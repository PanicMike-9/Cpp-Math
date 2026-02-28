#include <iostream>
#include <fstream>
#include <complex>
#include <vector>
#include <string>

class MandelBrot
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

        // render method
        void render_fractal()
        {
            for(int y = 0; y < height; ++y)
            {
                for(int x = 0; x < width; ++x)
                {
                    // map each pixel on the complex plain
                    std::complex<double> c(real_min + (real_max - real_min) * x / width,
                                           img_min + (img_max - img_min) * y / height);
                    std::complex<double> z = 0;
                    int iterator = 0;

                    while (std::abs(z) <= 2 && iterator < max_iteration)
                    {
                        z = z * z + c;
                        iterator++;
                    }

                    image[y * width + x] = iterator;
                }
            }
        }
};

using MB = MandelBrot; // type alias 

int main() 
{
    std::cout << "no errors!\n";
    return 0;
}

