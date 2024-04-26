// file_tape_device.h
#ifndef FILE_TAPE_DEVICE_H
#define FILE_TAPE_DEVICE_H

#include "tape_dev.h"
#include <fstream>

class FileTapeDevice : public TapeDevice {
private:
    std::ifstream inputFile;
    std::ofstream outputFile;

public:
    FileTapeDevice(const std::string& inputFileName, const std::string& outputFileName);
    ~FileTapeDevice();

    int read() override;
    void write(int value) override;
    void rewind() override;
    void moveForward() override;
};
#endif