//
// Created by shind_wvnx on 16.02.2023.
//

#include "InsertionSort.h"

void InsertionSort::insertionSort(int *array, int n) {
    for (int i = 1; i < n; ++i) {
        int value = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > value) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = value;
    }
}

int InsertionSort::binarySearch(int left, int right, int target, const int *array) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (array[mid] == target) {
            return mid + 1;
        }
        if (array[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

void InsertionSort::binaryInsertionSort(int *array, int n) {
    for (int i = 1; i < n; ++i) {
        int index = binarySearch(0, i - 1, array[i], array);
        int value = array[i];
        int j = i - 1;
        while (j >= index) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = value;

    }
}