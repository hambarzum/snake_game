#ifndef OPTIONS_HPP
#define OPTIONS_HPP

#include "menu.hpp"

class Options : public Menu {
public:
    Options(const WindowPtr);
    ~Options();

public:
    void handleInput();
    void run();
};

#endif //  OPTIONS_HPP
