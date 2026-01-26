#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <iomanip>

int main()
{
    double radius = 0;
    
    std::cout << "Enter radius: ";
    std::cin >> radius;

    if(radius < 0)
    {
        std::cerr << "ERROR: Invalid radius" << std::endl;
        return 1;
    }
        double diameter = 2 * radius;

        double circumference = 2 * M_PI * radius;

        double area = M_PI * std::pow(radius, 2);

        std::cout << std::fixed << std::setprecision(2) << '\n';
        std::cout << "---- Circle Info ----\n";
        std::cout << std::left << std::setw(15) << "Radius: " << radius << '\n';
        std::cout << std::left << std::setw(15) << "Diameter: " << diameter << '\n';
        std::cout << std::left << std::setw(15) << "Circumference: " 
                  << circumference << '\n';
        std::cout << std::left << std::setw(15) << "Area: " << area << '\n';
        std::cout << "---------------------\n";
}
