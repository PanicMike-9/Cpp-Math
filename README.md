# math equations in c++

## quadratic equation
- in mathematics, a quadratic equation is an equation that can be rearranged in standardform as:

$$x = \frac{-b \pm \sqrt{b^2 - 4ac}}{2a}$$

- where the variable $$x$$ represents an unknown number, and $$a, b, c$$ represents know numbers, where $$a!=0$$.

- for more info on **quadratic equation** visit: [definition of quadratic equation](https://en.wikipedia.org/wiki/quadratic_equation)

### compile and run
``` bash
g++ quadratic_equation.cpp -o quadratic && ./quadratic 
```
## pythagorean theorem
- in mathematics, the **pythagorean theorem** or **pythagoras's theorem** is a fundamental relation in **euclidean geometry** between the three sides of a **right triangle**. it states that the area of the square whose side is the **hypotenuse** is equal to the sum of the areas of the squares on the other two sides. the theorem can be written as an equation:

$$a^{2}+b^{2}=c^{2}$$

- for more info on **pythagorean theorem** visit: [definition of pythagorean theorem](https://en.wikipedia.org/wiki/pythagorean_theorem)

### compile and run
``` bash
g++ pythagorean_theorem.cpp -o pythagorean && ./pythagorean 
```
## circle solver 
- *π* is commonly  defined as the ratio of a circle's circumference $$c$$ to its diameter $$d$$:

- the program provides the diameter, circumference, and area using:

$$d = 2r$$
$$c = 2\pi r$$
$$a = \pi r{2}$$

- for more info on $$\pi$$ visit: [definition of pi](https://en.wikipedia.org/wiki/pi)

### compile and run
``` bash
g++ circle_solver.cpp -o circlesolver && ./circlesolver 
```
## Vector2

- A lightweight, header-only C++ class for handling 2D vectors. This class provides the basic functions to understand how the Vector2 class works with basic functions like distance and distance squared to dot product and similar

### how to use it
``` C++
//main.cpp
#include <iostream>
#include "vector2.hpp"

int main()
{
    Vector2 test_vec(3.0f, 4.0f);
    std::cout << "Test length\n"
              << "x: " << test_vec.x << '\n'
              << "y: " << test_vec.y << '\n'
              << "Length: " << test_vec.length() << '\n'
              << "Length squared: " << test_vec.length_squared() << '\n';
    
    return 0;
} 
```
### compile and run
``` bash
g++ main.cpp -o run && ./run
```
