//
// Created by shind_wvnx on 16.02.2023.
//

#include "HeapSort.h"
#include <algorithm>
#include <cstdint>

/**
 * Time-efficient method to perform heap sort.
 * @param array array to sort
 * @param n array size
 * @param i index in array
 */
void HeapSort::heapifyTime(int *array, int n, int i) {
    int val = i;
    do {
        i = val;
        int left = 2 * i + 1;
        int right = 2 * (i + 1);
        if (left < n && array[left] > array[val]) {
            val = left;
        }
        if (right < n && array[right] > array[val]) {
            val = right;
        }
        std::swap(array[val], array[i]);
    } while (val != i);
}

/**
 * Time-efficient method to iterate over elements meanwhile sorting with heapify.
 * @param array array to sort
 * @param n array size
 */
void HeapSort::heapSortTime(int *array, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifyTime(array, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        std::swap(array[0], array[i]);
        heapifyTime(array, i, 0);
    }
}

/**
 * Operations counting method to perform heap sort.
 * @param array array to sort
 * @param n array size
 * @param i index in array
 * @param counter number of performed elementary operations
 */
void HeapSort::heapifyOperations(int *array, int n, int i, int64_t &counter) {
    int val = i;
    counter += 2;
    do {
        i = val;
        int left = 2 * i + 1;
        int right = 2 * (i + 1);
        if (left < n && array[left] > array[val]) {
            val = left;
            counter += 2;
        }
        if (right < n && array[right] > array[val]) {
            val = right;
            counter += 2;
        }
        std::swap(array[val], array[i]);
        counter += 44;
    } while (val != i);
}

/**
 * Operations counting method to iterate over elements meanwhile sorting with heapify.
 * @param array array to sort
 * @param n array size
 * @param counter number of performed elementary operations
 */
int64_t HeapSort::heapSortOperations(int *array, int n) {
    int64_t counter = 0;
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifyOperations(array, n, i, counter);
        counter += 9;
    }
    for (int i = n - 1; i > 0; i--) {
        std::swap(array[0], array[i]);
        heapifyOperations(array, i, 0, counter);
        counter += 17;
    }
    counter += 11;
    return counter;
}