#include <memory> // std::unique_ptr

#include "controller/main_menu.hpp"
#include "window/ncurses_window.hpp"

constexpr int WINDOW_HEIGHT = 21; // 20 for board, 1 for score board
constexpr int WINDOW_WIDTH = 30;

using MenuPtr = std::unique_ptr<Menu>;

int main() {
    
    Size windowSize = {WINDOW_HEIGHT, WINDOW_WIDTH};

    MenuPtr menu  = std::make_unique<MainMenu>(new NCursesWindow(windowSize));
    menu->run();

    return 0;
}
