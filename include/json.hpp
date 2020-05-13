#pragma once

#include <string>
#include <vector>


class JsonPair;
class JsonString;

typedef std::vector<JsonPair*> ValueList;


enum Type
{
    String,
    Number,
    Bool,
    Array
};

class Json
{
    virtual std::string getValue() = 0;
};

class JsonValue : public Json
{
public:
    JsonValue() {}
    virtual std::string getValue() = 0;
};



class JsonObject : public JsonValue
{
public:
    JsonObject();
    JsonObject(ValueList* list);
    std::vector<JsonPair*> values;
    virtual std::string getValue();
};

class JsonPair : public Json
{
public:
    JsonPair(JsonString* str, JsonValue* val);
    std::string name;
    JsonValue* value;
    virtual std::string getValue();
};

class JsonNumber : public JsonValue
{
public:
    double val;
    virtual std::string getValue();
};

class JsonBool : public JsonValue
{
public:
    JsonBool(int val)
        : val(val) {}
    virtual std::string getValue();
    bool val;
};

class JsonString : public JsonValue
{
public:
    JsonString(std::string val)
        : value(val) {}
    std::string value;
    virtual std::string getValue();
};

class JsonArray : public JsonValue
{
public:
    JsonValue* operator[](size_t index);
    void push_back(JsonValue* val);
    virtual std::string getValue();

private:
    std::vector<JsonValue*> values;

};

