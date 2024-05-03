#ifndef FILETAPE_H
#define FILETAPE_H

#include "tape.h"
#include <fstream>
#include <string>

class FileTape : public Tape {

public:
    FileTape(const std::string& inputFilename, const std::string& outputFilename);
    ~FileTape();

    bool read(int& value) override;
    void write(int value) override;
    void Forward() override;
    bool isEnd() const override;
    void rewind() override;

private:
    std::ifstream input;
    std::ofstream output;
    std::string inputFilename;
    std::string outputFilename;
};

#endif // FILETAPE_H
