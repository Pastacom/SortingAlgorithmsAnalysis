//
// Created by shind_wvnx on 16.02.2023.
//

#pragma once

struct StableCountingSort {
    static void stableCountingSortTime(int *array, int n);

    static int stableCountingSortOperations(int *array, int n);

private:
    static int getMaxValueTime(int *array, int n);

    static int getMaxValueOperations(int *array, int n, int &counter);
};

