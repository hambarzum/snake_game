#include "ncurses_window.hpp"

NCursesWindow::NCursesWindow(const Size size) 
    : size_(size)
{
    initscr();
    noecho();
    curs_set(0);
    raw(); // prevents from exiting out by ctrl+C

    pos_ = getCenterPosition(getMaxScreenSize());
    window_ = newwin(size.height, size.width, pos_.row, pos_.column);

    keypad(window_, true);
    
    wtimeout(window_, 200);
}

void NCursesWindow::drawGame() const {
    clean();
    drawWindowBorders();
    drawScoreBoard(0); // draws scoreboard with initial score of 0
    this->refresh(); // ncurses also has built-in refresh()
}

Size NCursesWindow::getMaxScreenSize() const {
    Size maxSize;
    getmaxyx(stdscr, maxSize.height, maxSize.width); 
    return maxSize;
}

Position NCursesWindow::getCenterPosition(Size maxSize) const {
    return Position {(maxSize.height/2) - (size_.height/2), (maxSize.width/2) - (size_.width/2)};
}

void NCursesWindow::drawMenu(const Sections& sections, int choice) {
    clean();
    drawWindowBorders();
    
    const Position menuPos = {size_.height / 2 - int(sections.size()) / 2, size_.width / 2 - 5}; // places menu in window's approximate center

    for (int i = 0; i < sections.size(); ++i) {
        if (choice == i) {
            mvwprintw(window_, menuPos.row + i, menuPos.column, "->%s", sections[i].c_str());
        }
        else {
            mvwprintw(window_, menuPos.row + i, menuPos.column, "  %s", sections[i].c_str());
        }
    }

    this->refresh();
}

void NCursesWindow::drawWindowBorders() const {
    box(window_, 0, 0);
}

NCursesWindow::~NCursesWindow() {
    endwin();
}

void NCursesWindow::drawCell(const Cell& object) const {
    mvwaddch(window_, object.getPosition().column, object.getPosition().row, object.getIcon());
}

void NCursesWindow::drawScoreBoard(int score) const {
    mvwprintw(window_, size_.height - 1, 0, "Score: ");
    wprintw(window_, "%d", score);
}

char NCursesWindow::getInput() const {
    return wgetch(window_);
}

char NCursesWindow::getCharacterAt(Position pos) const {
    return mvwinch(window_, pos.column, pos.row);
}

Size NCursesWindow::getSize() const{
    return size_;
}

void NCursesWindow::refresh() const {
    wrefresh(window_);
}

void NCursesWindow::clean() const {
    wclear(window_);
}