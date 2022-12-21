#ifndef OPTIONS_HPP
#define OPTIONS_HPP

#include "menu.hpp"


class Options {
public:
    Options(const WindowPtr);
    
public:
    void processInput();
    void run();

private:
    WindowPtr window_;
    bool exit_;
};

#endif //  OPTIONS_HPP
