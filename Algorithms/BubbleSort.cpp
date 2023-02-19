//
// Created by shind_wvnx on 16.02.2023.
//

#include <algorithm>
#include <cstdint>
#include "BubbleSort.h"

/**
 * Regular time-efficient bubble sort algorithm.
 * @param array array to sort
 * @param n array size
 */
void BubbleSort::bubbleSortTime(int *array, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                std::swap(array[j], array[j + 1]);
            }
        }
    }
}

/**
 * Time-efficient bubble sort algorithm with first Iverson rule.
 * @param array array to sort
 * @param n array size
 */
void BubbleSort::firstIversonBubbleSortTime(int *array, int n) {
    for (int i = 0; i < n - 1; ++i) {
        bool flag = true;
        for (int j = 0; j < n - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                std::swap(array[j], array[j + 1]);
                flag = false;
            }
        }
        if (flag) {
            break;
        }
    }
}

/**
 * Time-efficient bubble sort algorithm with first and second Iverson rule.
 * @param array array to sort
 * @param n array size
 */
void BubbleSort::secondIversonBubbleSortTime(int *array, int n) {
    int prev = n - 1;
    for (int i = 0; i < n - 1; ++i) {
        int bound = prev;
        prev = 0;
        for (int j = 0; j < bound; ++j) {
            if (array[j] > array[j + 1]) {
                std::swap(array[j], array[j + 1]);
                prev = j;
            }
        }
        if (prev == 0) {
            break;
        }
    }
}

/**
 * Regular operations counting bubble sort algorithm.
 * @param array array to sort
 * @param n array size
 * @return number of performed elementary operations
 */
int64_t BubbleSort::bubbleSortOperations(int *array, int n) {
    int64_t counter = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                std::swap(array[j], array[j + 1]);
                counter += 10;
            }
            counter += 16;
        }
        counter += 13;
    }
    counter += 4;
    return counter;
}

/**
 * Operations counting bubble sort algorithm with first Iverson rule.
 * @param array array to sort
 * @param n array size
 * @return number of performed elementary operations
 */
int64_t BubbleSort::firstIversonBubbleSortOperations(int *array, int n) {
    int64_t counter = 0;
    for (int i = 0; i < n - 1; ++i) {
        bool flag = true;
        for (int j = 0; j < n - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                std::swap(array[j], array[j + 1]);
                flag = false;
                counter += 11;
            }
            counter += 16;
        }
        if (flag) {
            ++counter;
            break;
        }
        counter += 15;
    }
    counter += 5;
    return counter;
}

/**
 * Operations counting bubble sort algorithm with first and second Iverson rule.
 * @param array array to sort
 * @param n array size
 * @return number of performed elementary operations
 */
int64_t BubbleSort::secondIversonBubbleSortOperations(int *array, int n) {
    int64_t counter = 0;
    int prev = n - 1;
    for (int i = 0; i < n - 1; ++i) {
        int bound = prev;
        prev = 0;
        for (int j = 0; j < bound; ++j) {
            if (array[j] > array[j + 1]) {
                std::swap(array[j], array[j + 1]);
                prev = j;
                counter += 12;
            }
            counter += 13;
        }
        if (prev == 0) {
            ++counter;
            break;
        }
        counter += 15;
    }
    counter += 8;
    return counter;
}