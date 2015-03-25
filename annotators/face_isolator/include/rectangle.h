#pragma once

#include <string>
#include <sstream>

class Rectangle
{
public:
    Rectangle(int x=-1, int y=-1, int width=-1, int height=-1) :
        x(x), y(y), width(width), height(height)
    {
    }
    
    int x, y, width, height;
    
    std::string toString() const
    {
        std::ostringstream retval;
        retval << x << "," << y << "+" << width << "x" << height;
        return retval.str();
    }
};