#ifndef MAIN_MENU_HPP
#define MAIN_MENU_HPP

#include <string>
#include <vector>

#include "options.hpp"

class MainMenu : public Menu {
public:
    MainMenu(const WindowPtr win);

public:
    void processInput();
    void run();

};

#endif // MAIN_MENU_HPP