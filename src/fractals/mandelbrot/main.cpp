
#include <iostream>
#include <limits>
#include <chrono> 
#include "renderer.hpp"

// type alias
using MB = Mandelbrot;  

// function prototype
void output_gray_scale();
void output_color();

int main() 
{
    output_color();
    return 0;
}

void output_gray_scale()
{
    int width, height, max_iteration;
    double zoom_value;
    std::cout << "Enter width, height, max_iteration & zoom by in order: ";

    // input validation
    while(true)
    {
        if(std::cin >> width >> height >> max_iteration >> zoom_value && 
                width > 0 && height > 0 && max_iteration > 0 && zoom_value > 0 && 
                width <= 5000 && height <= 5000 && max_iteration <= 1500 && zoom_value <= 1)
        {
            break;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Values either exceed the max limits or are invalid please try again!\n";
        std::cout << "Enter width, height and max_iteration in order: ";
    }

    std::cout << "Generating Fractal...\n";
    MB fractal = MB(width, height, max_iteration, zoom_value);

    // calculate function duration
    auto start_rt = std::chrono::steady_clock::now();

    fractal.render_fractal();

    auto end_rt = std::chrono::steady_clock::now();

    auto duration_rt = std::chrono::duration_cast<std::chrono::seconds>(end_rt - start_rt);

    std::cout << "Total render duration(ms): " << duration_rt.count() << 's' << '\n';

    std::cout << "Saving image!\n";
    fractal.render_gray_scale("gray_scale_mandelbrot.pgm");

    // values for debugging
    std::cout << "--- Check Values ---"               << '\n' 
              << "real_min: "  << fractal.real_min    << '\n'
              << "real_max: "  << fractal.real_max    << '\n'
              << "img_min: "   << fractal.img_min     << '\n'
              << "img_max: "   << fractal.img_max     << '\n'
              << "real_span: " << fractal.view.real_span   << '\n';
}

void output_color()
{
    int width, height, max_iteration;
    double zoom_value;
    std::cout << "Enter width, height, max_iteration & zoom by in order: ";

    // input validation
    while(true)
    {
        if(std::cin >> width >> height >> max_iteration >> zoom_value && 
                width > 0 && height > 0 && max_iteration > 0 && zoom_value > 0 && 
                width <= 5000 && height <= 5000 && max_iteration <= 1500 && zoom_value <= 1)
        {
            break;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Values either exceed the max limits or are invalid please try again!\n";
        std::cout << "Enter width, height and max_iteration in order: ";
    }

    std::cout << "Generating Fractal...\n";
    MB fractal = MB(width, height, max_iteration, zoom_value);

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
    fractal.render_color(file_name);
    
    // values for debugging
    std::cout << "--- Check Values ---"               << '\n' 
              << "real_min: "  << fractal.real_min    << '\n'
              << "real_max: "  << fractal.real_max    << '\n'
              << "img_min: "   << fractal.img_min     << '\n'
              << "img_max: "   << fractal.img_max     << '\n'
              << "real_span: " << fractal.view.real_span   << '\n';
}
