//
// Created by shind_wvnx on 17.02.2023.
//

#include <cstdlib>
#include <algorithm>
#include "../../Algorithms/ShellSort.h"

static int* first;
static int* second;
static int* third;
static int* fourth;

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
            int first_index = rand() % std::min(i, n);
            int second_index = rand() % std::min(i, n);
            std::swap(array[first_index], array[second_index]);
        }
    }
}

static void clearMemory() {
    delete[] first;
    delete[] second;
    delete[] third;
    delete[] fourth;
}

static void generateArrays() {
    int n = 4100;
    clearMemory();
    first = new int[n];
    second = new int[n];
    third = new int[n];
    fourth = new int[n];
    generateArray(first, n, 6);

    generateArray(second, n, 4001);

    generateArray(third, n, 4001);
    ShellSort::ciuraSortTime(third, n);
    swapRandomElements(third, n);

    generateReversedArray(fourth, n, 4101);
    ShellSort::ciuraSortTime(fourth, n);
    for (int i = 0; i < n / 2; ++i) {
        std::swap(fourth[i], fourth[n - i - 1]);
    }
}

static int* chooseArray(int choice) {
    if (choice == 1) {
        return first;
    } else if (choice == 2) {
        return second;
    } else if (choice == 3) {
        return third;
    } else {
        return fourth;
    }
}