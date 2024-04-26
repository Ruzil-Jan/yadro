// tape_sorter.h
#ifndef SORTER_H
#define SORTER_H
#include "tape_dev.h"

class TapeSorter {
private:
    TapeDevice* inputTape;
    TapeDevice* outputTape;

public:
    TapeSorter(TapeDevice& inputTape, TapeDevice& outputTape);
    ~TapeSorter();

    void sort();
};
#endif
