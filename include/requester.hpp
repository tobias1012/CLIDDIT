#pragma once

#include <string>
#include <memory>

#include <curl/curl.h>

/* Requester class is for requesting websites, this can be done
 * with a few methods, but mainly strives to do so with GET
 * Abstraction layer upon Curl
 * 
 */
class Requester
{
public:
    Requester();
    ~Requester();
    void setHost(std::string host);
    std::string getResponse(std::string subsite);

    static size_t writeCallback(const char* data, size_t size, size_t nmemb, std::string* userp);
private:
    CURL* curl;
    std::string host;
};