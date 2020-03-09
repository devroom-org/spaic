#pragma once

#include <string>

namespace spaic::css
{
class Stylesheet
{
public:
    Stylesheet();
    std::string compile();
};
} // namespace spaic::css
