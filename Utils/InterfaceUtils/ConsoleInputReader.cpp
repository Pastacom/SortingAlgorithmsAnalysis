//
// Created by shind_wvnx on 17.02.2023.
//

#include <string>
#include <iostream>

/**
 * Read numbers from console to launch array sorting.
 * @return user's parsed input
 */
static int readConsoleInput() {
    std::string input;
    int ans;
    do {
        std::cout << "Input number of sorting algorithm:";
        std::getline(std::cin, input);
        try {
            ans = std::stoi(input);
        } catch (std::exception& ex) {
            ans = 0;
        }
        if (ans < 1 || ans > 14) {
            std::cout << "Incorrect input or number of algorithm, try again!\n";
        }
    } while (ans < 1 || ans > 14);
    return ans;
}

