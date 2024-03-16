#include "newton.hpp"
#include <algorithm>
#include <iostream>
#include <stdexcept>
/* TODO:
1. Write calculateHorner method DONE
2. fix calculatedDividedDifferences DONE
3. in approximation fix 2 methods in cpp file na ya
*/
namespace approximation {

Newton::Newton(std::shared_ptr<Points2D> sortedPoints) {
  if (sortedPoints->empty()) {
    throw std::invalid_argument("ERROR WITH DATA FILE! NOT ENOUGH POINTS!");
  }
  this->inputData = sortedPoints;
  std::sort(this->inputData->begin(), this->inputData->end(),
            [](const Point2D &A, const Point2D &B) -> bool {
              return B.first - A.first > CALCULATION_ERROR;
            });
  for (std::size_t i = 1; i < this->inputData->size(); ++i)
    if (std::abs((*this->inputData)[i].first -
                 (*this->inputData)[i - 1].first) < CALCULATION_ERROR) {
      throw std::invalid_argument(
          "EXPECTED CORRECT FUNCTION. CORRECT INPUT DATA BEFOREHAND");
    }
}

void Newton::calculateDividedDifferences() {
  const auto n{this->inputData->size()};
  this->divDiff.resize(n);
  std::vector<std::vector<double>> dividedDifferences(
      n, std::vector<double>(n, 0.0));
  for (std::size_t i{0}; i < n; ++i) {
    dividedDifferences[i][0] = (*this->inputData)[i].second;
  }
  for (std::size_t i{1}; i < n; ++i) {
    for (std::size_t j{1}; j <= i; ++j) {
      dividedDifferences[i][j] =
          (dividedDifferences[i][j - 1] - dividedDifferences[i - 1][j - 1]) /
          ((*this->inputData)[i].first - (*this->inputData)[i - j].first);
    }
  }
  for (std::size_t i{0}; i < n; ++i) {
    this->divDiff[i] = dividedDifferences[i][i];
  }
}

double Newton::calculateHorner(double x) {
  double result{this->divDiff.back()};
  const auto size{this->divDiff.size()};
  if (size > 1) {
    for (std::size_t i{size - 2}; i > 0; --i) {
      result *= (x - (*this->inputData)[i].first);
      result += this->divDiff[i];
    }
    result *= (x - (*this->inputData)[0].first);
    result += this->divDiff[0];
  }
#ifdef _DEBUG
  std::cout << x << " : " << result;
#endif
  return result;
}

Points2D &Newton::newtonApproximation() {
  if (this->divDiff.empty()) {
    this->calculateDividedDifferences();
  }
  for (auto x{this->inputData->front().first};
       x <= this->inputData->back().first; x += CALC_DELTA) {
    this->resultData.emplace_back(x, this->calculateHorner(x));
#ifdef _DEBUG
    std::cout << this->calculateHorner(x);
    std::cout << std::endl;
#endif
  }
  return this->resultData;
}
}; // namespace approximation