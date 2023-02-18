//
// Created by shind_wvnx on 16.02.2023.
//

#include <algorithm>
#include "SelectionSort.h"

void SelectionSort::selectionSortTime(int *array, int n) {
    for (int i = 0; i < n - 1; ++i) {
        int min = i;
        for (int j = i + 1; j < n; ++j) {
            if (array[j] < array[min]) {
                min = j;
            }
        }
        std::swap(array[i], array[min]);
    }
}

int SelectionSort::selectionSortOperations(int *array, int n) {
    int counter = 0;
    for (int i = 0; i < n - 1; ++i) {
        int min = i;
        for (int j = i + 1; j < n; ++j) {
            if (array[j] < array[min]) {
                min = j;
                counter += 2;
            }
            counter += 12;
        }
        std::swap(array[i], array[min]);
        counter += 23;
    }
    counter += 5;
    return counter;
}