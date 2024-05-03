#include "sorter.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
#include <queue>
#include <sstream>
#include <iomanip>

Sorter::Sorter(int maxMemory, const std::string& tmpDirectory)
    : MAX_MEMORY(maxMemory), tmpDir(tmpDirectory) {}

void Sorter::sort(Tape& inputTape, Tape& outputTape) {
    std::vector<int> values;
    int value;

    // Read 
    while (inputTape.read(value)) {
        values.push_back(value);//Thank you Galowitz 
        if (values.size() * sizeof(int) > static_cast<std::vector<int>::size_type>(MAX_MEMORY)) {
            std::sort(values.begin(), values.end());
            for (int val : values) {
                outputTape.write(val);
            }
            values.clear();
        }
    }

 
    if (!values.empty()) {//if empty (is not C)
        std::sort(values.begin(), values.end());
        for (int val : values) {
            outputTape.write(val);
        }
    }
}
