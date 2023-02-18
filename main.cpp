#include <iostream>
#include "Utils/ArrayUtils/SortSelector.cpp"
#include "Utils/InterfaceUtils/ConsoleInputReader.cpp"


int main() {
    std::string loop;
    generateArrays();
    do {
        printAlgorithms();
        int choice = readConsoleInput();
        chooseAlgorithm(choice);
        do {
            std::cout << "\nContinue? (y/n):";
            std::getline(std::cin, loop);
        } while (loop != "y" && loop != "n");
        std::cout << '\n';
    } while (loop == "y");
}
