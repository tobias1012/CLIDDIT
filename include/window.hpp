#pragma once


#include <string>
#include <ncurses.h>

class Window
{
public:
    Window()
    {
        getmaxyx(stdscr,xdim,ydim);
        top = newwin(3,ydim,0,0);
        bottom = newwin(1, ydim, xdim-1, 0);
    }
    virtual void render() = 0;
    void overlay()
    {
        init_pair(1,COLOR_WHITE,COLOR_BLUE);
        //Top Setup
        int hashtag = '#';
        box(top, (int)hashtag, (int)hashtag);
        std::string title = "CLIDDIT";
        wbkgd(top, COLOR_PAIR(1));
        mvwprintw(top,1, (ydim/2) - (title.size()/2), title.c_str());
        wrefresh(top);

        //Bottom setup
        wbkgd(bottom, COLOR_PAIR(1));
        wrefresh(bottom);

    }
protected:
    WINDOW* top;
    WINDOW* bottom;
    int xdim, ydim;
};

