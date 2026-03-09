#include <iostream>
#include <fstream>
#include <complex>
#include <cmath>
#include <vector>
#include <string>
#include <chrono> // for each render time

// multiple fractal formulas
enum class FractalType
{
    mandelbrot,
    julia_set
};

class MandelBrot
{
    public:
        std::vector<int> image;

        // complex plane values
        double real_min = -2.5;
        double real_max = 1;
        double img_min = -1;
        double img_max = 1;

        // width and height for the fractal set
        int width;
        int height;

        // max amount of iteration
        const int max_iteration;

        // enum class for multiple formulas
        FractalType curr_fractal_type = FractalType::julia_set;

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
                    std::complex<double> c;
                    std::complex<double> z;

                    // compute real and img values
                    double compute_real = (real_min + (real_max - real_min) * x / width);
                    double compute_img = (img_max - (img_max - img_min) * y / height);

                    std::complex<double> pixel(compute_real, compute_img);

                    // switch fractal formula
                    switch(curr_fractal_type)
                    {
                        case FractalType::mandelbrot: 
                            c = pixel;
                            z = 0;
                        break;

                        case FractalType::julia_set:
                            real_min = -0.2, real_max = 0.2;
                            img_min = -0.2, img_max = 0.2;
                            z = pixel;
                            c = std::complex<double>(-0.8, 0.156);
                        break;
                    }

                    int iterator = 0;

                    while (std::abs(z) <= 2 && iterator < max_iteration)
                    {
                        z = (z * z) + c;
                        iterator++;
                    }

                    image[y * width + x] = iterator;
                }
            }
        }

        // save in pgm format
        void save_gray_scale(const std::string& file_name)
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

        // save in ppm format
        void save_color(const std::string& file_name)
        {
            std::ofstream ofs(file_name, std::ios::binary);

            ofs << "P6\n" << width << ' ' << height << "\n255\n";

            for(int i = 0; i < width * height; ++i)
            {
                int iteration_num = image[i];
                unsigned char r, g, b;
                if(iteration_num == max_iteration)
                {
                    // main set color
                    r = 0;
                    g = 0;                    
                    b = 0;
                }
                else
                {
                    // color palette smoothening using std::cos()
                    double t = (double)iteration_num / max_iteration;

                    r = (int)(255 * (0.5 + 0.5 * std::cos(6.2831 * (t + 0.2))));
                    g = (int)(255 * (0.5 + 0.5 * std::cos(6.2831 * (t + 0.63))));
                    b = (int)(255 * (0.5 + 0.5 * std::cos(6.2831 * (t + 0.97))));
                }
                ofs.write(reinterpret_cast<char*>(&r), 1);
                ofs.write(reinterpret_cast<char*>(&g), 1);
                ofs.write(reinterpret_cast<char*>(&b), 1);
            }

            ofs.close();
        }

        /*
         * Todo *
         * Add function to create multiple formulas ✅
         * add time bench mark using chrono ❌
         * fix the aspect ratio problem(the stretch) ❌
         * add zoom logic ❌
         */
};

using MB = MandelBrot; // type alias 

void output()
{
    int width, height, max_iteration;
    std::cout << "Enter width, height and max_iteration in order: ";
    std::cin >> width >> height >> max_iteration;

    std::cout << "Generating Mandelbrot Set\n";
    MB fractal = MB(width, height, max_iteration);

    // calculate function duration
    auto start_rt = std::chrono::steady_clock::now();

    fractal.render_fractal();

    auto end_rt = std::chrono::steady_clock::now();

    auto duration_rt = std::chrono::duration_cast<std::chrono::seconds>(end_rt - start_rt);

    std::cout << "Total render duration(ms): " << duration_rt.count() << 's' << '\n';

    std::cout << "Saving image!\n";
    fractal.save_gray_scale("gray_scale_mandelbrot.pgm");
}

void output_color()
{
    int width, height, max_iteration;
    std::cout << "Enter width, height and max_iteration in order: ";
    std::cin >> width >> height >> max_iteration;

    std::cout << "Generating Mandelbrot Set\n";
    MB fractal = MB(width, height, max_iteration);
    
    // calculate function duration
    auto start_rt = std::chrono::steady_clock::now();
    
    fractal.render_fractal();

    auto end_rt = std::chrono::steady_clock::now();

    auto duration_rt = std::chrono::duration_cast<std::chrono::seconds>(end_rt - start_rt);

    std::cout << "Total render duration: " << duration_rt.count() << 's' << '\n';

    std::cout << "Saving image!\n";
    fractal.save_color("color_mandelbrot.ppm");

}

int main() 
{
    output_color();
    return 0;
}

