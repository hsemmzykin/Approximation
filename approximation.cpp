#include "approximation.hpp"
#include "newton.hpp"

namespace approximation {

std::ostream &operator<<(std::ostream &out, const Points2D &Points2D) {
  for (const auto &pairs : Points2D) {
    out << pairs.first << " " << pairs.second;
  }
  return out;
}
Points2D &&approximate(METHODS method, const Points2D &input) {
  switch (method) {
  case METHODS::NEWTON: {
    Newton algorithm(std::make_shared<Points2D>(input));
    return std::forward<Points2D>(algorithm.newtonApproximation());
  }
  default:
    return std::forward<Points2D>(Points2D());
  }
}
}; // namespace approximation