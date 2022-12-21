#ifndef NCURSES_WINDOW_HPP

#include <ncurses.h>

#include "window.hpp"

class NCursesWindow : public Window{
public:
    NCursesWindow(const Size);
    ~NCursesWindow();

public:
    void drawGame() const;
    void drawMenu(const Sections&, int choice);
    void drawCell(const Cell&) const;

public:
    char getInput() const;
    char getCharacterAt(Position) const;
    Size getSize() const;
    
public:    
    void refresh() const;
    void clean() const;
    
private:
    Size getMaxScreenSize() const;
    Position getCenterPosition(Size) const;
    void drawWindowBorders() const;
    void drawScoreBoard(int score) const;

private:
    WINDOW* window_;
    Size size_;
    Position pos_;
};


#define NCURSES_WINDOW_HPP
#endif // NCURSES_WINDOW_HPP