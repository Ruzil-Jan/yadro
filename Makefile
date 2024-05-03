#beggining of programm 
TARGET = surmt
CC = g++
# compiler flags:
#  -g     - this flag adds debugging information to the executable file
#  -Wall  - this flag is used to turn on most compiler warnings
FLAGS = -g -Wall
O = -o
RM = rm
#some text 
NAMES = &(patsubmit %.cpp,  %.o, $(SOURCE))

#first target
$(TARGET) :  main.o sorter.o file_tape_dev.o
$(CC) main.o sorter.o file_tape_dev.o $(O) $(TARGET) $(FLAGS) 

#for main 
main.o : main.cpp 
$(CC) -c main.cpp $(O) main.o $(FLAGS) 

#sorter
sorter.o : sorter.cpp 
$(CC) -c sorter.cpp $(O) sorter.o $(FLAGS) 

#ftd
file_tape_dev.o : file_tape_dev.cpp 
$(CC) -c file_tape_dev.cpp  $(O) file_tape_dev.o $(FLAGS) 

#for clean 
clean :
$(RM) $(TARGET) *.o 

