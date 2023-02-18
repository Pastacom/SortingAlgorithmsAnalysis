//
// Created by shind_wvnx on 17.02.2023.
//

#include <cstdlib>
#include <algorithm>
#include "../../Algorithms/ShellSort.h"

static void generateArray(int *arr, int end, int length) {
    for (int i = 0; i < length; ++i) {
        arr[i] = rand() % end;
    }
}

static void generateReversedArray(int *arr, int end, int length) {
    for (int i = 0; i < length; ++i) {
        arr[i] = 1 + (rand() % end);
    }
}

static void swapRandomElements(int *arr, int length) {
    for (int i = 0; i < length; ++i) {
        int index = rand() % length;
        std::swap(arr[i], arr[index]);
    }
}

static void chooseArray(int choice, int *array, int n) {
    if (choice == 1) {
        generateArray(array, 5, n);
    } else if (choice == 2) {
        generateArray(array, 4000, n);
    } else if (choice == 3) {
        generateArray(array, 4000, n);
        swapRandomElements(array, n);
    } else {
        generateReversedArray(array, 4100, n);
        ShellSort::ciuraSortTime(array, n);
        for (int i = 0; i < n / 2; ++i) {
            std::swap(array[i], array[n - i - 1]);
        }
    }
}