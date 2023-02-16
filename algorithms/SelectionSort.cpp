//
// Created by shind_wvnx on 16.02.2023.
//

#include <algorithm>
#include "SelectionSort.h"

void SelectionSort::selectionSort(int *array, int n) {
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