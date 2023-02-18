//
// Created by shind_wvnx on 16.02.2023.
//

#include "InsertionSort.h"

void InsertionSort::insertionSortTime(int *array, int n) {
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

int InsertionSort::binarySearchTime(int left, int right, int target, const int *array) {
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

void InsertionSort::binaryInsertionSortTime(int *array, int n) {
    for (int i = 1; i < n; ++i) {
        int index = binarySearchTime(0, i - 1, array[i], array);
        int value = array[i];
        int j = i - 1;
        while (j >= index) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = value;
    }
}

int InsertionSort::insertionSortOperations(int *array, int n) {
    int counter = 0;
    for (int i = 1; i < n; ++i) {
        int value = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > value) {
            array[j + 1] = array[j];
            --j;
            counter += 10;
        }
        array[j + 1] = value;
        counter += 26;
    }
    ++counter;
    return counter;
}

int InsertionSort::binarySearchOperations(int left, int right, int target,
                                          const int *array, int &counter) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (array[mid] == target) {
            counter += 2;
            return mid + 1;
        }
        if (array[mid] < target) {
            left = mid + 1;
            counter += 3;
        } else {
            right = mid - 1;
            counter += 3;
        }
        counter += 20;
    }
    counter += 4;
    return left;
}

int InsertionSort::binaryInsertionSortOperations(int *array, int n) {
    int counter = 0;
    for (int i = 1; i < n; ++i) {
        int index = binarySearchOperations(0, i - 1, array[i], array, counter);
        int value = array[i];
        int j = i - 1;
        while (j >= index) {
            array[j + 1] = array[j];
            --j;
            counter += 13;
        }
        array[j + 1] = value;
        counter += 31;
    }
    counter += 4;
    return counter;
}