#ifndef NCURSES_WINDOW_HPP

#include <ncurses.h>

#include "window.hpp"

class NCursesWindow : public Window{
public:
    NCursesWindow(const Size&);
    ~NCursesWindow();

public:
    void drawGame() const;
    void drawMenu(const MenuTabs&, int choice) const;
    void drawCell(const Cell&) const;
    void drawScoreBoard(int score) const;
    void drawOptions() const;

public:
    char getInput() const;
    char getCharacterAt(const Position&) const;
    Size getSize() const;
    
public:    
    void refresh() const;
    void clean() const;
    
private:
    Size getMaxScreenSize() const;
    Position getCenterPosition(const Size&) const;
    void drawWindowBorders() const;
    void drawMenuHeader() const;
    void drawMenuTabs(const MenuTabs&, int choice) const;
    void drawOptionsHeader() const;
    void drawOptionsContent() const;

private:
    WINDOW* window_;
    Size size_;
    Position pos_;
};


#define NCURSES_WINDOW_HPP
#endif // NCURSES_WINDOW_HPP