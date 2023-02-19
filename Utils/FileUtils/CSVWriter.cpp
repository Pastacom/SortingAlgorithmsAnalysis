//
// Created by shind_wvnx on 19.02.2023.
//
#include <map>
#include <string>
#include <vector>
#include <fstream>

/**
 * Write registered data to csv file.
 * @param data average time and operations for different options
 * @param stream stream to csv file to output data
 */
static void writeResults(std::map<std::string, std::vector<int64_t>> data, std::ofstream& stream) {
    for (auto [key, value] : data) {
        stream << key << ';';
    }
    stream << '\n';
    int i = 0;
    while (i < data["Array size"].size()) {
        for (auto [key, value] : data) {
            stream << data[key][i] << ';';
        }
        stream << '\n';
        ++i;
    }

}

static void writeToFirstFile(std::map<std::string, std::vector<int64_t>>& data) {
    std::ofstream file("FirstIteration.csv");
    writeResults(data, file);
    file.close();
}

static void writeToSecondFile(std::map<std::string, std::vector<int64_t>>& data) {
    std::ofstream file("SecondIteration.csv");
    writeResults(data, file);
    file.close();
}