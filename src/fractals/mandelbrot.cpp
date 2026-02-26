#include <iostream>
#include <fstream>
#include <complex>
#include <vector>
#include <string>

class Mandelbrot
{
    public:
        std::vector<int> image;

        double real_min = -2;
        double real_max = 2;
        double img_min = -1.5;
        double img_max = 1.5;

        int width;
        int height;
        const int max_iteration;

        // explicit constructor
        MandelBrot(int width_c, int height_c, int max_iteration_c)
            : width(width_c), height(height_c), max_iteration(max_iteration_c) 
        {
            image.resize(width * height);
        }
};

int main() 
{
    std::cout << "working!\n";
    return 0;
}

