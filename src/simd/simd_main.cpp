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
    // 4 floats
    alignas(16) float a_128[4] {8.0f, 16.0f, 32.0f, 40.0f};
    alignas(16) float b_128[4] {8.0f, 16.0f, 32.0f, 40.0f};
    alignas(16) float result_128[4];

    avx_multiply_floats_128(a_128, b_128, result_128);

    std::println("AVX 128-bit float multiplication");
    for (const float i : result_128)
    {
        std::print("{} ", i);
    }
    std::println();

    alignas(32) float a_256[8] {8.0f, 16.0f, 32.0f, 40.0f, 48.0f, 56.0f, 64.0f, 72.0f};
    alignas(32) float b_256[8] {8.0f, 16.0f, 32.0f, 40.0f, 48.0f, 56.0f, 64.0f, 72.0f};
    alignas(32) float result_256[8];

    avx2_multiply_floats_256(a_256, b_256, result_256);

    std::println("AVX 256-bit float multiplication");
    for (const float i : result_256)
    {
        std::print("{} ", i);
    }
    std::println();

    cpu_feature_check();
}
