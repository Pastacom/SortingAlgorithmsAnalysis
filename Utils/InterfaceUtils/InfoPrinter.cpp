//
// Created by shind_wvnx on 17.02.2023.
//

#include <iostream>
#include "../ArrayUtils/AlgorithmsInfo.cpp"

static void printAlgorithms() {
    for (int i = 1; i < 14; ++i) {
        std::cout << i << ". " + getName(i) << '\n';
    }
    std::cout << "14. Perform all algorithms." << '\n';
}

static void printArrayType(int choice) {
    switch (choice) {
        case 1:
            std::cout << "\nFrom 0 to 5 array\n";
            break;
        case 2:
            std::cout << "\nFrom 0 to 4000 array\n";
            break;
        case 3:
            std::cout << "\nAlmost sorted array\n";
            break;
        case 4:
            std::cout << "\nReversed sorted array\n";
            break;
        default:
            return;
    }
}