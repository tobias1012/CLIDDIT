#pragma once

#include <string>

#include "json.hpp"
class Json;
extern JsonObject* finished;
extern void scan(const char*);
extern void yyparse();

class JsonParser
{
public:
    JsonParser();
    JsonObject parse(std::string str);

};