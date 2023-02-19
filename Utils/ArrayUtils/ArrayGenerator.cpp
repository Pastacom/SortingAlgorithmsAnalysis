//
// Created by shind_wvnx on 17.02.2023.
//

#include <cstdlib>
#include <algorithm>
#include "../../Algorithms/ShellSort.h"

// Static arrays for each array type.
static int* first;
static int* second;
static int* third;
static int* fourth;

/**
 * Generates default array.
 * @param array pointer to array that have to be filled
 * @param n array size
 * @param bound max value in array
 */
static void generateArray(int *array, int n, int bound) {
    for (int i = 0; i < n; ++i) {
        array[i] = rand() % bound;
    }
}

/**
 * Method to generate reversed array that contains value from 1 to 4100.
 * @param array pointer to array that have to be filled
 * @param n array size
 * @param bound max value in array
 */
static void generateReversedArray(int *array,  int n, int bound) {
    for (int i = 0; i < n; ++i) {
        array[i] = 1 + (rand() % bound);
    }
}

/**
 * Method to swap some elements to simulate almost sorted array. Swapping 10 pairs in each 1000 elements.
 * @param array pointer to array that have to be filled
 * @param n array size
 */
static void swapRandomElements(int *array, int n) {
    for (int i = 1000; i-1000 <= n; i += 1000) {
        for (int j = 0; j < 10; ++j) {
            int first_index = rand() % std::min(i, n);
            int second_index = rand() % std::min(i, n);
            std::swap(array[first_index], array[second_index]);
        }
    }
}

/**
 * Delete static arrays data.
 */
static void clearMemory() {
    delete[] first;
    delete[] second;
    delete[] third;
    delete[] fourth;
}

/**
 * Generate arrays before sorting.
 */
static void generateArrays() {
    int n = 4100;
    clearMemory();
    first = new int[n];
    second = new int[n];
    third = new int[n];
    fourth = new int[n];
    // Array filled with numbers from 0 to 5.
    generateArray(first, n, 6);

    // Array filled with numbers from 0 to 4000.
    generateArray(second, n, 4001);

    // Almost sorted array filled with numbers from 0 to 4000.
    generateArray(third, n, 4001);
    ShellSort::ciuraSortTime(third, n);
    swapRandomElements(third, n);

    // Reversed sorted array filled with numbers from 1 to 4100.
    generateReversedArray(fourth, n, 4100);
    ShellSort::ciuraSortTime(fourth, n);
    for (int i = 0; i < n / 2; ++i) {
        std::swap(fourth[i], fourth[n - i - 1]);
    }
}

/**
 * Return array according to passed type parameter.
 * @param choice array type parameter
 * @return array of specific type
 */
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