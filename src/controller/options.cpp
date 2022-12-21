#include "options.hpp"

Options::Options(WindowPtr win) 
    : window_(win), exit_(false)
{}

void Options::processInput() {
    chtype input = window_->getInput();

    switch(input) {
        case 27: // Esc ASCII code
            exit_ = true;
            break;
        default:
            break;
    }
}

void Options::run() {
    while(!exit_) {
        window_->drawOptions();
        processInput();
    }
}