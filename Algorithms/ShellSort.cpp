//
// Created by shind_wvnx on 16.02.2023.
//

#include "ShellSort.h"

void ShellSort::shellSortTime(int *array, int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            int value = array[i];
            int j = i;
            for (; j >= gap && array[j - gap] > value; j -= gap) {
                array[j] = array[j - gap];
            }
            array[j] = value;
        }
    }
}

void ShellSort::ciuraSortTime(int *array, int n) {
    for (int gap : ciuraSequence) {
        for (int i = gap; i < n; ++i) {
            int value = array[i];
            int j = i;
            for (; j >= gap && array[j - gap] > value; j -= gap) {
                array[j] = array[j - gap];
            }
            array[j] = value;
        }
    }
}

int ShellSort::shellSortOperations(int *array, int n) {
    int counter = 0;
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            int value = array[i];
            int j = i;
            for (; j >= gap && array[j - gap] > value; j -= gap) {
                array[j] = array[j - gap];
                counter += 24;
            }
            array[j] = value;
            counter += 27;
        }
        counter += 10;
    }
    counter += 5;
    return counter;
}

int ShellSort::ciuraSortOperations(int *array, int n) {
    int counter = 0;
    for (int gap : ciuraSequence) {
        for (int i = gap; i < n; ++i) {
            int value = array[i];
            int j = i;
            for (; j >= gap && array[j - gap] > value; j -= gap) {
                array[j] = array[j - gap];
                counter += 24;
            }
            array[j] = value;
            counter += 27;
        }
        counter += 14;
    }
    counter += 4;
    return counter;
}