#include "curves/ellipse.hpp"
#include <cmath>

namespace curves {

Ellipse::Ellipse(double x, double y) : x_radius(x), y_radius(y) {
    if (x_radius <= 0 || y_radius <= 0) throw std::invalid_argument("Ellipse radii must be > 0");
}

point Ellipse::getPoint(double t) const {
    return { x_radius * std::cos(t), y_radius * std::sin(t), 0.0 };
}

point Ellipse::getDerivative(double t) const {
    return { -x_radius * std::sin(t), y_radius * std::cos(t), 0.0 };
}

std::string Ellipse::getName() const { return "Ellipse"; }


}