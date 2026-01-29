#include <iostream>
#include <string>
#include <stdexcept>

float calculate_lerp(float start_value, float end_value, float time)
{
    if(time < 0.0f || time > 1.0f) 
        throw std::runtime_error("Time must be between 0.0 and 1.0");
    
    return (1.0f - time) * start_value + time * end_value;
}

int main()
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
    catch (const std::runtime_error&)
    {
        std::cerr << "Logic error: " << e.what() << '\n';
    }
    catch (...)
    {
        std::cerr << "An unknow error occurred!\n";
    }

    return 0;
}
