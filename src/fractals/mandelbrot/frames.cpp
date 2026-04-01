#include <iostream>
#include <limits>
#include <chrono>
#include <cmath>

#include "frames.hpp"

// multiple images with different zoom values
void generate_zoom()
{
    int width, height, max_iteration, total_frames;
    double base_zoom;
    std::cout << "ENTER WIDTH, HEIGHT, MAX_ITERATION, BASE_ZOOM && TOTAL_FRAMES IN ORDER: ";

    // input validation
    while(true)
    {
        if(std::cin >> width >> height >> max_iteration >> base_zoom >> total_frames &&
                width > 0 && height > 0 && max_iteration > 0 && base_zoom > 0 && total_frames > 0 &&  
                width <= 5000 && height <= 5000 && max_iteration <= 1500 && base_zoom <= 1.00 && total_frames <= 150)
        {
            break;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout  << "** INVALID INPUT! **\n"  
                   << "** VALUES SHOULD BE **\n"
                   << "*  WIDTH/HEIGHT:   1-5000 \n"
                   << "*  MAX_ITERATION:  1-1500 \n"
                   << "*  BASE_ZOOM:      0.0-1.0 \n"
                   << "*  TOTAL_FRAMES:   1-150  \n";
        std::cout << "\nENTER WIDTH, HEIGHT, MAX_ITERATION, BASE_ZOOM && TOTAL_FRAMES IN ORDER: ";
    }

    std::cout << "GENERATING FRAMES...\n";

    auto start_anim = std::chrono::steady_clock::now();

    for(int frame = 0; frame < total_frames; ++frame)
    {
        double zoom = base_zoom * exp(-0.05 * frame); // zoom by 5%

        MB fractal(width, height, max_iteration, zoom);

        fractal.render_fractal();

        // filename with index
        char filename[100];
        sprintf(filename, "frm_%04d.ppm", frame);

        fractal.render_color(filename);
    } 

    auto end_anim = std::chrono::steady_clock::now();

    auto duration_anim = std::chrono::duration_cast<std::chrono::seconds>(end_anim - start_anim);

    std::cout << "TOTAL ANIMATION RENDER DURATION: " << duration_anim.count() << "s \n";

    std::cout << "FRAME GENERATION COMPLETED!\n";
}

/*
// single image in color
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
        std::cout << "VALUES EITHER EXCEED THE MAX LIMITS OR ARE INVALID PLEASE TRY AGAIN!\n";
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
        case  FractalType::mandelbrot:          file_name  =  "Mandelbrot.ppm";          break;
        case  FractalType::julia_classic:       file_name  =  "Julia_classic.ppm";       break;
        case  FractalType::julia_flower:        file_name  =  "Julia_flower.ppm";        break;
        case  FractalType::julia_cone:          file_name  =  "Julia_cone.ppm";          break;
        case  FractalType::julia_spiral:        file_name  =  "Julia_spiral.ppm";        break;
        case  FractalType::julia_snake:         file_name  =  "Julia_snake.ppm";         break;
        case  FractalType::julia_silver_ratio:  file_name  =  "Julia_silver_ratio.ppm";  break;

        default:  file_name  =  "Unknown_fractal.ppm";  break;
    }

    std::cout << "SAVING IMAGE TO: " << file_name << '\n';

    // save file
    fractal.render_color(file_name);
}

// single image in gray scale
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
}
*/
