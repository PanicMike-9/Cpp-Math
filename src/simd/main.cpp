#include "test_simd.hpp"

int main()
{
    std::println("128-bit float addition");
    test_128f_addition();

    std::println("256-bit addition");
    test_256f_addition();

    std::println("256-bit float multiplication");
    test_256f_multiplication();          

    std::println("128-bit float multiplication");
    test_128f_multiplication();

    std::println("256-bit float scalar multiplication");
    test_256f_scalar_multiplication();
}
