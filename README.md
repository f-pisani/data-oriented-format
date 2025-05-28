# Data Oriented Format (DOF)

A custom serialization format library written in C++ that provides a JSON-like data structure for storing and serializing hierarchical data with typed values.

> **Note:** This is an old hobby project created as a learning exercise. It was originally developed in 2015 using Code::Blocks and has been modernized to use standard build tools.
> 
> To be honest, I don't know what I was doing, just use JSON ffs. 

## Overview

DOF (Data Oriented Format) is a lightweight data serialization library that allows you to:
- Create hierarchical data structures with typed values
- Support for basic types: integers, real numbers (floats), booleans, and strings
- Nest objects within objects
- Serialize data to a human-readable format similar to JSON

## Requirements

- C++11 compatible compiler (g++, clang++)
- Make build tool

## Building the Project

```bash
# Build the project
make

# Build and run
make run

# Clean build artifacts
make clean

# Rebuild from scratch
make rebuild
```

The compiled executable will be placed in the `build/` directory.

## Usage Example

```cpp
#include "Object.hpp"
#include "Value.hpp"

int main() {
    DOF::Object obj;
    
    // Set basic values
    obj.Set("count", DOF::int_v(42));
    obj.Set("pi", DOF::real_v(3.14159f));
    obj.Set("enabled", DOF::bool_v(true));
    obj.Set("name", DOF::string_v("Example"));
    
    // Create nested object
    DOF::Object nested;
    nested.Set("id", DOF::int_v(1));
    obj.Set("nested_data", &nested);
    
    // Serialize to string
    std::cout << obj.Serialize() << std::endl;
    
    return 0;
}
```

## Project Structure

- `Object.hpp/cpp` - Core data container class
- `Value.hpp/cpp` - Generic value wrapper template
- `Lexer.hpp/cpp` - Token definitions for parsing (incomplete)
- `Reader.hpp/cpp` - Placeholder for file reading operations
- `Writer.hpp/cpp` - Placeholder for file writing operations
- `main.cpp` - Example usage
