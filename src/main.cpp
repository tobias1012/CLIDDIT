#include <iostream>
#include <chrono>

#include "program.hpp"
#include "requester.hpp"
#include "jsonParser.hpp"
#include "redditHandler.hpp"
#include "windowHandler.hpp"

int main()
{
    /*
    Requester req;

    req.setHost("https://www.reddit.com/");
    std::string t = req.getResponse("/.json");

    JsonParser parser;

    auto before = std::chrono::high_resolution_clock::now();
    parser.parse(t);
    auto now = std::chrono::high_resolution_clock::now();
    
    auto dT = std::chrono::duration_cast<std::chrono::microseconds>(now - before).count();

    std::cout <<"Length of string:" << t.length() << std::endl << 
    "Time to Parse: " << dT << std::endl;
    */

    RedditHandler handler;

    std::string name = handler.getPosts()[0].name;

    std::cout << name << std::endl;

    WindowHandler wHandler;
    wHandler.start();
    

    return 0;
}