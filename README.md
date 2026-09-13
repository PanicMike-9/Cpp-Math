# CPP-Math an educational and light weight Math library written in C++

## Vector2

- A lightweight, header-only C++ class for handling 2D vectors. This class provides the basic functions to understand how the Vector2 class works with basic functions.

### Quick Test
``` C++
#include <iostream>
#include "vector2.hpp"

using vec2 = geom::Vector2;

inline void test_length()
{
    vec2 test_vec(3.0f, 4.0f);
    println("Test Length");
    print
    (
      "x: {:2.2f}\n" 
      "y: {:2.2f}\n"
      test_vec.x, test_vec.y
    );
    println("Length: {}", test_vec.length());
    println("Length Squared: {}", test_vec.length_squared());
}

int main()
{
    test_length();
    return 0;
}
```
### compile and run
``` bash
g++ -Wall -Wextra -Wpedantic -std=c++23 test_vector2.cpp -o run && ./run
```
- More detailed tests are here: [linear_algebra/test_vector2.cpp](./src/linear_algebra/test_vector2.cpp)

## Vector3

- A lightweight, header-only C++ class for handling 3D vectors. This class provides the basic functions to understand how the Vector3 class works with basic functions.

### Quick Test
``` C++
#include <print>
#include <format>
#include "vector3.hpp"

using vec3 = geom::Vector3;

inline void test_length()
{
    vec3 test_vec(3.0f, 4.0f, 1.0f);
    println("Test Length");
    print
    (
      "x: {:2.2f}\n" 
      "y: {:2.2f}\n"
      "z: {:2.2f}\n", 
      test_vec.x, test_vec.y, test_vec.z
    );
    println("Length: {}", test_vec.length());
    println("Length Squared: {}", test_vec.length_squared());
}

int main()
{
    test_length();
    return 0;
}
```
### compile and run
``` bash
g++ -Wall -Wextra -Wpedantic -std=c++23 test_vector3.cpp -o run && ./run
```
- More detailed tests are here: [linear_algebra/test_vector3.cpp](./src/linear_algebra/test_vector3.cpp)

## SIMD Vectorization

- A lightweight, SIMD SSE and AVX-2 based header file. This file provides SIMD based functions, allowing vector mulitiplication, in parallel for 128-bit and 256-bit floats.

### Quick Test
``` C++
#include <print>
#include "simd_multiply_floats.hpp"

int main()
{
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

    alignas(32) float a_sc_256[8] {8.0f, 16.0f, 32.0f, 40.0f, 48.0f, 56.0f, 64.0f, 72.0f};
    alignas(32) float b_sc_256[8] {19.0f, 27.0f, 43.0f, 51.0f, 59.0f, 67.0f, 75.0f, 83.0f};
    const float scalar {100.0f};

    simd::avx2_vec_multiply_scalar_256(a_sc_256, 8, scalar);
    simd::avx2_vec_multiply_scalar_256(b_sc_256, 8, scalar);

    return 0;
}
```
### Compile & Run
With -O3 flag (remove them if needed)

``` Bash
g++ -mavx2 -std=c++23 -O3 main.cpp -o run && ./run
```
or

``` Bash
clang++ -mavx2 -std=c++23 -O3 main.cpp -o run && ./run
```

- More detailed tests are here: [simd/main.cpp](./src/simd/main.cpp)
