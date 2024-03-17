#pragma once

#include <ostream>
#include <vector>

namespace approximation {
constexpr double CALCULATION_ERROR{1e-9};
constexpr double CALC_DELTA{1e-3};

enum class METHODS {
  NEWTON,
};
using Point2D = std::pair<double, double>;
using Points2D = std::vector<Point2D>;
using Points = std::vector<double>;

Points2D &&approximate(METHODS method, const Points2D &input);
}; // namespace approximation

std::ostream &operator<<(std::ostream &out,
                         const approximation::Points2D &Points2);