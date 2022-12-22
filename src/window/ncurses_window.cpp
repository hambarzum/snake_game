#include "ncurses_window.hpp"

NCursesWindow::NCursesWindow(const Size& size) 
    : size_(size)
{
    initscr();
    noecho();
    curs_set(0);
    raw(); // prevents from exiting out by ctrl+C/ctrl+Z

    pos_ = getCenterPosition(getMaxScreenSize());
    window_ = newwin(size.height, size.width, pos_.row, pos_.column);

    wtimeout(window_, 150);
}

NCursesWindow::~NCursesWindow() {
    endwin();
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

Position NCursesWindow::getCenterPosition(const Size& maxSize) const {
    return Position {(maxSize.height/2) - (size_.height/2), (maxSize.width/2) - (size_.width/2)};
}

void NCursesWindow::drawMenu(const MenuTabs& tabs, int choice) const {
    clean();
    drawWindowBorders();

    drawMenuHeader();
    drawMenuTabs(tabs, choice);

    this->refresh();
}

void NCursesWindow::drawMenuHeader() const {
    mvwprintw(window_, size_.height/2 - 6, size_.width / 2 - 2, "MENU");
}

void NCursesWindow::drawMenuTabs(const MenuTabs& tabs, int choice) const {
    const Position menuPos = {size_.height / 2 - int(tabs.size()) / 2, size_.width / 2 - 3}; // places menu in window's approximate center

    for (int i = 0; i < tabs.size(); ++i) {
        if (choice == i) {
            wattron(window_, A_REVERSE); // highlights choice
        }
        mvwprintw(window_, menuPos.row + i, menuPos.column, "%s", tabs[i].c_str());
        wattroff(window_, A_REVERSE);
    }
}

void NCursesWindow::drawWindowBorders() const {
    box(window_, 0, 0);
}

void NCursesWindow::drawCell(const Cell& object) const {
    mvwaddch(window_, object.getPosition().column, object.getPosition().row, object.getIcon());
}

void NCursesWindow::drawScoreBoard(int score) const {
    mvwprintw(window_, size_.height - 1, 0, "Score: ");
    wprintw(window_, "%d", score);
}

void NCursesWindow::drawOptions() const {
    clean();
    drawWindowBorders();
    
    drawOptionsHeader();
    drawOptionsContent();

}

void NCursesWindow::drawOptionsHeader() const {
    mvwprintw(window_, size_.height / 2 - 6, size_.width / 2 - 3, "OPTIONS");
}

void NCursesWindow::drawOptionsContent() const {
    mvwprintw(window_, size_.height / 2 - 2, 3, "Esc: Back To Last Window");
    mvwprintw(window_, size_.height / 2 - 1, 3, "Enter: Select Option");
    mvwprintw(window_, size_.height / 2, 3, "W/S: Move Up/Down");
    mvwprintw(window_, size_.height / 2 + 1, 3, "A/D: Move Left/Right");
}

char NCursesWindow::getInput() const {
    return wgetch(window_);
}

char NCursesWindow::getCharacterAt(const Position& pos) const {
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