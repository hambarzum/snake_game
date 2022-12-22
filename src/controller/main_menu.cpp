#include "main_menu.hpp"
#include "play.hpp"
#include "options.hpp"

MainMenu::MainMenu(const WindowPtr win) 
    : Menu(win)
{
    choice_ = 0;
    tabs = {
        "Play", 
        "Options", 
        "Records", 
        "Quit"
    };
    exit_ = false;
}

void MainMenu::processInput() {
    const char input = window_->getInput();

    switch(input) {
        case 'w':
            if(choice_ > 0) {
                choice_--;
            }
            else {
                choice_ = tabs.size() - 1;
            }
            break;
        case 's':
            if(choice_ < tabs.size() - 1) {
                choice_++;
            }
            else {
                choice_ = 0;
            }
            break;
        case 10: // Enter ASCII code
            if (tabs[choice_] == "Play") {
                window_->drawGame();
                Game game(window_);
                game.run();
            }

            if(tabs[choice_] == "Options") {
                Options options(window_);
                options.run();
            }

            if(tabs[choice_] == "Records") {
            
            }


            else if(tabs[choice_] == "Quit") {
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
        window_->drawMenu(tabs, choice_);
        processInput();
    }
}