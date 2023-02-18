//
// Created by shind_wvnx on 16.02.2023.
//

#include <algorithm>
#include "BubbleSort.h"

void BubbleSort::bubbleSortTime(int *array, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                std::swap(array[j], array[j + 1]);
            }
        }
    }
}

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

int BubbleSort::bubbleSortOperations(int *array, int n) {
    int counter = 0;
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

int BubbleSort::firstIversonBubbleSortOperations(int *array, int n) {
    int counter = 0;
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

int BubbleSort::secondIversonBubbleSortOperations(int *array, int n) {
    int counter = 0;
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