#include "requester.hpp"

Requester::Requester()
{
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(!curl)
    {
        throw "Could not init Curl!";
    }

    //Dont bother with ipv6 resolve
    curl_easy_setopt(curl, CURLOPT_IPRESOLVE, CURL_IPRESOLVE_V4);

    //follow redirect
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, true);

    //set writecallback function
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, Requester::writeCallback);

}

Requester::~Requester()
{
    curl_easy_cleanup(curl);
    curl_global_cleanup();
}



void Requester::setHost(std::string host)
{
    if(host.back() == '/') //remove '/' as it should be in the get response function instead
    {
        host.pop_back();
    }
    this->host = host;
}

std::string Requester::getResponse(std::string subsite)
{

    if(!(subsite[0] == '/')) //check if '/' is in front
    {
        subsite = '/' + subsite; //add '/' if not present
    }

    std::unique_ptr<std::string> responseBody(new std::string()); //Our response after

    std::string fullpath = host + subsite;
    curl_easy_setopt(curl, CURLOPT_URL, fullpath.c_str());
    
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, responseBody.get());

    //make the request;
    curl_easy_perform(curl);


    return *responseBody.get();
}

size_t Requester::writeCallback(const char* data, size_t size, size_t nmemb, std::string* out)
{
    const size_t totalsize = size * nmemb;
    out->append(data, totalsize);

    return totalsize;
}