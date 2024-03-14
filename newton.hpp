#pragma once
#include "approximation.hpp"
#include <memory>

namespace approximation {
class Newton {
public:
  Newton(std::shared_ptr<Points2D> sortedPoints);
  Newton() = delete;
  Newton(const Newton &) = delete;
  Newton &operator=(const Newton &) = delete;
  Newton &operator=(Newton &&) = delete;
  Newton(Newton &&) = delete;

  Points &&newtonApproximation();

private:
  Points divDiff;
  std::shared_ptr<Points2D> inputData;
  inline double dividedDifference(const Point2D &ith, const Point2D &jth);
  Points &&calculateDividedDifferences(const Points2D &sortedPoints);
  double calculateHorner(double x, const Points &differences,
                         const Points2D &sortedPoints);
};
}; // namespace approximation