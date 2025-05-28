# Data Oriented Format - Makefile
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g
LDFLAGS = 

# Source files
SOURCES = main.cpp Object.cpp Value.cpp Lexer.cpp Reader.cpp Writer.cpp
OBJECTS = $(SOURCES:%.cpp=build/%.o)
EXECUTABLE = build/dof

# Default target
all: $(EXECUTABLE)

# Build executable
$(EXECUTABLE): $(OBJECTS)
	@mkdir -p build
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $@

# Build object files
build/%.o: %.cpp
	@mkdir -p build
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the program
run: $(EXECUTABLE)
	./$(EXECUTABLE)

# Clean build artifacts
clean:
	rm -rf build/

# Rebuild everything
rebuild: clean all

.PHONY: all clean rebuild run