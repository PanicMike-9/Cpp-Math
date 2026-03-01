#include <iostream>
#include <fstream>
#include <complex>
#include <vector>
#include <string>

class MandelBrot
{
    public:
        std::vector<int> image;

        // these values zooms into the set
        double real_min = -1;
        double real_max = 1;
        double img_min = -0.5;
        double img_max = 0.5;

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
                    // map each pixel on the complex plane
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

        void save_gray_scale(const std::string &file_name)
        {
            std::ofstream ofs(file_name, std::ios::binary);

            ofs << "P5\n" << width << ' ' << height << "\n255\n";

            for(int i = 0; i < width * height; ++i)
            {
                int iteration_num = image[i];
                unsigned char color = 
                    static_cast<unsigned char>(255 * iteration_num / max_iteration);
                ofs << color;
            }

            ofs.close();
        }
};

using MB = MandelBrot; // type alias 

void output()
{
    int width, height, max_iteration;
    std::cout << "Enter width, height and max_iteration in order: ";
    std::cin >> width >> height >> max_iteration;

    std::cout << "Generating Mandelbrot Set\n";
    MB fractal = MB(width, height, max_iteration);
    fractal.render_fractal();

    std::cout << "Saving image!\n";
    fractal.save_gray_scale("gray_scale_mandelbrot.ppm");
}

int main() 
{
    return 0;
}

