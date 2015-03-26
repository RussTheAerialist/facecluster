#include "rectangle.h"

#include <string>
#include <sstream>

Rectangle::Rectangle(int x, int y, int width, int height) :
    x(x), y(y), width(width), height(height)
{
}
    
std::string Rectangle::toString() const
{
    std::ostringstream retval;
    retval << x << "," << y << "+" << width << "x" << height;
    return retval.str();
}
    
Rectangle Rectangle::fromString(const std::string& str)
{
    return Rectangle();
}
