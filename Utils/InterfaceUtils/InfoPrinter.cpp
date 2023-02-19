//
// Created by shind_wvnx on 17.02.2023.
//

#include <iostream>
#include "../ArrayUtils/AlgorithmsInfo.cpp"

/**
 * Method to output algorithms names.
 */
static void printAlgorithms() {
    for (int i = 1; i < 14; ++i) {
        std::cout << i << ". " + getName(i) << '\n';
    }
    std::cout << "14. Perform all algorithms." << '\n';
}

/**
 * Method to get array type.
 * @param choice type to return
 * @return array type
 */
static std::string getArrayType(int choice) {
    switch (choice) {
        case 1:
            return "From 0 to 5 array";
        case 2:
            return "From 0 to 4000 array";
        case 3:
            return "Almost sorted array";
        case 4:
            return "Reversed sorted array";
        default:
            return "";
    }
}