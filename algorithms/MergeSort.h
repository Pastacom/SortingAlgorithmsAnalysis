//
// Created by shind_wvnx on 16.02.2023.
//

#pragma once

struct MergeSort {
    static void mergeSort(int array[], int n);
private:
    static void mergeTwoSubArrays(int array[], int left, int right);
    static void merge(int array[], int left, int mid, int right);
};

