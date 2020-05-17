#include "windowHandler.hpp"

WindowHandler::WindowHandler()
{
    initscr();
    start_color();
    win = new SubredditWindow();
    
}

WindowHandler::~WindowHandler()
{
    endwin();
}

void WindowHandler::start()
{
    while (true)
    {
        int ch;
        win->render();
        noecho();
        ch = getch();
        if(ch == 27)
        {
            break;
        }

    }
    
}