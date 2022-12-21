#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>
#include <vector>
#include <ncurses.h>

#include "../game_objects/cell.hpp"

struct Size {
    int height;
    int width;
};

using Sections = std::vector<std::string>;

class Window {
public:
    Window() {}
    virtual ~Window() {}

public:
    virtual void drawGame() const = 0;
    virtual void drawMenu(const Sections&, int choice) = 0;
    virtual void drawCell(const Cell&) const = 0;
    virtual void drawScoreBoard(int score) const = 0;

public:
    virtual char getInput() const = 0;
    virtual char getCharacterAt(Position) const = 0;
    virtual Size getSize() const = 0;

public:
    virtual void refresh() const = 0;
    virtual void clean() const = 0;

};

using WindowPtr = Window*;

#endif // WINDOW_HPP

