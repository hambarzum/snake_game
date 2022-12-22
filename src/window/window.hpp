#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>
#include <vector>

#include "../game_objects/cell.hpp"

struct Size {
    int height;
    int width;
};

using MenuTabs = std::vector<std::string>;
using OptionsContent = std::vector<std::string>;

class Window {
public:
    Window() {}
    virtual ~Window() {}

public:
    virtual void drawGame() const = 0;
    virtual void drawMenu(const MenuTabs&, int choice) const = 0;
    virtual void drawCell(const Cell&) const = 0;
    virtual void drawScoreBoard(int score) const = 0;
    virtual void drawOptions(const OptionsContent&) const = 0;

public:
    virtual char getInput() const = 0;
    virtual char getCharacterAt(const Position&) const = 0;
    virtual Size getSize() const = 0;

public:
    virtual void refresh() const = 0;
    virtual void clean() const = 0;

};

using WindowPtr = Window*;

#endif // WINDOW_HPP

