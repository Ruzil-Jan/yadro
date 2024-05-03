#beggining of programm 
TARGET=surmt
CXX=g++
SOURCES= main.cpp sorter.cpp file_tape_dev.cpp
OBJECTS=$(SOURCES:.cpp= .o)
# compiler flags:
#  -g     - this flag adds debugging information to the executable file
#  -Wall  - this flag is used to turn on most compiler warnings
CXXFLAGS= -g -Wall -std=c++20
all:$(TARGET)
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@
clean:
	rm -f $(OBJECTS) $(TARGET)
