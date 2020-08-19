#include "../include/Timer.hpp"
#include <chrono>

Timer::Timer()
{
    start = std::chrono::high_resolution_clock::now();
}


Timer::Timer(std::string _timerMessage) : Timer() 
{
    timerMessage = _timerMessage;
}

Timer::~Timer()
{
    std::chrono::duration<double> duration = std::chrono::high_resolution_clock::now() - start;
    std::cout << "[" << std::chrono::high_resolution_clock::now().time_since_epoch().count() << "]: " <<"Time taken: "
            << duration.count() * 1000.0 << "ms\n"; 
    std::cout << "[" << std::chrono::high_resolution_clock::now().time_since_epoch().count() << "]: Message: " << timerMessage << "\n"; 
}
