#pragma once

#include <vector>
#include <memory>

#include "json.hpp"

class JSONReader
{
public:
    JSONReader();
    Json jsonRead(std::string json);
private:
};