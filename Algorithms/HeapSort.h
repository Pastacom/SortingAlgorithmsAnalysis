//
// Created by shind_wvnx on 16.02.2023.
//

#pragma once

struct HeapSort {
    static void heapSort(int *array, int n);

private:
    static void heapify(int *array, int n, int i);
};


