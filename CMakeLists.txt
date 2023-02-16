cmake_minimum_required(VERSION 3.21)
project(SortingAlgorithmsResearch)

set(CMAKE_CXX_STANDARD 17)

add_executable(SortingAlgorithmsResearch main.cpp algorithms/SelectionSort.cpp algorithms/SelectionSort.h algorithms/BubbleSort.cpp algorithms/BubbleSort.h algorithms/InsertionSort.cpp algorithms/InsertionSort.h algorithms/StableCountingSort.cpp algorithms/StableCountingSort.h algorithms/RadixSort.cpp algorithms/RadixSort.h algorithms/MergeSort.cpp algorithms/MergeSort.h algorithms/HeapSort.cpp algorithms/HeapSort.h algorithms/ShellSort.cpp algorithms/ShellSort.h algorithms/QuickSort.cpp algorithms/QuickSort.h Utils/ArrayUtils/SortSelector.cpp Utils/ArrayUtils/SortChecker.cpp Utils/TimeUtils/TimerGuard.cpp Utils/TimeUtils/TimerGuard.h)
