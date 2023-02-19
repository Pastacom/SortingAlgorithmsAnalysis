//
// Created by shind_wvnx on 16.02.2023.
//

#pragma once

#include <cstdint>

struct StableCountingSort {
    static void stableCountingSortTime(int *array, int n);

    static int64_t stableCountingSortOperations(int *array, int n);

private:
    static int getMaxValueTime(int *array, int n);

    static int getMaxValueOperations(int *array, int n, int64_t &counter);
};

