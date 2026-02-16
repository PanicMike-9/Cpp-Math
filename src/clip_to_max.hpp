#include <iostream>
#include <algorithm>
#include <stdexcept>

// const expression value
constexpr int MAX_RANGE = 255;

// clip function to clip to max value
int clip(int value)
{
    int clip_to_max = std::max(0, std::min(MAX_RANGE, value));

    if(clip_to_max != value)
    {
        std::cerr << "Value: " << value << " is out of range!\n" 
                  << "Max range: " << MAX_RANGE << '\n';
    }

    return clip_to_max;
}

int main() 
{
    int my_value = 0;
    std::cout << "Value? ";
    std::cin >> my_value;
    std::cout << "My value: " << clip(my_value) << '\n';
    return 0;
}
