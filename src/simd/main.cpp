#include <print>
#include "simd_multiply_floats.hpp"

void cpu_feature_check()
{
#if defined(__GNUC__) || defined(__clang__)
    __builtin_cpu_init();

    std::println("=== Hardware SIMD Support ===");
    std::println("SSE4.1:  {}", __builtin_cpu_supports("sse4.1"));
    std::println("SSE4.2:  {}", __builtin_cpu_supports("sse4.2"));
    std::println("AVX:     {}", __builtin_cpu_supports("avx"));
    std::println("AVX2:    {}", __builtin_cpu_supports("avx2"));
    std::println("AVX512F: {}", __builtin_cpu_supports("avx512f"));

#else 
    std::println("!!! Non-GCC/Clang compiler detected (SIMD check skipped) !!!");
#endif
}

// quick check at runtime
inline bool supports_avx2()
{
#if defined(__GNUC__) || defined(__clang__)
    __builtin_cpu_init();
    return __builtin_cpu_supports("avx2");
#else
    return false;
#endif
}

int main()
{
    // alignas 16 = 4 floats * 4 
    alignas(16) float a_128[4] {8.0f, 16.0f, 32.0f, 40.0f};
    alignas(16) float b_128[4] {8.0f, 16.0f, 32.0f, 40.0f};
    alignas(16) float result_128[4];

    simd::sse_multiply_floats_128(a_128, b_128, result_128);

    std::println("SSE 128-bit float multiplication");
    for (const float i : result_128)
    {
        std::print("{} ", i);
    }
    std::println();

    // alignas 32 = 8 floats * 4 
    alignas(32) float a_256[8] {8.0f, 16.0f, 32.0f, 40.0f, 48.0f, 56.0f, 64.0f, 72.0f};
    alignas(32) float b_256[8] {8.0f, 16.0f, 32.0f, 40.0f, 48.0f, 56.0f, 64.0f, 72.0f};
    alignas(32) float result_256[8];

    simd::avx2_multiply_floats_256(a_256, b_256, result_256);

    std::println("AVX2 256-bit float multiplication");
    for (const float i : result_256)
    {
        std::print("{} ", i);
    }
    std::println();

    // aligna 64 = 16 float * 4
    alignas(32) float a_sc_256[8] {8.0f, 16.0f, 32.0f, 40.0f, 48.0f, 56.0f, 64.0f, 72.0f};
    alignas(32) float b_sc_256[8] {19.0f, 27.0f, 43.0f, 51.0f, 59.0f, 67.0f, 75.0f, 83.0f};
    const float scalar {100.0f};
    //alignas(32) const std::size_t size_of_a {sizeof(a_scalar_256) / sizeof(a_scalar_256[0])};

    // causes core dumped, stack smashing error with GCC when array size is not known at compile time, no issues with Clang
    simd::avx2_vec_multiply_scalar_256(a_sc_256, 8, scalar);

    std::println("AVX2 256-bit float 'a' array multiplication with const float scalar: {}", scalar);
    for (const float i : a_sc_256)
    {
        std::print("{} ", i);
    }
    std::println();

    simd::avx2_vec_multiply_scalar_256(b_sc_256, 8, scalar);

    std::println("AVX2 256-bit float 'b' array multiplication with const float scalar: {}", scalar);
    for (const float i : b_sc_256)
    {
        std::print("{} ", i);
    }
    std::println();

    //cpu_feature_check();
}
