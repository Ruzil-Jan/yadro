#include "filetape.h"

FileTape::FileTape(const std::string& inputFilename, const std::string& outputFilename)
    : input(inputFilename), output(outputFilename), inputFilename(inputFilename), outputFilename(outputFilename) {}

FileTape::~FileTape() {
    input.close();
    output.close();
}

bool FileTape::read(int& value) {
    if (input >> value) {
        return true;
    }
    return false;
}

void FileTape::write(int value) {
    output << value << std::endl;
}

void FileTape::Forward() {}



bool FileTape::isEnd() const {
    return input.eof();
}

void FileTape::rewind() {
    input.clear();
    input.seekg(0, std::ios::beg);
}
