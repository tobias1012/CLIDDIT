#pragma once

#include <string>

#include "requester.hpp"
#include "jsonParser.hpp"
#include "redditPost.hpp"

class RedditHandler
{
public:
    RedditHandler();
    Posts changeSubreddit(std::string subreddit);
    Posts getPosts();
private:
    std::string subreddit;

    Requester req;
    JsonParser parser;
};