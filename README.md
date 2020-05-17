# CLIDDIT
A CLI reddit client

## Why?

I've been browsing a wee too much reddit in this quarantine, so I've decided to actually turn this mishabit into something productive.
Now we've got CLIDDIT, Cliddit is a CLI Reddit client with no authentication (as of now at least)

This is an excercise to use as few libraries as possible, for now i'll only use libcurl and ncurses, curl is for some neat networking capabilities (https). It is a very real possibility that i'll add libcaca to "render" pictures.

# How?
Reddit has one cool feature where one can append ".json" to every url and the site gets returned in json format. I have used this feature to request the json output via libcurl, thereafter parse the json to something a bit better for C++ with a parser i wrote with Bison and Flex, and then finally get it into a redditPost class, then some NCurses classes show the posts on screen and lets you interact in some way or form with these



# May i see?
Yes of course!

I'll have to add some screenshots though, maybe in a later state of the program.


# Contributing
If you really want to you can contribute to the program, do this by opening an issue. we'll discuss the function and then do a pull request if you have an implementation of the feature, then i can merge it in.
