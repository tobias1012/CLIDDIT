#include "program.hpp"

Program::Program()
{
    initscr();
    cbreak();
    keypad(stdscr, true);
    noecho();
    start_color();
    clear();
}

Program::~Program()
{
    endwin();
}