#include <iostream>
#include <cmath>
#include <iomanip>

int main()
{
    // values
    double a, b;

    // output message
    std::cout << "Enter a & b(in order): ";
    
    // read values
    std::cin >> a >> b; 

    // negative values error handling
    if(a <= 0 || b <= 0)
    {
        std::cout << "ERROR: Values cannot be 0 or negative(-)\n";
        std::cout << "Please review your values!\n";
        std::cout << "a: " << a << '\n';
        std::cout << "b: " << b << '\n';
    }
    else 
    {
        // pythagorean theorem
        double c = std::sqrt(std::pow(a, 2) + std::pow(b, 2));

        std::cout << "a: " << a << '\n';
        std::cout << "b: " << b << '\n';
        std::cout << "Hypotenuse: "
                  << std::fixed << std::setprecision(2) << c << '\n';
    }
}

