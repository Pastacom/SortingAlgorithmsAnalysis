//
// Created by shind_wvnx on 16.02.2023.
//

#include <map>
#include <vector>
#include <functional>
#include "../TimeUtils/TimerGuard.h"
#include "ArrayGenerator.cpp"
#include "../InterfaceUtils/InfoPrinter.cpp"
#include "SortChecker.cpp"
#include "../FileUtils/CSVWriter.cpp"

// Average time and operations for different options for first and second iterations.
static std::map<std::string, std::vector<int64_t>> first_iteration;
static std::map<std::string, std::vector<int64_t>> second_iteration;

/**
 * Method to prepare keys in map before putting time and operations
 * @param i array type
 */
static void prepareMaps(int i) {
    for (int j = 1; j < 5; ++j) {
        std::string name = getName(i) + " " + getArrayType(j);
        first_iteration.insert(std::make_pair(name + " Time", std::vector<int64_t>()));
        second_iteration.insert(std::make_pair(name + " Time", std::vector<int64_t>()));
        first_iteration.insert(std::make_pair(name + " Operations", std::vector<int64_t>()));
        second_iteration.insert(std::make_pair(name + " Operations", std::vector<int64_t>()));
    }
}

/**
 * Method to prepare vector sizes in measurements data.
 */

static void prepareSizes() {
    first_iteration.insert(std::make_pair("Array size", std::vector<int64_t>()));
    second_iteration.insert(std::make_pair("Array size", std::vector<int64_t>()));
    for (int i = 50; i <= 300; i += 50) {
        first_iteration["Array size"].push_back(i);
    }
    for (int i = 100; i <= 4100; i += 100) {
        second_iteration["Array size"].push_back(i);
    }
}

/**
 * Method to perform sorting algorithm and register average time and number of operations
 * @param algorithm couple of sorting methods, first is time-efficient and second is for counting operations
 * @param original original array that will be copied and sorted
 * @param size size of given array
 * @param name table name
 * @param flag write to first iteration or second
 */

static void runAlgorithm(std::pair<std::function<void(int*, int)>,
                                   std::function<int(int*, int)>>& algorithm,
                                   int* original, int size, const std::string& name, bool flag) {
    int *array;
    std::chrono::duration<double> total = std::chrono::duration<double>::zero();
    // Averaging sorting time
    for (int i = 0; i < 50; ++i) {
        // Make a copy of array.
        array = new int[size];
        std::copy(original, original+size, array);
        {
            TimerGuard timer(&total);
            // Performing time-efficient algorithm.
            algorithm.first(array, size);
        }
        // TimerGuard destructor triggered and time is added to total value.
        delete[] array;
    }
    // Compute average value.
    int64_t result = std::chrono::duration_cast<std::chrono::nanoseconds>(total / 50.0).count();
    std::cout << "Time for sorting elapsed: " << result << " nanoseconds\n";
    if (flag) {
        first_iteration[name + " Time"].push_back(result);
    } else {
        second_iteration[name + " Time"].push_back(result);
    }
    // Make a copy of array.
    array = new int[size];
    std::copy(original, original+size, array);
    // Performing operation counting algorithm.
    result = algorithm.second(array, size);
    std:: cout << "Elementary operations performed: " << result << '\n';
    if (flag) {
        first_iteration[name + " Operations"].push_back(result);
    } else {
        second_iteration[name + " Operations"].push_back(result);
    }
    // Show if array is sorted.
    std::cout << "sorted = " << std::boolalpha << isSorted(array, size) << '\n';
    delete[] array;
}

/**
 * Method to iterate over different options of array type and size and compute time and operations.
 * @param sortingAlgorithm couple of sorting methods, first is time-efficient and second is for counting operations
 * @param name table name
 */

static void algorithmIterator(std::pair<std::function<void(int*, int)>,
        std::function<int(int*, int)>> sortingAlgorithm , int name) {
    // First iteration
    std::cout << "1.\n";
    for (int i = 50; i <= 300; i += 50) {
        std::cout << "\ncurrent size:" << i << '\n';
        for (int j = 1; j < 5; ++j) {
            std::cout << '\n' + getArrayType(j) + '\n';
            std::string name_to_pass = getName(name) + " " + getArrayType(j);
            runAlgorithm(sortingAlgorithm, chooseArray(j), i, name_to_pass, true);
        }
    }
    // Second iteration
    std::cout << "2.\n";
    for (int i = 100; i <= 4100; i += 100) {
        std::cout << "\ncurrent size:" << i << '\n';
        for (int j = 1; j < 5; ++j) {
            std::cout << '\n' + getArrayType(j) + '\n';
            std::string name_to_pass = getName(name) + " " + getArrayType(j);
            runAlgorithm(sortingAlgorithm, chooseArray(j), i, name_to_pass, false);
        }
    }
}
/**
 * Method to choose algorithms to perform sorting.
 * @param choice user's choice
 */
static void chooseAlgorithm(int choice) {
    std::pair<std::function<void(int*, int)>, std::function<int(int*, int)>> sortingAlgorithm;
    prepareSizes();
    if (choice == 14) {
        // Perform all algorithms.
        for (int i = 1; i <= 13; ++i) {
            std::cout << '\n' << getName(i)  << '\n';
            sortingAlgorithm = getAlgorithm(i);
            prepareMaps(i);
            algorithmIterator(sortingAlgorithm, i);
        }
    } else {
        // Single option.
        std::cout << '\n' << getName(choice)  << '\n';
        sortingAlgorithm = getAlgorithm(choice);
        prepareMaps(choice);
        algorithmIterator(sortingAlgorithm, choice);
    }
    writeToFirstFile(first_iteration);
    writeToSecondFile(second_iteration);
    // Clearing data.
    first_iteration.clear();
    second_iteration.clear();
}