//
// Created by shind_wvnx on 16.02.2023.
//

#include <algorithm>
#include "RadixSort.h"

int RadixSort::getMaxValue(int *array, int n) {
    int ans = array[0];
    for (int i = 1; i < n; ++i) {
        ans = std::max(ans, array[i]);
    }
    return ans;
}

void RadixSort::radixSort(int *array, int n) {
    int exp = 1;
    int res[n * 4];
    int max = getMaxValue(array, n);
    while (max / exp > 0) {
        int sums[256];
        for (int & sum : sums) {
            sum = 0;
        }
        for (int i = 0; i < n; ++i) {
            ++sums[array[i] / exp % 256];
        }
        for (int i = 1; i < 256; ++i) {
            sums[i] += sums[i - 1];
        }
        for (int i = n - 1; i >= 0; --i) {
            res[--sums[array[i] / exp % 256]] = array[i];
        }
        for (int i = 0; i < n; ++i) {
            array[i] = res[i];
        }
        exp *= 256;
    }
}