#include <filesystem>
#include <fstream>
#include <iostream>
#include <limits>

#include "approximation.hpp"

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << "\nWRONG NUMBER OF ARGUMENTS\n";
    return EXIT_FAILURE;
  }
  std::filesystem::path inputFile(argv[1]);
  std::ifstream inputData(inputFile);
  approximation::Points2D initialPoints;
  if (inputData.is_open()) {
    while (inputData) {
      double X{std::numeric_limits<double>::max()};
      double Y{std::numeric_limits<double>::max()};
      char comma{'\0'};
      // inputData >> dataFunction;
      inputData >> X >> comma >> Y;
      if (X != std::numeric_limits<double>::max() &&
          Y != std::numeric_limits<double>::max()) {
        initialPoints.emplace_back(X, Y);
      }
    }
    for (const auto &x : initialPoints) {
      std::cout << "INITIAL POINT: " << x.first << " " << x.second << std::endl;
    }
    inputData.close();
  } else {
    std::cerr << "\nERROR OCCURED WHILE OPENING FILE\n";
    return EXIT_FAILURE;
  }

  approximation::Points2D outputApproximation{
      std::move(approximation::approximate(approximation::METHODS::NEWTON,
                                           initialPoints))};
  std::ofstream fout("file.txt");
  if (fout.is_open()) {
    fout << outputApproximation;
    fout.close();
  } else {
    std::cerr << "\nERROR OCCURED WHILE OPENING OUTPUT FILE\n";
    return EXIT_FAILURE;
  }

#ifdef _DEBUG
  std::cout << outputApproximation;
#endif

  return 0;
}