#include <cmath>
#include <stdexcept>

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

        // normalize magnitude
        Vector2 normalize() const
        {
            float mag = length();

                if(mag == 0) throw std::runtime_error("cannot divide with 0!\n");

                float new_x = x / mag;
                float new_y = y / mag;

                return Vector2(new_x, new_y);
        }
};

#endif
