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
    const WindowPtr window_;
    OptionsContent content_;
    bool exit_;
};

#endif //  OPTIONS_HPP
