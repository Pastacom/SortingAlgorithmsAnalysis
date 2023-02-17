//
// Created by User on 17.02.2023.
//

#include <iostream>
#include "../ArrayUtils/SortSelector.cpp"

static void printAlgorithms() {
    for (int i = 1; i < 14; ++i) {
        std::cout << i << ". " + getName(i) << '\n';
    }
    std::cout << "14. Perform all algorithms." << '\n';


}