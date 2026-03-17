#include <cmath>
#include <stdexcept>
#include <cassert> // for assert

// header guards
#ifndef VECTOR2_HPP
#define VECTOR2_HPP

class Vector2 
{
    public:
        float x;
        float y;

        // constructor
        constexpr Vector2(float x_c, float y_c) : x(x_c), y(y_c) {}

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

            if(mag == 0) throw std::runtime_error("Division by zero!\n");

            float new_x = x / mag;
            float new_y = y / mag;

            return Vector2(new_x, new_y);
        }

        // dot product
        constexpr float dot(const Vector2& other) const
        {
            return (x * other.x) + (y * other.y);
        }

        // actual distance in units (uses std::sqrt, slower and easier to read) 
        constexpr float distance(const Vector2& other) const
        {
            float delta_x = other.x - x;
            float delta_y = other.y - y;

            return std::sqrt(delta_x * delta_x + delta_y * delta_y);
        }

        // returns distance sqaured (no std::sqrt, faster, use for range and comparison)
        constexpr float distance_squared(const Vector2& other) const
        {
            float delta_x = other.x - x;
            float delta_y = other.y - y;

            return (delta_x * delta_x) + (delta_y * delta_y);
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

#endif
