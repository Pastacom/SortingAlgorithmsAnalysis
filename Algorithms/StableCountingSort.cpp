//
// Created by shind_wvnx on 16.02.2023.
//

#include <algorithm>
#include "StableCountingSort.h"

int StableCountingSort::getMaxValueTime(int *array, int n) {
    int ans = array[0];
    for (int i = 1; i < n; ++i) {
        ans = std::max(ans, array[i]);
    }
    return ans;
}

void StableCountingSort::stableCountingSortTime(int *array, int n) {
    int bound = getMaxValueTime(array, n);
    int sums[bound + 1];
    int res[n];
    for (int i = 0; i < bound + 1; ++i) {
        sums[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        ++sums[array[i]];
    }
    for (int i = 1; i < bound + 1; ++i) {
        sums[i] += sums[i - 1];
    }
    for (int i = n - 1; i >= 0; --i) {
        res[--sums[array[i]]] = array[i];
    }
    for (int i = 0; i < n; ++i) {
        array[i] = res[i];
    }
}

int StableCountingSort::getMaxValueOperations(int *array, int n, int &counter) {
    int ans = array[0];
    for (int i = 1; i < n; ++i) {
        ans = std::max(ans, array[i]);
    }
    return ans;
}

int StableCountingSort::stableCountingSortOperations(int *array, int n) {
    int counter = 0;
    int bound = getMaxValueTime(array, n);
    int sums[bound + 1];
    int res[n];
    for (int i = 0; i < bound + 1; ++i) {
        sums[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        ++sums[array[i]];
    }
    for (int i = 1; i < bound + 1; ++i) {
        sums[i] += sums[i - 1];
    }
    for (int i = n - 1; i >= 0; --i) {
        res[--sums[array[i]]] = array[i];
    }
    for (int i = 0; i < n; ++i) {
        array[i] = res[i];
    }
    return counter;
}