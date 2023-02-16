//
// Created by shind_wvnx on 16.02.2023.
//

#include "ShellSort.h"

void ShellSort::shellSort(int *array, int n) {
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

void ShellSort::ciuraSort(int *array, int n) {
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