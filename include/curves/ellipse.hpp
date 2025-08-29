#pragma once
#include "curve.hpp"
#include <memory>
#include <stdexcept>

namespace curves {

class Ellipse final : public Curve {
    double x_radius;
    double y_radius; 
public:
    Ellipse(double x, double y);
    point getPoint(double t) const override;
    point getDerivative(double t) const override;
    std::string getName() const override;
};

}
