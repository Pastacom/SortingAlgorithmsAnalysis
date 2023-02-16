//
// Created by shind_wvnx on 16.02.2023.
//

#pragma once

#include <string>
#include <chrono>
#include <iostream>

class TimerGuard  {
    std::string message;
    std::chrono::time_point<std::chrono::system_clock, std::chrono::duration<double>> start;
    std::ostream* stream;

public:
    explicit TimerGuard(std::string_view message = "", std::ostream& out = std::cout);
    ~TimerGuard();
};
