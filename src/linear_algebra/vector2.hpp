#include <cmath>
#include <cassert> // for assert

// header guards
#ifndef VECTOR2_HPP
#define VECTOR2_HPP

constexpr const float PI = 3.14159265358979323846f;

namespace vmath
{

class Vector2 
{
    public:
        float x;
        float y;

        // constructor
        constexpr Vector2(float x, float y) : x{x}, y{y} {}

        // find magnitude (sqaured)
        constexpr float length_squared() const
        {
            return (x * x + y * y);
        }

        // find magnitude (with square root)
        constexpr float length() const
        {
           return std::sqrt(length_squared());  
        }

        // normalize magnitude aka unit vector
        constexpr Vector2 normalize() const
        {
            float mag = length();
            assert(mag > 0.0f && "Vector2: Division by zero!");

            float inv = 1.0f / mag;
            return Vector2(x * inv, y * inv);
        }

        // dot product
        constexpr float dot(const Vector2& other) const
        {
            return (x * other.x) + (y * other.y);
        }

        // calculate distance
        constexpr float distance(const Vector2& other) const
        {
            return (*this - other).length();
        }

        // returns distance sqaured 
        constexpr float distance_squared(const Vector2& other) const
        {
            return (*this - other).length_squared();
        }

        // rotate
        Vector2 rotate(float angle) const
        {
            float radians = angle * (PI / 180);
            
            float new_x = x * std::cos(radians) - y * std::sin(radians);
            float new_y = x * std::sin(radians) + y * std::cos(radians);

            return Vector2(new_x, new_y);
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
            assert(other.x != 0.0f && other.y != 0.0f && "Vector2: Division by zero!");
            return Vector2{x / other.x, y / other.y};
        }

        constexpr Vector2 operator/(float scalar) const
        {
            assert(scalar != 0.0f && "Vector2: Division by zero!");
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
            assert(other.x != 0.0f && other.y != 0.0f && "Vector2: Division by zero!");
            x /= other.x;
            y /= other.y;
            return *this;
        }

        constexpr Vector2& operator/=(float scalar)
        {
            assert(scalar != 0.0f && "Vector2: Division by zero!");
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

} // namespace vmath

#endif
