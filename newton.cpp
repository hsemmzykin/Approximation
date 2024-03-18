#include "newton.hpp"
#include <algorithm>
#include <stdexcept>
#ifdef _DEBUG
#include <iostream>
#endif
/* TODO:
1. Write calculateHorner method DONE
2. fix calculatedDividedDifferences DONE
3. in approximation fix 2 methods in cpp file na ya
*/
namespace approximation {

Newton::Newton(Points2D &Points) : inputData(Points) {
  if (Points.empty()) {
    throw std::invalid_argument("ERROR WITH DATA FILE! NOT ENOUGH POINTS!");
  }
  std::sort(input().begin(), input().end(),
            [](const Point2D &A, const Point2D &B) -> bool {
              return B.first - A.first > CALCULATION_ERROR;
            });
  for (std::size_t i = 1; i < input().size(); ++i)
    if (std::abs(input()[i].first - input()[i - 1].first) < CALCULATION_ERROR) {
      throw std::invalid_argument(
          "EXPECTED CORRECT FUNCTION. CORRECT INPUT DATA BEFOREHAND");
    }
}

Points2D Newton::newtonApproximation() {
  Points2D resultData;
  if (divDiff.empty()) {
    calculateDividedDifferences();
    for (auto x{input().front().first}; x <= input().back().first - CALC_DELTA;
         x += CALC_DELTA) {
      resultData.emplace_back(x, calculateHorner(x));
    }
#ifdef _DEBUG
    std::cout << calculateHorner(x);
    std::cout << std::endl;
#endif
  }
  return resultData;
}

void Newton::calculateDividedDifferences() {
  const auto n{input().size()};
  divDiff.resize(n);
  std::vector<std::vector<double>> dividedDifferences(
      n, std::vector<double>(n, 0.0));
  for (std::size_t i{0}; i < n; ++i) {
    dividedDifferences[i][0] = input()[i].second;
  }
  for (std::size_t i{1}; i < n; ++i) {
    for (std::size_t j{1}; j <= i; ++j) {
      dividedDifferences[i][j] =
          (dividedDifferences[i][j - 1] - dividedDifferences[i - 1][j - 1]) /
          (input()[i].first - input()[i - j].first);
    }
  }
  for (std::size_t i{0}; i < n; ++i) {
    divDiff[i] = dividedDifferences[i][i];
  }
}

double Newton::calculateHorner(double x) {
  double result = divDiff.back();
  const int64_t size = divDiff.size();
  for (int64_t i = size - 2; i >= 0; --i) {
    result *= (x - input()[i].first);
    result += divDiff[i];
  }
#ifdef _DEBUG
  std::cout << x << " : " << result;
#endif
  return result;
}

const Points2D &Newton::input() const { return inputData; }

Points2D &Newton::input() { return inputData; }

}; // namespace approximation