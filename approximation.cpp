#include "approximation.hpp"
//#include "chebyshev.hpp"
#include "newton.hpp"

namespace approximation {

Points2D approximate(METHODS method, Points2D &input) {
  static Points2D Empty;
  switch (method) {
  case METHODS::NEWTON: {
    Newton algorithm = Newton(input);
    return algorithm.newtonApproximation();
  }
  default:
    return Empty;
  }
}
}; // namespace approximation
std::ostream &operator<<(std::ostream &out,
                         const approximation::Points2D &Points2) {
  for (const auto &pairs : Points2) {
    out << pairs.first << ", " << pairs.second << std::endl;
  }
  return out;
}