//
// Created by shind_wvnx on 17.02.2023.
//

#include <cstdlib>
#include <algorithm>
#include "../../Algorithms/ShellSort.h"

static void generateArray(int *array, int n, int bound) {
    for (int i = 0; i < n; ++i) {
        array[i] = rand() % bound;
    }
}

static void generateReversedArray(int *array,  int n, int bound) {
    for (int i = 0; i < n; ++i) {
        array[i] = 1 + (rand() % bound);
    }
}

static void swapRandomElements(int *array, int n) {
    for (int i = 1000; i-1000 <= n; i += 1000) {
        for (int j = 0; j < 10; ++j) {
            int first = rand() % std::min(i, n);
            int second = rand() % std::min(i, n);
            std::swap(array[first], array[second]);
        }
    }
}

static void chooseArray(int choice, int *array, int n) {
    if (choice == 1) {
        generateArray(array, n, 6);
    } else if (choice == 2) {
        generateArray(array, n, 4001);
    } else if (choice == 3) {
        generateArray(array, n, 4001);
        ShellSort::ciuraSortTime(array, n);
        swapRandomElements(array, n);
    } else {
        generateReversedArray(array, n, 4101);
        ShellSort::ciuraSortTime(array, n);
        for (int i = 0; i < n / 2; ++i) {
            std::swap(array[i], array[n - i - 1]);
        }
    }
}