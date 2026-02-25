#include <iostream>
#include <fstream>
#include <complex>
#include <vector>
#include <string>

using MB = Mandelbrot; // type alias for MandelBrot

struct Mandelbrot
{
    std::vector<int> image;

    double real_min = -2;
    double real_max = 2;
    double img_min = -1.5;
    double img_max = 1.5;
};

int main() 
{
    return 0;
}

