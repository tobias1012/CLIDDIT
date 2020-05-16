#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

class Json;
class JsonPair;
class JsonString;
class JsonValue;

typedef std::vector<JsonPair*> PairList;
typedef std::vector<JsonValue*> ValueList;


enum Type
{
    String,
    Number,
    Bool,
    Array
};

class Json
{
public:
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
    JsonObject(PairList* list);
    PairList values;
    JsonValue* operator[](std::string str);
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
    int val;
};

class JsonString : public JsonValue
{
public:
    JsonString(std::string* val)
        : value(*val) {}
    JsonString() = default;
    std::string value;
    virtual std::string getValue();
};

class JsonArray : public JsonValue
{
public:
    JsonArray(ValueList* vals);
    JsonArray() = default;
    JsonValue* operator[](size_t index);
    void push_back(JsonValue* val);
    ValueList values;
    virtual std::string getValue();

};

