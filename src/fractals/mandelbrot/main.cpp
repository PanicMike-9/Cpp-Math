#include <iostream>
#include <limits>
#include <chrono> 
#include <cmath> 
#include "renderer.hpp"

// type alias
using MB = Mandelbrot;  

// function prototype
void output_gray_scale();
void output_color();
void generate_frames(int width, int height, int max_iteration, double base_zoom, int total_frames);

int main() 
{
    generate_frames(800, 600, 200, 1.0, 60);
    return 0;
}

// generate multiple frames
void generate_frames(int width, int height, int max_iteration, double base_zoom, int total_frames)
{
    std::cout << "GENERATING FRAMES...\n";

    auto start_anim = std::chrono::steady_clock::now();

    for(int frame = 0; frame < total_frames; ++frame)
    {
        double zoom = base_zoom * exp(-0.05 * frame); // zoom by 5%

        MB fractal(width, height, max_iteration, zoom);

        fractal.render_fractal();

        // filename with index
        char filename[100];
        sprintf(filename, "frame_%04d.ppm", frame);

        fractal.render_color(filename);
    } 

    auto end_anim = std::chrono::steady_clock::now();

    auto duration_anim = std::chrono::duration_cast<std::chrono::seconds>(end_anim - start_anim);

    std::cout << "TOTAL ANIMATION RENDER DURATION: " << duration_anim.count() << "s \n";

    std::cout << "FRAME GENERATION COMPLETED!\n";
}

void output_color()
{
    int width, height, max_iteration;
    double zoom_value;
    std::cout << "ENTER WIDTH, HEIGHT, MAX_ITERATION & ZOOM BY IN ORDER: ";

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
        std::cout << "VALUES EITHER EXCEED THE MAX LIMITS OR ARE INVALID PLEase try again!\n";
        std::cout << "ENTER WIDTH, HEIGHT AND MAX_ITERATION IN ORDER: ";
    }

    std::cout << "GENERATING FRACTAL...\n";
    MB fractal = MB(width, height, max_iteration, zoom_value);

    // custom file name
    std::string file_name;
    
    // calculate function duration
    auto start_rt = std::chrono::steady_clock::now();
    
    fractal.render_fractal();

    auto end_rt = std::chrono::steady_clock::now();

    auto duration_rt = std::chrono::duration_cast<std::chrono::seconds>(end_rt - start_rt);

    std::cout << "TOTAL RENDER DURATION: " << duration_rt.count() << 's' << '\n';

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

    std::cout << "SAVING IMAGE TO: " << file_name << '\n';

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

void output_gray_scale()
{
    int width, height, max_iteration;
    double zoom_value;
    std::cout << "ENTER WIDTH, HEIGHT, MAX_ITERATION & ZOOM BY IN ORDER: ";

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
        std::cout << "VALUES EITHER EXCEED THE MAX LIMITS OR ARE INVALID PLEASE TRY AGAIN!\n";
        std::cout << "ENTER WIDTH, HEIGHT AND MAX_ITERATION IN ORDER: ";
    }

    std::cout << "GENERATING FRACTAL...\n";
    MB fractal = MB(width, height, max_iteration, zoom_value);

    // calculate function duration
    auto start_rt = std::chrono::steady_clock::now();

    fractal.render_fractal();

    auto end_rt = std::chrono::steady_clock::now();

    auto duration_rt = std::chrono::duration_cast<std::chrono::seconds>(end_rt - start_rt);

    std::cout << "TOTAL RENDER DURATION(MS): " << duration_rt.count() << 's' << '\n';

    std::cout << "SAVING IMAGE!\n";
    fractal.render_gray_scale("gray_scale_mandelbrot.pgm");

    // values for debugging
    std::cout << "--- Check Values ---"               << '\n' 
              << "real_min: "  << fractal.real_min    << '\n'
              << "real_max: "  << fractal.real_max    << '\n'
              << "img_min: "   << fractal.img_min     << '\n'
              << "img_max: "   << fractal.img_max     << '\n'
              << "real_span: " << fractal.view.real_span   << '\n';
}
