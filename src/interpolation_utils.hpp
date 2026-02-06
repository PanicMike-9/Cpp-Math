// header guards
#ifndef INTERPOLATION_UTILS_HPP
#define INTERPOLATION_UTILS_HPP

// includes
#include <stdexcept>
#include <algorithm>
#include <cmath> // for future updates

namespace vmath
{

// linear interpolaion curve fitting
inline float lerp(float start_value, float end_value, float time)
{
    if(time < 0.0f || time > 1.0f) 
        throw std::runtime_error("Time must be between 0.0 and 1.0");
    
    return (1.0f - time) * start_value + time * end_value;
}

// inverse linear interpolation/min-max normalization
inline float inverse_lerp(float value, float start_value, float end_value)
{
    float range = end_value - start_value;
    if(range == 0.0f)
        throw std::runtime_error("cannot divide with 0");

    return (value - start_value) / range;
}

// clamp between two values
inline float clamp(float value, float min_val, float max_val)
{
    if(min_val > max_val) 
        throw std::runtime_error("minimum value cannot be larger than maximum value!");

    return std::max(min_val, std::min(value, max_val));
}

// remap
inline float remap(float value, float old_min, float old_max, 
    float new_min, float new_max)
{
    float t = inverse_lerp(old_min, old_max, value);

    float t_clamped = clamp(t, 0.0f, 1.0f);

    return lerp(new_min, new_max, t_clamped);
}

} // namespace vmath

#endif // INTERPOLATION_UTILS_HPP
