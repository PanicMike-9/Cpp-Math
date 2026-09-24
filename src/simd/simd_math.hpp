#pragma once

// #include <xmmintrin.h> // maybe not required
#include <immintrin.h> // works for GCC, Clang and MSVC

namespace simd
{

// ---- SSE 128-bit Functions ----
    
inline void multiply_floats_128(const float a[4], const float b[4], float result[4])
{
    __m128 arr_a  = _mm_loadu_ps(a);
    __m128 arr_b = _mm_loadu_ps(b);

    __m128 calculate = _mm_mul_ps(arr_a, arr_b);
    _mm_storeu_ps(result, calculate);
}

inline void add_floats_128(const float a[4], const float b[4], float result[4])
{
    __m128 arr_a {_mm_loadu_ps(a)};
    __m128 arr_b {_mm_loadu_ps(b)};

    __m128 calculate {_mm_add_ps(arr_a, arr_b)};
    _mm_storeu_ps(result, calculate);
}

inline void array_multiply_scalar_128(float* a, const std::size_t n, const float scalar) noexcept
{
    const __m128 arr_scalar = _mm_set1_ps(scalar);
    std::size_t i {0};
    for (; i + 3 < n; i += 4)
    {
        __m128 arr_a = _mm_loadu_ps(&a[i]);
        __m128 calculate = _mm_mul_ps(arr_a, arr_scalar);
        _mm_storeu_ps(&a[i], calculate);
    }

    // process remainder values
    for (; i < n; ++i)
    {
        a[i] *= scalar;
    }
}

inline void array_add_scalar_128(float* a, const std::size_t n, const float scalar) noexcept
{
    const __m128 arr_scalar = _mm_set1_ps(scalar);
    std::size_t i {0};
    for (; i + 3 < n; i += 4)
    {
        __m128 arr_a = _mm_loadu_ps(&a[i]);
        __m128 calculate = _mm_add_ps(arr_a, arr_scalar);
        _mm_storeu_ps(&a[i], calculate);
    }

    // process remainder values
    for (; i < n; ++i)
    {
        a[i] += scalar;
    }
}

// ---- AVX2 256-bit Functions ----

inline void multiply_floats_256(const float a[8], const float b[8], float result[8])
{
    __m256 arr_a = _mm256_loadu_ps(a);
    __m256 arr_b = _mm256_loadu_ps(b);

    __m256 calculate = _mm256_mul_ps(arr_a, arr_b);
    _mm256_storeu_ps(result, calculate);
}

inline void add_floats_256(const float a[8], const float b[8], float result[8])
{
    __m256 arr_a {_mm256_loadu_ps(a)};
    __m256 arr_b {_mm256_loadu_ps(b)};

    __m256 calculate {_mm256_add_ps(arr_a, arr_b)};
    _mm256_storeu_ps(result, calculate);
}

inline void array_multiply_scalar_256(float* a, const std::size_t n, const float scalar) noexcept
{
    const __m256 arr_scalar = _mm256_set1_ps(scalar);
    std::size_t i {0};
    for (; i + 7 < n; i += 8)
    {
        __m256 arr_a = _mm256_loadu_ps(&a[i]);

        __m256 calculate = _mm256_mul_ps(arr_a, arr_scalar);
        _mm256_storeu_ps(&a[i], calculate);
    }

    // process remainder values
    for (; i < n; ++i)
    {
        a[i] *= scalar;
    }
}

inline void array_add_scalar_256(float* a, const std::size_t n, const float scalar) noexcept
{
    const __m256 arr_scalar = _mm256_set1_ps(scalar);
    std::size_t i {0};
    for (; i + 7 < n; i += 8)
    {
        __m256 arr_a = _mm256_loadu_ps(&a[i]);

        __m256 calculate = _mm256_add_ps(arr_a, arr_scalar);
        _mm256_storeu_ps(&a[i], calculate);
    }

    // process remainder values
    for (; i < n; ++i)
    {
        a[i] += scalar;
    }
}

inline void multiply_add_floats_256(const float a[8], const float b[8], const float result[8], std::size_t n) noexcept
{
}

}// namespace simd

