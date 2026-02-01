#include <iostream>
#include <string>
#include <stdexcept>

// linear interpolaion
float calculate_lerp(float start_value, float end_value, float time)
{
    if(time < 0.0f || time > 1.0f) 
        throw std::runtime_error("Time must be between 0.0 and 1.0");
    
    return (1.0f - time) * start_value + time * end_value;
}

void run_lerp() 
{
    std::string input;

    try 
    {
        std::cout << "Enter start: ";
        std::getline(std::cin, input);
        const float start = std::stof(input);

        std::cout << "Enter end: ";
        std::getline(std::cin, input);
        const float end = std::stof(input);

        std::cout << "Enter time: ";
        std::getline(std::cin, input);
        const float time = std::stof(input);

        std::cout << "LERP: " << calculate_lerp(start, end, time) << '\n';
    }
    catch (const std::invalid_argument&)
    {
        std::cerr << "Error: Input contains non-numeric characters" << '\n';
    }
    catch (const std::out_of_range&)
    {
        std::cerr << "Error: Values too large!" << '\n';
    }
    catch (const std::runtime_error& e)
    {
        std::cerr << "Logic error: " << e.what() << '\n';
    }
    catch (...)
    {
        std::cerr << "An unknow error occurred!\n";
    }
}

// inverse linear interpolation/normalization
float calculate_inverse_lerp(float start_value, float end_value, float value)
{
    float range = end_value - start_value;
    if(range == 0.0f)
        throw std::runtime_error("cannot divide with 0");

    return (value - start_value) / range;
}

void run_inverse_lerp()
{
    std::string input; 

    try 
    {
        std::cout << "Enter start: ";
        std::getline(std::cin, input);
        const float start = std::stof(input);

        std::cout << "Enter end: ";
        std::getline(std::cin, input);
        const float end = std::stof(input);

        std::cout << "Enter value: ";
        std::getline(std::cin, input);
        const float value = std::stof(input);

        std::cout << "Inverse lerp: " << calculate_inverse_lerp(start, end, value)
                  << '\n';
    }
    catch (const std::invalid_argument&)
    {
        std::cerr << "Error: Input contains non-numeric characters\n";
    }
    catch (const std::out_of_range&)
    {
        std::cerr << "Error: Values too large!\n";
    }
    catch (const std::runtime_error& e)
    {
        std::cerr << "Runtime error: " << e.what() << '\n';
    }
    catch (...)
    {
        std::cerr << "An unknown error occurred!\n";
    }
}

int main()
{
    run_inverse_lerp();
    return 0;
}
