//
// Created by shind_wvnx on 16.02.2023.
//

#include "TimerGuard.h"

TimerGuard::TimerGuard(std::chrono::duration<double> *time) {
    start = std::chrono::high_resolution_clock::now();
    total = time;
}

TimerGuard::~TimerGuard() {
    std::chrono::duration<double> res = std::chrono::high_resolution_clock::now() - start;
    *total += res;
}