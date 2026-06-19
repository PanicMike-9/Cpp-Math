#pragma once

#include <cmath>

namespace geom
{
const float PI = 3.14159265358979323846f;

// convert radians to degrees
template<typename T>
inline T rad_to_deg(T radians)
{
    return radians * (180.0f / PI);
}

//convert degrees to radians
template<typename T>
inline constexpr T deg_to_rad(T degrees)
{
    return degrees * (PI / 180.0f);
}

// use template for variable type
template<typename T>
class Vector2 
{
    public:
        T x;
        T y;

        // constructor
        constexpr Vector2(T x, T y) : x{x}, y{y} {}

        // find magnitude (sqaured)
        constexpr T length_squared() const
        {
            return (x * x + y * y);
        }

        // find magnitude (with square root)
        inline float length() const
        {
           return std::sqrt
           (
                static_cast<float>(length_squared())
           );  
        }

        // normalize magnitude aka unit vector
        inline Vector2<float> normalize() const
        {
            T mag = length();
            float inv = 1.0f / static_cast<float>(mag);

            return Vector2
            (
                static_cast<float>(x) * inv, 
                static_cast<float>(y) * inv
            );
        }

        // dot product
        constexpr T dot(const Vector2& other) const
        {
            return (x * other.x) + (y * other.y);
        }

        // calculate distance
        inline T distance(const Vector2& other) const
        {
            return (*this - other).length();
        }

        // returns distance sqaured 
        constexpr T distance_squared(const Vector2& other) const
        {
            return (*this - other).length_squared();
        }

        // rotate
        inline Vector2 rotate(T angle) const
        {
            T radians = deg_to_rad(angle);

            T cos_a = std::cos(radians);
            T sin_a = std::sin(radians);
            
            return Vector2
            ( 
                x * cos_a - y * sin_a, 
                x * sin_a + y * cos_a
            );
        }

        // find angle between two vectors
        inline T angle_between(const Vector2& other) const
        {
            T calculate_dot = this->dot(other);
            T mag_a = this->length();
            T mag_b = other.length();

            T cos_theta = calculate_dot / (mag_a * mag_b);
            T inv_cosine = acos(cos_theta);

            return rad_to_deg(inv_cosine);
        }

        // operator add
        constexpr Vector2 operator+(const Vector2& other) const
        {
            return Vector2{x + other.x, 
                           y + other.y};
        }

        constexpr Vector2 operator+(T scalar) const
        {
            return Vector2{x + scalar, 
                           y + scalar};
        }

        // operator mutliply 
        constexpr Vector2 operator*(const Vector2& other) const
        {
            return Vector2{x * other.x, 
                           y * other.y};
        }

        constexpr Vector2 operator*(T scalar) const
        {
            return Vector2{x * scalar, 
                           y * scalar};
        }

        // operator minus
        constexpr Vector2 operator-(const Vector2& other) const
        {
            return Vector2{x - other.x, 
                           y - other.y};
        }

        constexpr Vector2 operator-(T scalar) const
        {
            return Vector2{x - scalar, 
                           y - scalar};
        }

        // unary -()
        constexpr Vector2 operator-() const
        {
            return Vector2{-x, -y};
        }

        // operator divide
        constexpr Vector2 operator/(const Vector2& other) const
        {
            return Vector2{x / other.x, 
                           y / other.y};
        }

        constexpr Vector2 operator/(T scalar) const
        {
            return Vector2{x / scalar, 
                           y / scalar};
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

        constexpr Vector2& operator/=(T scalar)
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

