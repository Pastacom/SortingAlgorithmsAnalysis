//
// Created by shind_wvnx on 16.02.2023.
//

#pragma once

struct StableCountingSort {
    static void stableCountingSort(int array[], int n);

private:
    static int getMaxValue(int *array, int n);
};

