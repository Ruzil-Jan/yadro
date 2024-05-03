// tape_sorter.h
#ifndef SORTER_H
#define SORTER_H

#include "tape.h"
#include <string>

class ExternalSorter {
private:
    const int MAX_MEMORY;     // Максимальный объем памяти для работы
    const std::string tmpDir; // Директория для временных файлов

public:
    ExternalSorter(int maxMemory, const std::string& tmpDirectory);

    void sort(Tape& inputTape, Tape& outputTape);
};

#endif // SORTER_H

