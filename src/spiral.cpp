#include "curves/spiral.hpp"
#include <cmath>

namespace curves {

Spiral::Spiral(double r, double s) : radius(r), step(s) {
    if (radius <= 0) throw std::invalid_argument("Spiral radius must be > 0");
}

point Spiral::getPoint(double t) const {
    return { radius * std::cos(t), radius * std::sin(t), (step / (2.0 * PI)) * t };
}

point Spiral::getDerivative(double t) const {
    return { -1 * radius * std::sin(t), radius * std::cos(t), step / (2.0 * PI) };
}

std::string Spiral::getName() const { return "Spiral"; }

}
