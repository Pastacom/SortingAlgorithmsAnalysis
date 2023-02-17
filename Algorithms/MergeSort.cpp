//
// Created by shind_wvnx on 16.02.2023.
//

#include "MergeSort.h"

void MergeSort::mergeSort(int *array, int n) {
    mergeTwoSubArrays(array, 0, n-1);
}

void MergeSort::mergeTwoSubArrays(int *array, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeTwoSubArrays(array, left, mid);
        mergeTwoSubArrays(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

void MergeSort::merge(int *array, int left, int mid, int right) {
    int left_size = mid - left + 1;
    int left_arr[left_size];
    int right_size = right - mid;
    int right_arr[right_size];

    for (int i = 0; i < left_size; ++i) {
        left_arr[i] = array[left + i];
    }
    for (int i = 0; i < right_size; ++i) {
        right_arr[i] = array[mid + i + 1];
    }

    int i = 0, j = 0;
    int current = left;
    while (i < left_size && j < right_size) {
        if (left_arr[i] <= right_arr[j]) {
            array[current++] = left_arr[i++];
        } else {
            array[current++] = right_arr[j++];
        }
    }
    while (i < left_size) {
        array[current++] = left_arr[i++];
    }
    while (j < right_size) {
        array[current++] = right_arr[j++];
    }
}