#pragma once
#include "curve.hpp"
#include <memory>
#include <stdexcept>

namespace curves {

class Circle final : public Curve {
    double radius;
public:
    explicit Circle(double r);
    point getPoint(double t) const override;
    point getDerivative(double t) const override;
    std::string getName() const override;
    double getRadius() const;
};

}
