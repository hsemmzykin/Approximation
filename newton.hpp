#pragma once
#include "approximation.hpp"
#include <functional>

namespace approximation {
class Newton {
public:
  Newton(Points2D &Points);

  Points2D newtonApproximation();

private:
  void calculateDividedDifferences();
  double calculateHorner(double x);

  const Points2D &input() const;
  Points2D &input();

  Points divDiff;
  std::reference_wrapper<Points2D> inputData;
};
}; // namespace approximation