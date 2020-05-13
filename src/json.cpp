#include "json.hpp"


JsonObject::JsonObject()
{
    //TODO: Implement
}

JsonObject::JsonObject(ValueList* list)
{
    values = *list;
}


std::string JsonObject::getValue()
{
    return this->getValue();
}

JsonPair::JsonPair(JsonString* str, JsonValue* val)
{
    name = str->getValue();
    value = val;
}

std::string JsonPair::getValue()
{
    std::string ret;
    ret = '"' + this->name + "\" : " + this->value->getValue();
    return ret;
}

std::string JsonNumber::getValue()
{
    std::string ret = std::to_string(this->val);
    return ret;
}

std::string JsonBool::getValue()
{
    return "False";
}

std::string JsonString::getValue()
{
    return value;
}

std::string JsonArray::getValue()
{
    return "Not implemented"; //TODO: IMPLEMENT
}