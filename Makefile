# Compiler and flags
CXX = clang++
CXXFLAGS = -std=c++17 -I/opt/homebrew/include
LDFLAGS = -L/opt/homebrew/lib -lsfml-graphics -lsfml-window -lsfml-system

# Output executable
TARGET = main

# Source files
SRCS = main.cpp grid.cpp unit.cpp

# Object files (just change .cpp to .o)
OBJS = $(SRCS:.cpp=.o)

# Default rule
all: $(TARGET)

# Link the object files into the final binary
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET) $(LDFLAGS)

# Compile each .cpp to .o
%.o: %.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)
