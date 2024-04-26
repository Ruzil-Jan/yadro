// tape_sorter
#include "sorter.h"
#include <vector>
#include <algorithm>
TapeSorter::~TapeSorter() {}

void TapeSorter::sort() {
    std::vector<int> buffer;

    // Чтение данных с входной ленты и сохранение во временный буфер
    inputTape->rewind();
    int value;
    while ((value = inputTape->read()) != EOF) {
        buffer.push_back(value);
    }

    // Сортировка буфера
    std::sort(buffer.begin(), buffer.end());

    // Запись отсортированных данных на выходную ленту
    for (int val : buffer) {
        outputTape->write(val);
    }
}
