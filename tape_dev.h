#pragma once
// устройство лента
// чисто виртуальный класс
#include <vector>
#include <string>



class TapeDevice {
public:
    virtual ~TapeDevice() {}

    // Чтение элемента с текущей позиции ленты
    virtual int read() = 0;

    // Запись элемента на текущую позицию ленты
    virtual void write(int value) = 0;

    // Перемотка ленты на начало
    virtual void rewind() = 0;

    // Сдвиг ленты на одну позицию вперед
    virtual void moveForward() = 0;
};


