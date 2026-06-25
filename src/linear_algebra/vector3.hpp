#pragma once

#include <cmath>
#include <cassert>

namespace geom
{

constexpr float PI = 3.14159265358979323846f;

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

// 1e-6f = 0.000001
constexpr float EPSILON = 1e-6f;

// handling comparison in presence of floating-point error
inline bool is_zero(float a)
{
    return std::abs(a) < EPSILON;
}

// values small enough to be equal
inline bool nearly_equal(float a, float b)
{
    return std::abs(a - b) < EPSILON;
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

        constexpr Vector3 operator/(float scalar) const
        {
            assert(std::abs(scalar) > 0.0f);
            return Vector3{x / scalar, y / scalar, z / scalar};
        }

        constexpr Vector3 operator*(float scalar) const
        {
            return Vector3{x * scalar, y * scalar, z * scalar};
        }

        constexpr Vector3 operator*(const Vector3 &other) const
        {
            return Vector3{x * other.x, y * other.y, z * other.z};
        }

        constexpr Vector3 operator+(float scalar) const
        {
            return Vector3{x + scalar, y + scalar, z + scalar};
        }

        constexpr Vector3 operator+(const Vector3 &other) const
        {
            return Vector3{ x + other.x, y + other.y, z + other.z};
        }

        constexpr Vector3 operator-(float scalar) const
        {
            return Vector3{x - scalar, y - scalar, z - scalar};
        }

        constexpr Vector3 operator-(const Vector3 &other) const
        {
            return Vector3{x - other.x, y - other.y, z - other.z};
        }
};

// ** free functions ** //

// basic function call for vector to vector division, no operator overload
inline Vector3 component_div(const Vector3 &a, const Vector3 &b) 
{
    return 
    {
        a.x / b.x,
        a.y / b.y,
        a.z / b.z
    };
}

inline float dot(const Vector3 &a, const Vector3 &b) 
{
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}

inline float distance_squared(const Vector3 &a, const Vector3 &b) 
{
    Vector3 displacement = a - b;
    return displacement.length_squared();
}

inline float distance(const Vector3 &a, const Vector3 &b) 
{
    Vector3 displacement = a - b;
    return displacement.length();
}

inline Vector3 cross(const Vector3 &a, const Vector3 &b)  
{
    return
    {
        (a.y * b.z - a.z * b.y),
        (a.z * b.x - a.x * b.z),
        (a.x * b.y - a.y * b.x)
    };
}

// scale vectors
inline Vector3 scale(const Vector3 &a, const Vector3 &b) 
{
    return Vector3
        (
         a.x * b.x, 
         a.y * b.y, 
         a.z * b.z
        );
}

} // namespace geom
