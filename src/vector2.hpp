#include <cmath>

// header guards
#ifndef VECTOR2_HPP
#define VECTOR2_HPP

class Vector2 
{
    public:
        float x;
        float y;

        // constructor
        Vector2(float x_c, float y_c) : x(x_c), y(y_c) {}

        // find magnitude
        float length() const
        {
           return std::sqrt(x * x + y * y);  
        }
};

#endif
