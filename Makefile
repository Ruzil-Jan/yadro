#beggining of programm 
TARGET = surmt
CC = g++

#some text 
SORCE = $(wildcarrd *.cpp)
NAMES = &(patsubmit %.cpp,  %.o, $(SOURCE))

#first target
$(TARGET) :  main.o sorter.o file_tape_dev.o
$(CC) main.o sorter.o file_tape_dev.o -o $(TARGET)

#for main 
main.o : main.cpp 
$(CC) -c main.cpp -o main.o

#sorter
sorter.o : sorter.cpp 
$(CC) -c sorter.cpp -o sorter.o

#ftd
file_tape_dev.o : file_tape_dev.cpp 
$(CC) -c file_tape_dev.cpp  -o file_tape_dev.o

#for clean 
clean :
rm $(TARGET) *.o 

