# math equations in c++

## Vector2

- A lightweight, header-only C++ class for handling 2D vectors. This class provides the basic functions to understand how the Vector2 class works with basic functions like distance and distance squared to dot product and similar

### Quick Test
``` C++
#include <iostream>
#include "vector2.hpp"

using vec2 = geom::Vector2;

void test_length()
{
    vec2 test_vec(3.0f, 4.0f);
    std::cout << "test length\n"
              << "x: " << test_vec.x << '\n'
              << "y: " << test_vec.y << '\n'
              << "length: " << test_vec.length() << '\n'
              << "length squared: " << test_vec.length_squared() << '\n';
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
- More detailed tests are here: [linear_algebra/test_vector2.cpp](./src/linear_algebra/test_vector2.cpp)

## Vector3

- A lightweight, header-only C++ class for handling 3D vectors. This class provides the basic functions to understand how the Vector3 class works with basic functions like distance and distance squared to dot product and similar

### Quick Test
``` C++
#include <print>
#include <format>
#include "vector3.hpp"

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
