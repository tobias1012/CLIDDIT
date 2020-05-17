#include "redditHandler.hpp"

RedditHandler::RedditHandler()
{
    req.setHost("https://reddit.com");

    subreddit = "";
}

Posts RedditHandler::changeSubreddit(std::string subreddit)
{
    Posts ret;
    //Do some cleaning of the string none will exist as of now
    this->subreddit = subreddit;

    return ret;
}

Posts RedditHandler::getPosts()
{
    Posts ret;

    std::string data = req.getResponse(subreddit + ".json?limit=100");

    JsonObject obj = parser.parse(data);

    //Cast to the datatypes. We could implement the type
    //and make our parser more general pourpose
    JsonObject& jData = dynamic_cast<JsonObject&>(*obj["data"]);
    JsonArray& posts = dynamic_cast<JsonArray&>(*jData["children"]);

    for(size_t i = 0; i < posts.values.size(); i++)
    {
        JsonObject& arrPoint = dynamic_cast<JsonObject&>(*posts[i]);
        JsonObject& t = dynamic_cast<JsonObject&>(*arrPoint["data"]);

        //Construct our post in a struct
        RedditPost tempPost;
        tempPost.name = t["title"]->getValue();
        tempPost.author = t["author"]->getValue();
        tempPost.score = stoi(t["ups"]->getValue());
        tempPost.subreddit = t["subreddit"]->getValue();
        
        
        //add the post to the list as the last thing
        ret.push_back(tempPost); 
    }

    return ret;

}