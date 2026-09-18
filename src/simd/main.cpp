#include <print>
#include "simd_math.hpp"

// inline void cpu_feature_check(); // Warning: Requires fmt/core.h & fmt/color.h
// quick check at runtime
inline bool supports_avx2();

inline void test_256f_scalar_multiplication();
inline void test_256f_multiplication();
inline void test_128f_addition();
inline void test_128f_multiplication();

int main()
{
    test_128f_addition();
    test_256f_multiplication();          
    test_128f_multiplication();
    test_256f_scalar_multiplication();
}

inline void test_256f_scalar_multiplication()
{
    alignas(32) float a[8] {8.0f, 16.0f, 32.0f, 40.0f, 48.0f, 56.0f, 64.0f, 72.0f};
    alignas(32) float b[8] {19.0f, 27.0f, 43.0f, 51.0f, 59.0f, 67.0f, 75.0f, 83.0f};
    const float scalar {100.0f};

    // causes core dumped, stack smashing error with GCC when array size is not known at compile time, no issues with Clang
    simd::array_multiply_scalar_256(a, 8, scalar);

    std::println("256-bit float 'a' array multiplication with const float scalar: {}", scalar);
    for (const float i : a)
    {
        std::print("{} ", i);
    }
    std::println();

    simd::array_multiply_scalar_256(b, 8, scalar);

    std::println("256-bit float 'b' array multiplication with const float scalar: {}", scalar);
    for (const float i : b)
    {
        std::print("{} ", i);
    }
    std::println();
}

inline void test_256f_multiplication()
{
    // alignas 32 = 8 floats * 4 
    alignas(32) float a[8] {8.0f, 16.0f, 32.0f, 40.0f, 48.0f, 56.0f, 64.0f, 72.0f};
    alignas(32) float b[8] {8.0f, 16.0f, 32.0f, 40.0f, 48.0f, 56.0f, 64.0f, 72.0f};
    alignas(32) float result[8];

    simd::multiply_floats_256(a, b, result);

    std::println("256-bit float multiplication");
    for (const float i : result)
    {
        std::print("{} ", i);
    }
    std::println();
}

inline void test_128f_addition()
{
    alignas(16) float a[4] {88.0f, 1600.0f, 44.0f, 4000.49f};
    alignas(16) float b[4] {7.0f, 14.0f, 302.0f, 21.98f};
    alignas(16) float result[4];
    simd::add_floats_128(a, b, result);

    std::println("128-bit float addition");
    for (const float i : result)
    {
        std::print("{} ", i);
    }
    std::println();
}

inline void test_128f_multiplication()
{
    // alignas 16 = 4 floats * 4 
    alignas(16) float a[4] {8.0f, 16.0f, 32.0f, 40.0f};
    alignas(16) float b[4] {8.0f, 16.0f, 32.0f, 40.0f};
    alignas(16) float result[4];

    simd::multiply_floats_128(a, b, result);

    std::println("128-bit float multiplication");
    for (const float i : result)
    {
        std::print("{} ", i);
    }
    std::println();
}

#if 0
#include <fmt/core.h>
#include <fmt/color.h>

inline void cpu_feature_check() 
{
#if defined(__GNUC__) || defined(__clang__)
    __builtin_cpu_init();

    fmt::print(fg(fmt::color::green), "=== Hardware SIMD Support ===\n");
    fmt::print(fg(fmt::color::green), "SSE4.1:  {}\n", __builtin_cpu_supports("sse4.1"));
    fmt::print(fg(fmt::color::green), "SSE4.2:  {}\n", __builtin_cpu_supports("sse4.2"));
    fmt::print(fg(fmt::color::green), "AVX:     {}\n", __builtin_cpu_supports("avx"));
    fmt::print(fg(fmt::color::green), "AVX2:    {}\n", __builtin_cpu_supports("avx2"));
    fmt::print(fg(fmt::color::green), "AVX512F: {}\n", __builtin_cpu_supports("avx512f"));

#else 
    fmt::print(fg(fmt::color::red), "\n!!! Non-GCC/Clang compiler detected (SIMD check skipped) !!!\n");
#endif
}
#endif

inline bool supports_avx2()
{
#if defined(__GNUC__) || defined(__clang__)
    __builtin_cpu_init();
    return __builtin_cpu_supports("avx2");
#else
    return false;
#endif
}
