#pragma once
#include <chrono>
#include <iostream>

class Timer
{
    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> start;
        std::string timerMessage;
    public:
    private:

    public:
        Timer();
        Timer(std::string _timerMessage);
        ~Timer();


};
