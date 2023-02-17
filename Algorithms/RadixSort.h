//
// Created by shind_wvnx on 16.02.2023.
//

#pragma once

struct RadixSort {
    static void radixSortTime(int *array, int n);

    static int radixSortOperations(int *array, int n);

private:
    static int getMaxValueTime(int *array, int n);

    static int getMaxValueOperations(int *array, int n, int &counter);

};

