#include <iostream>
#include <cmath>

int main()
{
    // values
    double a, b, c;

    // read values
    std::cout << "Enter a, b & c(in order): ";
    std::cin >> a >> b >> c;

    // discriminant edge case
    double discriminant = b*b - 4*a*c;

    // edge case check
    if(discriminant < 0)
    {
        std::cout << "ERROR: This equation has no real roots!\n";
        std::cout << "Please review your values!\n";
        std::cout << "a: " << a << '\n';
        std::cout << "b: " << b << '\n';
        std::cout << "c: " << c << '\n';
    }
    else if(a == 0)
    {
        std::cout << "ERROR: Please make sure 'a' value is not 0\n";
        std::cout << "Your current 'a' value is: " << a << '\n';
    }
    else 
    {
        // quadratic equation
        double root1 = (-b + std::sqrt(discriminant)) / (2 * a);
        double root2 = (-b - std::sqrt(discriminant)) / (2 * a);

        // values output
        std::cout << "a: " << a << '\n';
        std::cout << "b: " << b << '\n';
        std::cout << "c: " << c << '\n';

        // root output
        std::cout << "root 1: " << root1 << '\n';
        std::cout << "root 2: " << root2 << '\n';
    }
    return 0;
}
