// main.cpp

#include "file_tape_dev.h"
#include "sorter.h"
#include <iostream>

int main(int argc, char** argv) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <input_file> <output_file>\n";
        return 1;
    }

    std::string inputFileName = argv[1];
    std::string outputFileName = argv[2];

    FileTapeDevice inputTape(inputFileName, outputFileName);
    FileTapeDevice outputTape(outputFileName, outputFileName);

    TapeSorter tapeSorter(inputTape, outputTape);
    tapeSorter.sort();

    std::cout << "Sorting completed. Output written to " << outputFileName << std::endl;

    return 0;
}
