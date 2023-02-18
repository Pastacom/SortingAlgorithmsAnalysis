//
// Created by shind_wvnx on 18.02.2023.
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

static std::map<int, std::pair<std::pair < std::function < void(int *, int)>,
        std::function<int(int*, int)>>,
std::string>> algorithms {
{1, std::make_pair(std::make_pair(SelectionSort::selectionSortTime,
                                  SelectionSort::selectionSortOperations),
"Selection sort")},
{2, std::make_pair(std::make_pair(BubbleSort::bubbleSortTime,
                                  BubbleSort::bubbleSortOperations),
"Regular bubble sort")},
{3, std::make_pair(std::make_pair(BubbleSort::firstIversonBubbleSortTime,
                                  BubbleSort::firstIversonBubbleSortOperations),
"First Iverson rule bubble sort")},
{4, std::make_pair(std::make_pair(BubbleSort::secondIversonBubbleSortTime,
                                  BubbleSort::secondIversonBubbleSortOperations),
"First & second Iverson rule bubble sort")},
{5, std::make_pair(std::make_pair(InsertionSort::insertionSortTime,
                                  InsertionSort::insertionSortOperations),
"Insertion sort")},
{6, std::make_pair(std::make_pair(InsertionSort::binaryInsertionSortTime,
                                  InsertionSort::binaryInsertionSortOperations),
"Binary insertion sort")},
{7, std::make_pair(std::make_pair(StableCountingSort::stableCountingSortTime,
                                  StableCountingSort::stableCountingSortOperations),
"Stable counting sort")},
{8, std::make_pair(std::make_pair(RadixSort::radixSortTime,
                                  RadixSort::radixSortOperations),
"Radix sort")},
{9, std::make_pair(std::make_pair(MergeSort::mergeSortTime,
                                  MergeSort::mergeSortOperations),
"Merge sort")},
{10, std::make_pair(std::make_pair(QuickSort::quickSortTime,
                                   QuickSort::quickSortOperations),
"Quick sort")},
{11, std::make_pair(std::make_pair(HeapSort::heapSortTime,
                                   HeapSort::heapSortOperations),
"Heap sort")},
{12, std::make_pair(std::make_pair(ShellSort::shellSortTime,
                                   ShellSort::shellSortOperations),
"Shell sort")},
{13, std::make_pair(std::make_pair(ShellSort::ciuraSortTime,
                                   ShellSort::ciuraSortOperations),
"Ciura sort")}
};

static std::pair<std::function<void(int*, int)>,
        std::function<int(int*, int)>> getAlgorithm(int choice) {
    return algorithms[choice].first;
}

static std::string getName(int choice) {
    return algorithms[choice].second;
}