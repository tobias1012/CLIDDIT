#include "program.hpp"

Program::Program()
{
    initscr();
    cbreak();
    noecho();
    start_color();
    clear();
}

Program::~Program()
{
    endwin();
}