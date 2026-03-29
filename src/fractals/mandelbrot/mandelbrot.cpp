#include <iostream> 
#include <fstream>
#include <complex>
#include <cmath>
#include <vector>
#include <string>
#include <limits>
#include <chrono> // for each render time

// global constexpr
constexpr double PI  = 3.141592653589793;
constexpr double TAU = 2.0 * PI;

// multiple fractal formulas
enum class FractalType
{
    mandelbrot,
    julia_classic,
    julia_flower,
    julia_cone,
    julia_spiral, 
    julia_snake, 
    julia_silver_ratio, 
};

// choose from multiple types
enum class PaletteType
{
    sunset,
    ocean,
    fire,
    neon,
    blue_green,
    orange_valley,
    rainbow,
    fire_ice,
    elec_magenta,
    emerald,
    elec_blue,
};

// palette phases struct
struct Palette
{
    double r_phase;
    double g_phase;
    double b_phase;
};

// palette switching
Palette get_palette(PaletteType type)
{
    switch(type)
    {
        case PaletteType::sunset:        return {0.99, 0.20, 0.75};
        case PaletteType::ocean:         return {0.10, 0.40, 0.70};
        case PaletteType::fire:          return {0.00, 0.10, 0.20};
        case PaletteType::neon:          return {0.80, 0.50, 0.30};
        case PaletteType::blue_green:    return {0.04, 0.99, 0.25};
        case PaletteType::orange_valley: return {1.00, 0.20, 0.30};
        case PaletteType::rainbow:       return {0.00, 0.33, 0.67};
        case PaletteType::fire_ice:      return {0.00, 0.05, 0.05};
        case PaletteType::elec_magenta:  return {0.10, 0.50, 0.10};
        case PaletteType::emerald:       return {0.50, 0.20, 0.25};
        case PaletteType::elec_blue:     return {0.50, 0.10, 0.00};
    }

    // fallback
    return {0.1, 0.4, 0.7};
}

// camera for the set(defaults to mandelbrot set)
struct FractalView
{
    double center_real{-0.75}; 
    double center_img{0.0}; 
    double real_span{3.5}; 
};

class MandelBrot
{
    public:
        std::vector<int> image;

        // width and height for the fractal set
        int width;
        int height;

        // FractalView for julia set centering(does not work for mandelbrot)
        FractalView julia_view{ 0.0, 0.0, 3.0 };

        // complex plane real values
        double real_min = julia_view.center_real - julia_view.real_span/2;
        double real_max = julia_view.center_real + julia_view.real_span/2;

        double aspect_ratio = static_cast<double>(height) / static_cast<double>(width);
        double img_span = julia_view.real_span * aspect_ratio;

        // complex plane imaginary values
        double img_min = julia_view.center_img - img_span / 2;
        double img_max = julia_view.center_img + img_span / 2;

        // max amount of iteration
        const int max_iteration;

        // enum class for multiple formulas
        FractalType curr_fractal_type = FractalType::julia_snake;

        // custom palette
        Palette palette = get_palette(PaletteType::rainbow);

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
                    double compute_real = (real_min + (real_max - real_min) * static_cast<double>(x) / width);
                    double compute_img = (img_max - (img_max - img_min) * static_cast<double>(y) / height);

                    std::complex<double> pixel(compute_real, compute_img);

