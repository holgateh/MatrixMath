#include "include/Timer.hpp"
#include <chrono>

Timer::Timer()
{
    start = std::chrono::high_resolution_clock::now();
}
