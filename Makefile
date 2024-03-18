CUNITS = main.cpp newton.cpp approximation.cpp
INCLUDES = newton.hpp approximation.hpp gnuplot.hpp
all: $(CUNITS) $(INCLUDES)
	g++ -std=c++17 -w $(CUNITS) -o main
clean:
	rm main newton 
