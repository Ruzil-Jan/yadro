#beggining of programm 
TARGET=surmt
CXX=g++
SOURCES=main.cpp filetape.cpp sorter.cpp 
OBJECTS=$(SOURCES:.cpp= .o)
#PREFIX=/usr/local/bin
CXXFLAGS= -g -Wall -std=c++11 -Wextra 
# compiler flags:
#  -g     - this flag adds debugging information to the executable file
#  -Wall  - this flag is used to turn on most compiler warnings

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<
	
all: $(TARGET)
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean #директива