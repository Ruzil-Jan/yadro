#ifndef TAPE_H
#define TAPE_H
// устройство лента
#include <vector>
#include <string>
#include <fstream>

class Tape {
public:
    virtual ~Tape() {}
    virtual bool read(int& value) = 0;
    virtual void write(int value) = 0;
    virtual void Forward() = 0;
    virtual bool isEnd() const = 0;
    virtual void rewind() = 0;
};
#endif


