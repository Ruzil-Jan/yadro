# компилятор
CXX = g++
# флаги
CXXFLAGS = -Wall -Wextra -std=c++11

# суррогоатный mt
TARGET = smt

# исходники
SRCS = main.cpp filetape.cpp sorter.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(OBJS:.o=.d)
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<
-include $(DEPS)

clean:
	rm -f $(OBJS) $(DEPS) $(TARGET)
.PHONY: all clean
