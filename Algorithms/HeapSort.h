//
// Created by shind_wvnx on 16.02.2023.
//

#pragma once

#include <cstdint>

struct HeapSort {
    static void heapSortTime(int *array, int n);

    static int64_t heapSortOperations(int *array, int n);

private:
    static void heapifyTime(int *array, int n, int i);

    static void heapifyOperations(int *array, int n, int i, int64_t &counter);
};


