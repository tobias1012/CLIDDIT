#pragma once

#include <string>

class Json
{

};

class JsonValue : public Json
{

};

class JsonObject : public JsonValue
{

};

class JsonPair : public JsonValue
{
public:
    std::string name;
    JsonValue* value;
};