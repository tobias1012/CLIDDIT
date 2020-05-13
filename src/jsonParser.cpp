#include "jsonParser.hpp"

JsonParser::JsonParser()
{

}

JsonObject JsonParser::parse(std::string str)
{
    JsonObject ret;

    scan(str.c_str());
    yyparse();

    if(finished != nullptr)
    {
        ret = *finished;
    }
    else
    {
        throw "Parsing error!";
    }
    return ret;
}