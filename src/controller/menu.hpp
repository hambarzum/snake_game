#ifndef MENU_HPP
#define MENU__HPP

#include "../window/window.hpp"

class Menu {
public:
    Menu(const WindowPtr win)
        : window_(win)
    {}
    virtual ~Menu() {
        delete window_;
    }

public:
    virtual void processInput() = 0;
    virtual void run() = 0;

protected:
    int choice_;
    MenuTabs tabs; 
    const WindowPtr window_;
    bool exit_;
};

#endif // MENU_HPP