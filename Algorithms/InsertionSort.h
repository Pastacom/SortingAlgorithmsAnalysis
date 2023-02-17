//
// Created by shind_wvnx on 16.02.2023.
//

#pragma once

struct InsertionSort {
    static void insertionSort(int *array, int n);

    static void binaryInsertionSort(int *array, int n);

private:
    static int binarySearch(int left, int right, int target, const int *array);
};


