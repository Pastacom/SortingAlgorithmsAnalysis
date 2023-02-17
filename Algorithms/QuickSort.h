//
// Created by shind_wvnx on 16.02.2023.
//

#pragma once

struct QuickSort {
    static void quickSortTime(int *array, int n);

    static int quickSortOperations(int *array, int n);

private:
    static void sortSubArrayTime(int *array, int left, int right);

    static int partitionTime(int *array, int low, int high);

    static void sortSubArrayOperations(int *array, int left, int right, int &counter);

    static int partitionOperations(int *array, int low, int high, int &counter);
};
