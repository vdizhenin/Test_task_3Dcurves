#pragma once
#include "curve.hpp"
#include <memory>
#include <stdexcept>

namespace curves {

class Spiral final : public Curve {
    double radius, step;
public:
    Spiral(double r, double s);
    point getPoint(double t) const override;
    point getDerivative(double t) const override;
    std::string getName() const override;
};

}
