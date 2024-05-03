#beggining of programm 
TARGET=surmt
CXX=g++
# compiler flags:
#  -g     - this flag adds debugging information to the executable file
#  -Wall  - this flag is used to turn on most compiler warnings
CXXFLAGS= -g -Wall
O= -o
RM= rm

#first target
$(TARGET):  main.o sorter.o file_tape_dev.o
	$(CXX) main.o sorter.o file_tape_dev.o $(O) $(TARGET) $(CXXFLAGS) 

#for main 
main.o: main.cpp 
	$(CXX) -c main.cpp $(O) main.o 

#sorter
sorter.o: sorter.cpp 
	$(CXX) -c sorter.cpp $(O) sorter.o  

#ftd
file_tape_dev.o: file_tape_dev.cpp 
	$(CXX) -c file_tape_dev.cpp  $(O) file_tape_dev.o  

#for clean 
clean:
	$(RM) $(TARGET) *.o 
