#pragma once

#include <string>

// A Container for a reddit post, this is used to enumerate all posts and show them in ncurses
class Post
{
public:
    std::string title;
    std::string url;
    int score;
};