cmake_minimum_required(VERSION 3.21)
project(SortingAlgorithmsResearch)

set(CMAKE_CXX_STANDARD 17)

add_executable(SortingAlgorithmsResearch main.cpp Algorithms/SelectionSort.cpp Algorithms/SelectionSort.h Algorithms/BubbleSort.cpp Algorithms/BubbleSort.h Algorithms/InsertionSort.cpp Algorithms/InsertionSort.h Algorithms/StableCountingSort.cpp Algorithms/StableCountingSort.h Algorithms/RadixSort.cpp Algorithms/RadixSort.h Algorithms/MergeSort.cpp Algorithms/MergeSort.h Algorithms/HeapSort.cpp Algorithms/HeapSort.h Algorithms/ShellSort.cpp Algorithms/ShellSort.h Algorithms/QuickSort.cpp Algorithms/QuickSort.h Utils/ArrayUtils/SortSelector.cpp Utils/ArrayUtils/SortChecker.cpp Utils/TimeUtils/TimerGuard.cpp Utils/TimeUtils/TimerGuard.h Utils/ArrayUtils/ArrayGenerator.cpp Utils/InterfaceUtils/ConsoleInputReader.cpp Utils/InterfaceUtils/InfoPrinter.cpp Utils/ArrayUtils/AlgorithmsInfo.cpp)
