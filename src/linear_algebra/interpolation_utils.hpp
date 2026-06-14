// header guards
#ifndef INTERPOLATION_UTILS_HPP
#define INTERPOLATION_UTILS_HPP

// essential libs
#include <algorithm>
#include <cmath> // for future updates
#include <cassert> // for future updates

namespace vmath
{

// linear interpolaion curve fitting
inline float lerp(float start_value, float end_value, float time)
{
    assert(time >= 0.0f && time <= 1.0f);
    return (1.0f - time) * start_value + time * end_value;
}

// inverse linear interpolation/min-max normalization
inline float inverse_lerp(float start_value, float end_value, float value)
{
    float range = end_value - start_value;
    assert(range != 0.0f);

    return (value - start_value) / range;
}

// clamp between two values
inline float clamp(float value, float min_val, float max_val)
{
    assert(min_val <= max_val);
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
