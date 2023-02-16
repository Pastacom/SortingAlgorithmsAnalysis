//
// Created by shind_wvnx on 16.02.2023.
//

#include "TimerGuard.h"

TimerGuard::TimerGuard(std::string_view message, std::ostream &out) {
    this->message = message;
    start = std::chrono::high_resolution_clock::now();
    stream = &out;
}

TimerGuard::~TimerGuard() {
    std::chrono::duration<double> res = std::chrono::high_resolution_clock::now() - start;
    *stream << message << " " << res.count() * 1000000 << " ns\n";
}