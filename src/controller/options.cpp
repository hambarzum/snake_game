#include "options.hpp"

Options::Options(WindowPtr win) 
    : window_(win), exit_(false)
{
    content_ = {
        "Esc: Back To Last Window",
        "Enter: Select Option",
        "W/S: Move Up/Down",
        "A/D: Move Left/Right"
    };
}

void Options::processInput() {
    const char input = window_->getInput();

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
        window_->drawOptions(content_);
        processInput();
    }
}