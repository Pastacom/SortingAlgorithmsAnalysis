/*
 *  АиСД-2, 2023, задание 5
 *  ФИО: Шиндяпкин Илья Дмитриевич
 *  ГРУППА: БПИ219
 *  Среда разработки: CLion, 2021.3.4
 *  Сделано: реализованы различные алгоритмы сортировки, для подсчета времени и количества операций,
 *  реализована проверка на отсортированность массива, есть возможность запустить любую сортировку или все сразу,
 *  произведены вычисления, результаты записаны в csv файлы, построены графики, написан отчет.
 *  Не сделано: не прокомментированы все методы сортировок.
 * */


#include <iostream>
#include "Utils/ArrayUtils/SortSelector.cpp"
#include "Utils/InterfaceUtils/ConsoleInputReader.cpp"


int main() {
    std::string loop;
    do {
        // Generate arrays for sorting.
        generateArrays();
        printAlgorithms();
        // Choose sorting algorithm.
        int choice = readConsoleInput();
        chooseAlgorithm(choice);
        // Program loop.
        do {
            std::cout << "\nContinue? (y/n):";
            std::getline(std::cin, loop);
        } while (loop != "y" && loop != "n");
        std::cout << '\n';
    } while (loop == "y");
    // Delete arrays from heap.
    clearMemory();
}
