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
        constexpr Vector3() : x{0.0f}, y{0.0f}, z{0.0f} {}

        // constructor
        constexpr Vector3(float x, float y, float z) : x{x}, y{y}, z{z} {}

        // find magnitude squared
        inline float length_squared() const
        {
            return (x * x + y * y + z * z);
        }

        // find magnitude 
        inline float length() const
        {
            return std::sqrt(length_squared());
        }

        // find unit vector/normalize vector
        inline Vector3 normalize() const
        {
            float mag = length();
            float inv = 1.0f / mag;

            return Vector3(x * inv, y * inv, z * inv);
        }

        // ** operator overloads ** //

        constexpr Vector3 operator-(float scalar) const
        {
            return Vector3{x - scalar, y - scalar, z - scalar};
        }

        constexpr Vector3 operator-(const Vector3 &other) const
        {
            return Vector3{x - other.x, y - other.y, z - other.z};
        }
};

// find squared distance of two vectors
inline float distance_squared(const Vector3 &a, const Vector3 &b) 
{
    return (a - b).length_squared();
}

// find distance of two vectors
inline float distance(const Vector3 &a, const Vector3 &b) 
{
    return (a - b).length();
}

// find dot product
inline float dot(const Vector3 &a, const Vector3 &b) 
{
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}

} // namespace geom
