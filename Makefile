CUNITS = main.cpp newton.cpp approximation.cpp
INCLUDES = newton.hpp approximation.hpp
all: $(CUNITS) $(INCLUDES)
	clang++ -std=c++17 $(CUNITS) -o main