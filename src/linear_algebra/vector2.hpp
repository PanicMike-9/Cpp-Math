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

//convert degrees to radians
inline float deg_to_rad(float degrees)
{
    return degrees * (PI / 180.0f);
}

// use template for variable type
class Vector2 
{
    public:
        float x;
        float y;

        // constructor
        constexpr Vector2(float x, float y) : x{x}, y{y} {}

        // find magnitude (sqaured)
        constexpr inline float length_squared() const
        {
            return (x * x + y * y);
        }

        // find magnitude (with square root)
        inline float length() const
        {
           return std::sqrt(length_squared());
        }

        // normalize magnitude aka unit vector
        inline Vector2 normalize() const
        {
            float mag = length();
            float inv = 1.0f / mag;

            return Vector2(x * inv, y * inv);
        }

        // dot product
        constexpr float dot(const Vector2& other) const
        {
            return (x * other.x) + (y * other.y);
        }

        // calculate distance
        inline float distance(const Vector2& other) const
        {
            return (*this - other).length();
        }

        // returns distance sqaured 
        constexpr float distance_squared(const Vector2& other) const
        {
            return (*this - other).length_squared();
        }

        // rotate
        inline Vector2 rotate(float angle) const
        {
            float radians = deg_to_rad(angle);

            float cos_a = std::cos(radians);
            float sin_a = std::sin(radians);
            
            return Vector2(x * cos_a - y * sin_a, x * sin_a + y * cos_a);
        }

        // find angle between two vectors
        inline float angle_between(const Vector2& other) const
        {
            float calculate_dot = this->dot(other);
            float mag_a = this->length();
            float mag_b = other.length();

            float cos_theta = calculate_dot / (mag_a * mag_b);
            float inv_cosine = acos(cos_theta);

            return rad_to_deg(inv_cosine);
        }

        // operator add
        constexpr Vector2 operator+(const Vector2& other) const
        {
            return Vector2{x + other.x, y + other.y};
        }

        constexpr Vector2 operator+(float scalar) const
        {
            return Vector2{x + scalar, y + scalar};
        }

        // operator mutliply 
        constexpr Vector2 operator*(const Vector2& other) const
        {
            return Vector2{x * other.x, y * other.y};
        }

        constexpr Vector2 operator*(float scalar) const
        {
            return Vector2{x * scalar, y * scalar};
        }

        // operator minus
        constexpr Vector2 operator-(const Vector2& other) const
        {
            return Vector2{x - other.x, y - other.y};
        }

        constexpr Vector2 operator-(float scalar) const
        {
            return Vector2{x - scalar, y - scalar};
        }

        // unary -()
        constexpr Vector2 operator-() const
        {
            return Vector2{-x, -y};
        }

        // operator divide
        constexpr Vector2 operator/(const Vector2& other) const
        {
            return Vector2{x / other.x, y / other.y};
        }

        constexpr Vector2 operator/(float scalar) const
        {
            return Vector2{x / scalar, y / scalar};
        }

        // comparison == operator
        constexpr bool operator==(const Vector2& other) const
        {
            return (x == other.x && y == other.y);
        }

        // assignment operator +=
        constexpr Vector2& operator+=(const Vector2& other)
        {
            x += other.x;
            y += other.y;
            return *this;
        }

        // assignment operator *=
        constexpr Vector2& operator*=(const Vector2& other)
        {
            x *= other.x;
            y *= other.y;
            return *this;
        }

        // assignment operator -=
        constexpr Vector2& operator-=(const Vector2& other)
        {
            x -= other.x;
            y -= other.y;
            return *this;
        }

        // assignment operator /=
        constexpr Vector2& operator/=(const Vector2& other)
        {
            x /= other.x;
            y /= other.y;
            return *this;
        }

        constexpr Vector2& operator/=(float scalar)
        {
            float inv = 1.0f / scalar;
            x *= inv;
            y *= inv;
            return *this;
        }

        // assignment operator !=
        constexpr bool operator!=(const Vector2& other) const
        {
            return !(*this == other);
        }
};

} // namespace geom

