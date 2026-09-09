#pragma once

#include <print>
#include <xmmintrin.h>
#include <immintrin.h> // works for GCC, Clang and MSVC

namespace simd
{

inline void sse_multiply_floats_128(float a[4], float b[4], float result[4])
{
    __m128 arr_a = _mm_loadu_ps(a);
    __m128 arr_b = _mm_loadu_ps(b);

    __m128 calculate = _mm_mul_ps(arr_a, arr_b);
    _mm_storeu_ps(result, calculate);
}

inline void avx2_multiply_floats_256(float a[8], float b[8], float result[8])
{
    __m256 arr_a = _mm256_loadu_ps(a);
    __m256 arr_b = _mm256_loadu_ps(b);

    __m256 calculate = _mm256_mul_ps(arr_a, arr_b);
    _mm256_storeu_ps(result, calculate);
}

}// namespace simd

