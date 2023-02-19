//
// Created by shind_wvnx on 16.02.2023.
//

#include <algorithm>
#include "QuickSort.h"

void QuickSort::quickSortTime(int *array, int n) {
    sortSubArrayTime(array, 0, n-1);
}

void QuickSort::sortSubArrayTime(int *array, int left, int right) {
    if (left < right) {
        int pivot = partitionTime(array, left, right);
        sortSubArrayTime(array, left, pivot-1);
        sortSubArrayTime(array, pivot+1, right);
    }
}

int QuickSort::partitionTime(int *array, int low, int high) {
    int target = array[low];
    int left = low+1;
    int right = high;
    while (left <= right) {
        while (array[left] <= target && left <= right) {
            ++left;
        }
        while (array[right] >= target && left <= right) {
            --right;
        }
        if (left > right) {
            break;
        }
        std::swap(array[left], array[right]);
    }
    std::swap(array[low], array[right]);
    return right;
}

int64_t QuickSort::quickSortOperations(int *array, int n) {
    int64_t counter = 0;
    sortSubArrayOperations(array, 0, n-1, counter);
    counter += 5;
    return counter;
}

void QuickSort::sortSubArrayOperations(int *array, int left, int right, int64_t &counter) {
    if (left < right) {
        int pivot = partitionOperations(array, left, right, counter);
        sortSubArrayOperations(array, left, pivot-1, counter);
        sortSubArrayOperations(array, pivot+1, right, counter);
        counter += 18;
    }
    counter += 3;
}

int QuickSort::partitionOperations(int *array, int low, int high, int64_t &counter) {
    int target = array[low];
    int left = low+1;
    int right = high;
    counter += 9;
    while (left <= right) {
        while (array[left] <= target && left <= right) {
            counter += 11;
            ++left;
        }
        while (array[right] >= target && left <= right) {
            counter += 11;
            --right;
        }
        if (left > right) {
            ++counter;
            break;
        }
        std::swap(array[left], array[right]);
        counter += 33;
    }
    std::swap(array[low], array[right]);
    counter += 13;
    return right;
}