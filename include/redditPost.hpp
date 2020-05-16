#pragma once

#include <vector>
#include <string>

class RedditPost;
typedef std::vector<RedditPost> Posts;

class RedditPost
{
public:
    RedditPost() {}
    std::string name;
    int score;
    std::string subreddit;
    std::string author;

};