//
// Created by shind_wvnx on 16.02.2023.
//

#pragma once

struct MergeSort {
    static void mergeSortTime(int *array, int n);

    static int mergeSortOperations(int *array, int n);

private:
    static void mergeTwoSubArraysTime(int *array, int left, int right);

    static void mergeTime(int *array, int left, int mid, int right);

    static void mergeTwoSubArraysOperations(int *array, int left, int right, int &counter);

    static void mergeOperations(int *array, int left, int mid, int right, int &counter);
};

