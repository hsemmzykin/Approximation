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

  Points2D &newtonApproximation();

private:
  Points divDiff;
  Points2D resultData;
  std::shared_ptr<Points2D> inputData;
  void calculateDividedDifferences();
  double calculateHorner(double x);
};
}; // namespace approximation