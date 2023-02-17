//
// Created by shind_wvnx on 16.02.2023.
//

#include <map>
#include <functional>
#include <string>
#include "../../Algorithms/SelectionSort.h"
#include "../../Algorithms/BubbleSort.h"
#include "../../Algorithms/InsertionSort.h"
#include "../../Algorithms/StableCountingSort.h"
#include "../../Algorithms/RadixSort.h"
#include "../../Algorithms/MergeSort.h"
#include "../../Algorithms/QuickSort.h"
#include "../../Algorithms/HeapSort.h"
#include "../../Algorithms/ShellSort.h"

static std::map<int, std::pair<std::function<void(int*, int)>, std::string>> algorithms {
        {1, std::make_pair(SelectionSort::selectionSort, "Selection sort")},
        {2, std::make_pair(BubbleSort::bubbleSort, "Regular bubble sort")},
        {3, std::make_pair(BubbleSort::firstIversonBubbleSort, "First Iverson rule bubble sort")},
        {4, std::make_pair(BubbleSort::secondIversonBubbleSort, "First & second Iverson rule bubble sort")},
        {5, std::make_pair(InsertionSort::insertionSort, "Insertion sort")},
        {6, std::make_pair(InsertionSort::binaryInsertionSort, "Binary insertion sort")},
        {7, std::make_pair(StableCountingSort::stableCountingSort, "Stable counting sort")},
        {8, std::make_pair(RadixSort::radixSort, "Radix sort")},
        {9, std::make_pair(MergeSort::mergeSort, "Merge sort")},
        {10, std::make_pair(QuickSort::quickSort, "Quick sort")},
        {11, std::make_pair(HeapSort::heapSort, "Heap sort")},
        {12, std::make_pair(ShellSort::shellSort, "Shell sort")},
        {13, std::make_pair(ShellSort::ciuraSort, "Ciura sort")}
};

static std::function<void(int*, int)> chooseAlgorithm(int choice) {
    return algorithms[choice].first;
}

static std::string getName(int choice) {
    return algorithms[choice].second;
}