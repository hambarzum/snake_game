#include "main_menu.hpp"
#include "play.hpp"

MainMenu::MainMenu(const WindowPtr win) 
    : Menu(win)
{
    choice_ = 0;
    sections_ = {"Play", "Options", "Records", "Quit"};
    exit_ = false;
}

void MainMenu::processInput() {
    chtype input = window_->getInput();

    switch(input) {
        case KEY_UP: // implement
        case 'w':
            if(choice_ > 0) {
                choice_--;
            }
            else {
                choice_ = sections_.size() - 1;
            }
            break;
        case KEY_DOWN: // implement
        case 's':
            if(choice_ < sections_.size() - 1) {
                choice_++;
            }
            else {
                choice_ = 0;
            }
            break;
        case 10: // Enter ASCII code
            if (sections_[choice_] == "Play") {
                window_->drawGame();
                Game game(window_);
                game.run();
            }

            else if(sections_[choice_] == "Quit") {
                exit_ = true;
                window_->clean();
                window_->refresh();
            }

        default:
            break;
    }
}

void MainMenu::run() {
    while(!exit_) {
        window_->drawMenu(sections_, choice_);
        processInput();
    }
}