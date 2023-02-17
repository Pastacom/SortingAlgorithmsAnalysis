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
#include "../TimeUtils/TimerGuard.h"
#include "SortChecker.cpp"

static std::map<int, std::pair<std::pair<std::function<void(int*, int)>,
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

static void runAlgorithm(std::pair<std::function<void(int*, int)>,
                                   std::function<int(int*, int)>>& algorithm,
                                   int* original, int size) {
    int *array = new int[size];
    std::copy(original, original+size, array);
    {
        TimerGuard timer("Time for sorting elapsed: ", std::cout);
        algorithm.first(array, size);
    }
    std::cout << "sorted = " << std::boolalpha << isSorted(array, size) << '\n';
    delete[] array;
    array = new int[size];
    std::copy(original, original+size, array);
    std:: cout << "Elementary operations preformed: " << algorithm.second(array, size) << '\n';
    std::cout << "sorted = " << std::boolalpha << isSorted(array, size) << '\n';
    delete[] array;
}

static void chooseAlgorithm(int choice, int* original, int size) {
    std::pair<std::function<void(int*, int)>, std::function<int(int*, int)>> sortingAlgorithm;
    if (choice == 14) {
        for (int i = 1; i <= 13; ++i) {
            std::cout << '\n' << getName(i)  << '\n';
            sortingAlgorithm = getAlgorithm(i);
            runAlgorithm(sortingAlgorithm, original, size);
        }
    } else {
        std::cout << '\n' << getName(choice)  << '\n';
        sortingAlgorithm = getAlgorithm(choice);
        runAlgorithm(sortingAlgorithm, original, size);
    }
}