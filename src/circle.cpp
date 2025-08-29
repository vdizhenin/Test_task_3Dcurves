#include "curves/circle.hpp"
#include <cmath>

namespace curves {

Circle::Circle(double r) : radius(r) {
    if (radius <= 0) throw std::invalid_argument("Circle radius must be > 0");
}

point Circle::getPoint(double t) const {
    return { radius * std::cos(t), radius * std::sin(t), 0.0 };
}

point Circle::getDerivative(double t) const {
    return { -1 * radius * std::sin(t), radius * std::cos(t), 0.0 };
}

std::string Circle::getName() const { return "Circle"; }

double Circle::getRadius() const { return radius; }

}
