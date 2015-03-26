#include "rectangle.h"

#include <string>
#include <sstream>
#include <regex>
#include <iostream>

const std::regex GEOMETRY_REGEX("(\\d+),(\\d+)\\+(\\d+)x(\\d+)");
const int X=1;
const int Y=2;
const int WIDTH=3;
const int HEIGHT=4;

af::common::Rectangle::Rectangle(int x, int y, int width, int height) :
x(x), y(y), width(width), height(height)
{
}

std::string af::common::Rectangle::toString() const
{
    std::ostringstream retval;
    retval << x << "," << y << "+" << width << "x" << height;
    return retval.str();
}

af::common::Rectangle af::common::Rectangle::fromString(const std::string& str)
{
    std::cout << str << std::endl;
    std::smatch match;
    if (!std::regex_search(str, match, GEOMETRY_REGEX)) {
        std::cout << "Unable to match" << std::endl;
        return Rectangle();
    }
    
    std::cout << match.size() << std::endl;
    
    return Rectangle(
                     std::stoi(match[X].str()),
                     std::stoi(match[Y].str()),
                     std::stoi(match[WIDTH].str()),
                     std::stoi(match[HEIGHT].str())
                     );
}
