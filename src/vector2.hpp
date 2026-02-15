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

        // normalize magnitude aka unit vector
        Vector2 normalize() const
        {
            float mag = length();

            if(mag == 0) throw std::runtime_error("cannot divide with 0!\n");

            float new_x = x / mag;
            float new_y = y / mag;

            return Vector2(new_x, new_y);
        }

        // dot product
        float dot(const Vector2& other) const
        {
            return (x * other.x) + (y * other.y);
        }

        // actual distance in units (uses std::sqrt, slower and easier to read) 
        float distance(const Vector2& other) const
        {
            float delta_x = other.x - x;
            float delta_y = other.y - y;

            return std::sqrt(delta_x * delta_x + delta_y * delta_y);
        }

        // returns distance sqaured (no std::sqrt, faster, use for range and comparison)
        float distance_squared(const Vector2& other) const
        {
            float delta_x = other.x - x;
            float delta_y = other.y - y;

            return (delta_x * delta_x) + (delta_y * delta_y);
        }

        // operator add
        Vector2 operator+(const Vector2& other) const
        {
            return Vector2{x + other.x, y + other.y};
        }

        // operator multiply with a scalar value
        Vector2 operator*(float scalar) const
        {
            return Vector2{x * scalar, y * scalar};
        }

        // operator mutliply for vectors
        Vector2 operator*(const Vector2& other) const
        {
            return Vector2{x * other.x, y * other.y};
        }

        // operator minus
        Vector2 operator-(const Vector2& other) const
        {
            return Vector2{x - other.x, y - other.y};
        }

        // comparison == operator
        bool operator==(const Vector2& other) const
        {
            return (x == other.x && y == other.y);
        }

        // assignment operator +=
        Vector2& operator+=(const Vector2& other)
        {
            x += other.x;
            y += other.y;
            return *this;
        }

        // assignment operator *=
        Vector2& operator*=(const Vector2& other)
        {
            x *= other.x;
            y *= other.y;
            return *this;
        }

        // assignment operator -=
        Vector2& operator-=(const Vector2& other)
        {
            x -= other.x;
            y -= other.y;
            return *this;
        }
};

#endif
