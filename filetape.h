#ifndef FILETAPE_H
#define FILETAPE_H

#include "tape.h"
#include <fstream>
#include <string>

class FileTape : public Tape {

public:
    FileTape(const std::string& inputFilename, const std::string& outputFilename);
    ~FileTape();

    bool read(int& value) override;//чтение на магнитофоне 
    void write(int value) override;//запись на магнитофоне 
    void Forward() override;//перемотка 
    bool isEnd() const override;//конец 
    void rewind() override;//перемотка 

private://поля для файлов и пути 
    std::ifstream input;
    std::ofstream output;
    std::string inputFilename;
    std::string outputFilename;
};

#endif // FILETAPE_H
