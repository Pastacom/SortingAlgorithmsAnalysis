//
// Created by shind_wvnx on 16.02.2023.
//

#pragma once

#include <cstdint>

struct QuickSort {
    static void quickSortTime(int *array, int n);

    static int64_t quickSortOperations(int *array, int n);

private:
    static void sortSubArrayTime(int *array, int left, int right);

    static int partitionTime(int *array, int low, int high);

    static void sortSubArrayOperations(int *array, int left, int right, int64_t &counter);

    static int partitionOperations(int *array, int low, int high, int64_t &counter);
};
