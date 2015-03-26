#pragma once

#include <string>

namespace af {
    namespace common {
        
        class Rectangle
        {
        public:
            Rectangle(int x=-1, int y=-1, int width=-1, int height=-1);
            bool isNull() { return x == -1 || y == -1 || width == -1 || height == -1; }
            int x, y, width, height;
            
            std::string toString() const;
            static Rectangle fromString(const std::string& str);
        };
        
        
    }
}
