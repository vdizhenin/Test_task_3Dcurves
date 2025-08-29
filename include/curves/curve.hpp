#pragma once
#include <string>

#define PI 3.14159265358979323846

namespace curves {

struct point {
    double x{}, y{}, z{};
};

class Curve {
public:
    virtual point getPoint(double t) const = 0;
    virtual point getDerivative(double t) const = 0;
    virtual std::string getName() const = 0;
    virtual ~Curve() = default;
};


}