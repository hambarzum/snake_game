#ifndef MAIN_MENU_HPP
#define MAIN_MENU_HPP

#include <string>
#include <vector>

#include "menu.hpp"

using Sections = std::vector<std::string>;

class MainMenu : public Menu {
public:
    MainMenu(const WindowPtr win);

public:
    void processInput();
    void run();

private:
    bool exit_;
};

#endif // MAIN_MENU_HPP