#include "rectangle.h"

#include <string>
#include <sstream>

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
    return Rectangle();
}
