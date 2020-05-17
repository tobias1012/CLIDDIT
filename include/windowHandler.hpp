#pragma once

#include <ncurses.h>

#include "window.hpp"
#include "subredditWindow.hpp"

class WindowHandler
{
public:
    WindowHandler();
    ~WindowHandler();
    void start();
    Window* win;
};