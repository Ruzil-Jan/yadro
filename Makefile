# компилятор
CXX = g++
# флаги
CXXFLAGS = -Wall -Wextra -std=c++11
# суррогоатный mt
TARGET = smt
# исходники
SRCS = main.cpp filetape.cpp sorter.cpp
OBJS = $(SRCS:.cpp=.o)
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(TARGET)	
clear:
	rm -rf $(OBJS)
	
.PHONY: all clean clear
