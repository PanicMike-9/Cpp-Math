# Math Equations in C++

## Quadratic Equation
- In mathematics, a quadratic equation is an equation that can be rearranged in standardform as:

$$x = \frac{-b \pm \sqrt{b^2 - 4ac}}{2a}$$

- Where the variable $$x$$ represents an unknown number, and $$a, b, c$$ represents know numbers, where $$a!=0$$.

- for more info on **Quadratic Equation** visit: [Definition of Quadratic Equation](https://en.wikipedia.org/wiki/Quadratic_equation)

### Compile and Run
``` bash
g++ quadratic_equation.cpp -o quadratic && ./quadratic 
```
## Pythagorean Theorem
- In mathematics, the **Pythagorean theorem** or **Pythagoras's theorem** is a fundamental relation in **Euclidean Geometry** between the three sides of a **right triangle**. It states that the area of the square whose side is the **hypotenuse** is equal to the sum of the areas of the squares on the other two sides. The theorem can be written as an equation:

$$a^{2}+b^{2}=c^{2}$$

- for more info on **Pythagorean Theorem** visit: [Definition of Pythagorean Theorem](https://en.wikipedia.org/wiki/Pythagorean_theorem)

### Compile and Run
``` bash
g++ pythagorean_theorem.cpp -o pythagorean && ./pythagorean 
```
## Circle Solver 
- *π* is commonly  defined as the ratio of a circle's circumference $$C$$ to its diameter $$d$$:

- The program provides the diameter, circumference, and area using:

$$d = 2r$$
$$C = 2\pi r$$
$$A = \pi r{2}$$

- for more info on $$\pi$$ visit: [Definition of Pi](https://en.wikipedia.org/wiki/Pi)

### Compile and Run
``` bash
g++ circle_solver.cpp -o circlesolver && ./circlesolver 
```
## Linear Interpolation
- Linear interpolation is a method of curve fitting using linear polynomials to construct new data points within the range of discrete set of known points, the **precise method** 

$$lerp(a, b, t) = a + (b - a) * t$$

- for more info on Linear interpolation visit: [Definition of LERP](https://en.wikipedia.org/wiki/Linear_interpolation)

### Compile and Run
``` bash
g++ linear_interpolation.cpp -o lerp && ./lerp 
```
## Min-Max Normalization
- Also know as min-max scaling, rescaling is the simplest method and consists in rescaling the range of features to scale teh range in [0, 1] or [-1, 1]. The general formula for a min-max normalization is:

$$x={\frac {x-{\text{min}}(x)}{{\text{max}}(x)-{\text{min}}(x)}}$$

- for more info on min-max normalization visit: [Definition of min-max normalization](https://en.wikipedia.org/wiki/Feature_scaling)

## Compile and Run
``` C++
// in linear_interpolation.cpp
// in main run_inverse_lerp function
void run_inverse_lerp()
```
and then

``` bash
g++ linear_interpolation.cpp -o lerp && ./lerp
```

