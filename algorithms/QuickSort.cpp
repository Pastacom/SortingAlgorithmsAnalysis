//
// Created by shind_wvnx on 16.02.2023.
//

#include <algorithm>
#include "QuickSort.h"

void QuickSort::quickSort(int *array, int n) {
    sortSubArray(array, 0, n-1);
}

void QuickSort::sortSubArray(int *array, int left, int right) {
    if (left < right) {
        int pivot = partition(array, left, right);
        sortSubArray(array, left, pivot-1);
        sortSubArray(array, pivot+1, right);
    }
}

int QuickSort::partition(int *array, int low, int high) {
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