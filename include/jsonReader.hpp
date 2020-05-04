#pragma once

#include <vector>
#include <memory>

#include "json.hpp"
#include "tokens.hpp"

class JSONReader
{
public:
    JSONReader();
    Json jsonRead(std::string json);
private:
    std::vector<std::shared_ptr<Token>>
};