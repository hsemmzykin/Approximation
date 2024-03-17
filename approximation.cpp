#include "approximation.hpp"
#include "newton.hpp"
#include <memory>

namespace approximation {

Points2D &&approximate(METHODS method, const Points2D &input) {
  switch (method) {
  case METHODS::NEWTON: {
    // Newton *algorithm = new Newton(std::make_shared<Points2D>(input));
    auto algo = std::make_unique<Newton>(std::make_shared<Points2D>(input));
    return std::forward<Points2D>(algo->newtonApproximation());
  }
  default:
    return std::forward<Points2D>(Points2D());
  }
}
}; // namespace approximation
std::ostream &operator<<(std::ostream &out,
                         const approximation::Points2D &Points2) {
  for (const auto &pairs : Points2) {
    out << pairs.first << "," << pairs.second << std::endl;
  }
  return out;
}