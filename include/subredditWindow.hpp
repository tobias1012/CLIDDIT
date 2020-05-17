#pragma once

#include "window.hpp"

class SubredditWindow : public Window
{
public:
    SubredditWindow();
    virtual void render();
private:
    WINDOW* top;
    int xdim, ydim;
};