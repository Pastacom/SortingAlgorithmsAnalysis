//
// Created by shind_wvnx on 16.02.2023.
//

#include "HeapSort.h"
#include <algorithm>

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

void HeapSort::heapSortTime(int *array, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifyTime(array, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        std::swap(array[0], array[i]);
        heapifyTime(array, i, 0);
    }
}

void HeapSort::heapifyOperations(int *array, int n, int i, int &counter) {
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

int HeapSort::heapSortOperations(int *array, int n) {
    int counter = 0;
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapifyTime(array, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        std::swap(array[0], array[i]);
        heapifyTime(array, i, 0);
    }
    return counter;
}