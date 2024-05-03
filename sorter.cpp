#include "sorter.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>
#include <queue>
#include <sstream>
#include <iomanip>

ExternalSorter::ExternalSorter(int maxMemory, const std::string& tmpDirectory)
    : MAX_MEMORY(maxMemory), tmpDir(tmpDirectory) {}

void ExternalSorter::sort(Tape& inputTape, Tape& outputTape) {
    std::vector<int> values;
    int value;

    // Чтение значений с входной ленты и сохранение в памяти, учитывая ограничение по памяти
    while (inputTape.read(value)) {
        values.push_back(value);
        if (values.size() * sizeof(int) > static_cast<std::vector<int>::size_type>(MAX_MEMORY)) {
            std::sort(values.begin(), values.end());
            for (int val : values) {
                outputTape.write(val);
            }
            values.clear();
        }
    }

    // Если остались значения в буфере, сортируем и записываем на выходную ленту
    if (!values.empty()) {
        std::sort(values.begin(), values.end());
        for (int val : values) {
            outputTape.write(val);
        }
    }
}
