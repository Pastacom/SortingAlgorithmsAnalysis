//
// Created by shind_wvnx on 16.02.2023.
//

#pragma once

struct QuickSort {
    static void quickSort(int array[], int n);
private:
    static void sortSubArray(int array[], int left, int right);
    static int partition(int array[], int low, int high);
};
