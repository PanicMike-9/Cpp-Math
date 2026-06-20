#pragma once

#include <cmath>

namespace geom
{

const float PI = 3.14159265358979323846f;

// convert radians to degrees
inline float rad_to_deg(float radians)
{
    return radians * (180.0f / PI);
}

// convert degrees to radians
inline float deg_to_rad(float degrees)
{
    return degrees * (PI / 180.0f);
}
 
class Vector3
{
    public:
        float x;
        float y;
        float z;

        // default constructor
        Vector3() : x{0.0f}, y{0.0f}, z{0.0f} {}

        // constructor
        Vector3(float x, float y, float z) : x{x}, y{y}, z{z} {}
};

} // namespace geom
