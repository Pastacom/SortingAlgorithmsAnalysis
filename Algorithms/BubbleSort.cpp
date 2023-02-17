//
// Created by shind_wvnx on 16.02.2023.
//

#include <algorithm>
#include "BubbleSort.h"

void BubbleSort::bubbleSort(int *array, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                std::swap(array[j], array[j + 1]);
            }
        }
    }
}

void BubbleSort::firstIversonBubbleSort(int *array, int n) {
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

void BubbleSort::secondIversonBubbleSort(int *array, int n) {
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