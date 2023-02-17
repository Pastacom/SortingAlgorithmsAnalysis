//
// Created by shind_wvnx on 16.02.2023.
//

#pragma once

struct InsertionSort {
    static void insertionSortTime(int *array, int n);

    static void binaryInsertionSortTime(int *array, int n);

    static int insertionSortOperations(int *array, int n);

    static int binaryInsertionSortOperations(int *array, int n);

private:
    static int binarySearchTime(int left, int right, int target, const int *array);

    static int binarySearchOperations(int left, int right, int target, const int *array, int &counter);
};


