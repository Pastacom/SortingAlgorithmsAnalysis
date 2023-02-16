//
// Created by shind_wvnx on 16.02.2023.
//

static bool isSorted(const int* array, int n) {
    if (n == 0 || n == 1) {
        return true;
    }
    for (int i = 1; i < n; ++i) {
        if (array[i] < array[i-1]) {
            return false;
        }
    }
    return true;
}
