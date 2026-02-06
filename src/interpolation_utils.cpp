// header guards
#ifndef INTERPOLATION_UTILS_HPP
#define INTERPOLATION_UTILS_HPP

// includes
#include <stdexcept>
#include <cmath>


// linear interpolaion curve fitting
float calculate_lerp(float start_value, float end_value, float time)
{
    if(time < 0.0f || time > 1.0f) 
        throw std::runtime_error("Time must be between 0.0 and 1.0");
    
    return (1.0f - time) * start_value + time * end_value;
}

// inverse linear interpolation/min-max normalization
float calculate_inverse_lerp(float start_value, float end_value, float value)
{
    float range = end_value - start_value;
    if(range == 0.0f)
        throw std::runtime_error("cannot divide with 0");

    return (value - start_value) / range;
}

// clamp between two values
double calculate_clamp(double value, double min_val, double max_val)
{
    if(min_val > max_val) 
        throw std::runtime_error("minimum value cannot be larger than maximum value!");

    if(value < min_val) return min_val;
    if(value > max_val) return max_val;

    return value;
}

// remap
float calculate_remap(float value, float old_min, float old_max, 
    float new_min, float new_max)
{
    float t = calculate_inverse_lerp(old_min, old_max, value);

    float t_clamped = calculate_clamp(t, 0.0, 1.0);

    return calculate_lerp(new_min, new_max, t_clamped);
}

#endif // INTERPOLATION_UTILS_HPP
