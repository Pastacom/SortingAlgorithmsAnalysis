//
// Created by shind_wvnx on 16.02.2023.
//

#include <map>
#include <functional>
#include "../TimeUtils/TimerGuard.h"
#include "ArrayGenerator.cpp"
#include "../InterfaceUtils/InfoPrinter.cpp"
#include "SortChecker.cpp"



static void runAlgorithm(std::pair<std::function<void(int*, int)>,
                                   std::function<int(int*, int)>>& algorithm,
                                   int* original, int size) {
    int *array;
    std::chrono::duration<double> total = std::chrono::duration<double>::zero();
    for (int i = 0; i < 50; ++i) {
        array = new int[size];
        std::copy(original, original+size, array);
        {
            TimerGuard timer(&total);
            algorithm.first(array, size);
        }
    }
    std::cout << "Time for sorting elapsed: " <<
    std::chrono::duration_cast<std::chrono::nanoseconds>(total / 50.0).count() << " nanoseconds\n";
    std::cout << "sorted = " << std::boolalpha << isSorted(array, size) << '\n';
    delete[] array;
    array = new int[size];
    std::copy(original, original+size, array);
    std:: cout << "Elementary operations performed: " << algorithm.second(array, size) << '\n';
    std::cout << "sorted = " << std::boolalpha << isSorted(array, size) << '\n';
    delete[] array;
}

static void algorithmIterator(std::pair<std::function<void(int*, int)>,
        std::function<int(int*, int)>> sortingAlgorithm) {
    std::cout << "1.\n";
    for (int i = 50; i <= 300; i += 50) {
        std::cout << "\ncurrent size:" << i << '\n';
        for (int j = 1; j < 5; ++j) {
            printArrayType(j);
            runAlgorithm(sortingAlgorithm, chooseArray(j), i);
        }
    }
    std::cout << "2.\n";
    for (int i = 100; i <= 4100; i += 100) {
        std::cout << "\ncurrent size:" << i << '\n';
        for (int j = 1; j < 5; ++j) {
            printArrayType(j);
            runAlgorithm(sortingAlgorithm, chooseArray(j), i);
        }
    }
}

static void chooseAlgorithm(int choice) {
    std::pair<std::function<void(int*, int)>, std::function<int(int*, int)>> sortingAlgorithm;
    if (choice == 14) {
        for (int i = 1; i <= 13; ++i) {
            std::cout << '\n' << getName(i)  << '\n';
            sortingAlgorithm = getAlgorithm(i);
            algorithmIterator(sortingAlgorithm);
        }
    } else {
        std::cout << '\n' << getName(choice)  << '\n';
        sortingAlgorithm = getAlgorithm(choice);
        algorithmIterator(sortingAlgorithm);
    }
}