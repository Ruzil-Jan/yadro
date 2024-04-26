// file_tape_device.cpp

#include "file_tape_dev.h"

FileTapeDevice::FileTapeDevice(const std::string& inputFileName, const std::string& outputFileName) {
    inputFile.open(inputFileName, std::ios::binary);
    outputFile.open(outputFileName, std::ios::binary | std::ios::trunc);
}

FileTapeDevice::~FileTapeDevice() {
    inputFile.close();
    outputFile.close();
}

int FileTapeDevice::read() {
    int value;
    inputFile.read(reinterpret_cast<char*>(&value), sizeof(int));
    return value;
}

void FileTapeDevice::write(int value) {
    outputFile.write(reinterpret_cast<const char*>(&value), sizeof(int));
}

void FileTapeDevice::rewind() {
    inputFile.seekg(0, std::ios::beg);
}

void FileTapeDevice::moveForward() {
    inputFile.seekg(sizeof(int), std::ios::cur);
}
