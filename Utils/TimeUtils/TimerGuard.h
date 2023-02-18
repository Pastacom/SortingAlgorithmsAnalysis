//
// Created by shind_wvnx on 16.02.2023.
//

#pragma once

#include <string>
#include <chrono>
#include <iostream>

class TimerGuard  {
    std::chrono::time_point<std::chrono::system_clock, std::chrono::duration<double>> start;
    std::chrono::duration<double>* total;
public:
    explicit TimerGuard(std::chrono::duration<double>* time = nullptr);
    ~TimerGuard();
};