                    // switch fractal formula
                    switch(curr_fractal_type)
                    {
                        case FractalType::mandelbrot: 
                            c = pixel;
                            z = 0;
                        break;

                        case FractalType::julia_classic:
                            z = pixel;
                            c = std::complex<double>(-0.8, 0.156);
                        break;

                        case FractalType::julia_flower:
                            z = pixel;
                            c = std::complex<double>(0.35, 0.35);
                        break;

                        case FractalType::julia_cone:
                            z = pixel;
                            c = std::complex<double>(-0.4, 0.6);
                        break;
                        
                        case FractalType::julia_spiral:
                            z = pixel;
                            c = std::complex<double>(0.285, 0.01);
                        break;

                        case FractalType::julia_snake:
                            z = pixel;
                            c = std::complex<double>(-0.835, 0.2321);
                        break;
                            
                        case FractalType::julia_silver_ratio:
                            z = pixel;
                            c = std::complex<double>(-0.75, 0.11);
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

            // performance trick
            double inv_max_iteration = 1.0 / max_iteration;

            for(int i = 0; i < width * height; ++i)
            {
                int iteration_num = image[i];
                unsigned char r, g, b;
                if(iteration_num == max_iteration)
                {
                    // colors the set black
                    r = 0;
                    g = 0;                    
                    b = 0;
                }
                else
                {
                    // color palette smoothening using std::cos()
                    double t = iteration_num * inv_max_iteration;

                    r = (int)(255 * (0.5 + 0.5 * std::cos(TAU * (t + palette.r_phase))));
                    g = (int)(255 * (0.5 + 0.5 * std::cos(TAU * (t + palette.g_phase))));
                    b = (int)(255 * (0.5 + 0.5 * std::cos(TAU * (t + palette.b_phase))));
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
         * add time bench mark using chrono ✅
         * fix the aspect ratio problem(the stretch) ✅ 
         * add zoom logic ❌
         * add a struct Palette✅
         * add a enum class PaletteType✅
         * add input validation✅
         */
};

using MB = MandelBrot; // type alias 

void output()
{
    int width, height, max_iteration;
    std::cout << "Enter width, height and max_iteration in order: ";

    // input validation
    while(true)
    {
        if(std::cin >> width >> height >> max_iteration && 
                width > 0 && height > 0 && max_iteration > 0 && 
                width <= 5000 && height <= 5000 && max_iteration <= 1500)
        {
            break;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Values either exceed the max limits or are invalid please try again!\n";
        std::cout << "Enter width, height and max_iteration in order: ";
    }

    std::cout << "Generating Fractal...\n";
    MB fractal = MB(width, height, max_iteration);

    // calculate function duration
    auto start_rt = std::chrono::steady_clock::now();

    fractal.render_fractal();

    auto end_rt = std::chrono::steady_clock::now();

    auto duration_rt = std::chrono::duration_cast<std::chrono::seconds>(end_rt - start_rt);

    std::cout << "Total render duration(ms): " << duration_rt.count() << 's' << '\n';

    std::cout << "Saving image!\n";
    fractal.save_gray_scale("gray_scale_mandelbrot.pgm");

    // values for debugging
    std::cout << "--- Check Values ---"               << '\n' 
              << "real_min: "  << fractal.real_min    << '\n'
              << "real_max: "  << fractal.real_max    << '\n'
              << "img_min: "   << fractal.img_min     << '\n'
              << "img_max: "   << fractal.img_max     << '\n'
              << "real_span: " << fractal.julia_view.real_span   << '\n';
}

void output_color()
{
    int width, height, max_iteration;
    std::cout << "Enter width, height and max_iteration in order: ";

    // input validation
    while(true)
    {
        if(std::cin >> width >> height >> max_iteration && 
                width > 0 && height > 0 && max_iteration > 0 && 
                width <= 5000 && height <= 5000 && max_iteration <= 1500)
        {
            break;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Values either exceed the max limits or are invalid please try again!\n";
        std::cout << "Enter width, height and max_iteration in order: ";
    }

    std::cout << "Generating Fractal...\n";
    MB fractal = MB(width, height, max_iteration);

    // custom file name
    std::string file_name;
    
    // calculate function duration
    auto start_rt = std::chrono::steady_clock::now();
    
    fractal.render_fractal();

    auto end_rt = std::chrono::steady_clock::now();

    auto duration_rt = std::chrono::duration_cast<std::chrono::seconds>(end_rt - start_rt);

    std::cout << "Total render duration: " << duration_rt.count() << 's' << '\n';

    // unqiue fractal file name
    switch(fractal.curr_fractal_type)
    {
        case FractalType::mandelbrot:         file_name = "Mandelbrot.ppm";         break;
        case FractalType::julia_classic:      file_name = "Julia_classic.ppm";      break;
        case FractalType::julia_flower:       file_name = "Julia_flower.ppm";       break;
        case FractalType::julia_cone:         file_name = "Julia_cone.ppm";         break;
        case FractalType::julia_spiral:       file_name = "Julia_spiral.ppm";       break;
        case FractalType::julia_snake:        file_name = "Julia_snake.ppm";        break;
        case FractalType::julia_silver_ratio: file_name = "Julia_silver_ratio.ppm"; break;

        default: file_name = "Unknown_fractal.ppm"; break;
    }

    std::cout << "Saving image to: " << file_name << '\n';

    // save file
    fractal.save_color(file_name);
    
    // values for debugging
    std::cout << "--- Check Values ---"               << '\n' 
              << "real_min: "  << fractal.real_min    << '\n'
              << "real_max: "  << fractal.real_max    << '\n'
              << "img_min: "   << fractal.img_min     << '\n'
              << "img_max: "   << fractal.img_max     << '\n'
              << "real_span: " << fractal.julia_view.real_span   << '\n';
}

int main() 
{
    output_color();
    return 0;
}
