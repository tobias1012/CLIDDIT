#include "json.hpp"


JsonObject::JsonObject()
{
    //TODO: Implement
}

JsonObject::JsonObject(PairList* list)
{
    values = *list;
}


std::string JsonObject::getValue()
{
    return this->getValue();
}

JsonValue* JsonObject::operator[](std::string str)
{
    //We could massively improve perfomance by using findif instead
    size_t i = 0;
    for(i = 0; i < values.size(); i++)
    {
        if(str == values[i]->name)
        {
            break; //we found our value and now break out of loop
        }
    }

    return values[i]->value;
    
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
    value.pop_back();
    value.erase(0, 1);
    return value;
}

JsonArray::JsonArray(ValueList* vals)
{
    values = *vals;
}

std::string JsonArray::getValue()
{
    return "Can't get the value from an array"; //TODO: IMPLEMENT
}

void JsonArray::push_back(JsonValue* val)
{
    values.push_back(val);
}

JsonValue* JsonArray::operator[](size_t index)
{
    return values[index];
}