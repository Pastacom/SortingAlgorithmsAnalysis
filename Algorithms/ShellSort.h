//
// Created by shind_wvnx on 16.02.2023.
//

#pragma once

#include <cstdint>

struct ShellSort {
    static void shellSortTime(int *array, int n);

    static void ciuraSortTime(int *array, int n);

    static int64_t shellSortOperations(int *array, int n);

    static int64_t ciuraSortOperations(int *array, int n);

private:
    static constexpr int ciuraSequence[] = {1750, 701, 301, 132, 57, 23, 10, 4, 1};
};


