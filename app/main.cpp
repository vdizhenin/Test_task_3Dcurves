#include <iostream>
#include <random>
#include "curves/circle.hpp"
#include "curves/ellipse.hpp"
#include "curves/spiral.hpp"
using namespace std;
using namespace curves;

int main() {
    std::mt19937_64 gen{std::random_device{}()};
    vector<shared_ptr<Curve>> curves;

    uniform_real_distribution<double> radius(0.5, 10);
    uniform_real_distribution<double> step(0.1, 5);
    uniform_int_distribution<int> type(0, 2);

    for (int i = 0; i < 10; i++) {
        switch (type(gen)) {
            case 0:
                curves.emplace_back(make_shared<Circle>(radius(gen)));
                break;
            case 1:
                curves.emplace_back(make_shared<Ellipse>(radius(gen), radius(gen)));
                break;
            case 2:
                curves.emplace_back(make_shared<Spiral>(radius(gen), step(gen)));
                break;
            default:
                break;
        }
    }
    const double t = PI / 4.0;

    for (const auto& c : curves) {
        auto p = c->getPoint(t);
        auto d = c->getDerivative(t);
        auto n = c->getName();
        cout << n << endl;
        cout << "  C(t) = " << p.x << " " << p.y << " " << p.z << endl;
        cout << "  C'(t) = " << d.x << " " << d.y << " " << d.z << endl;
    }

    vector<shared_ptr<Circle>> circles;
    for (const auto& c : curves) {
        if (auto tmp = dynamic_pointer_cast<Circle>(c)) {
            circles.emplace_back(tmp);
        }
    }

    sort(circles.begin(), circles.end(), [](const std::shared_ptr<Circle>& a, const std::shared_ptr<Circle>& b) {
        return a->getRadius() < b->getRadius();
    });

    double sum = 0.0;
    cout << endl;
    for (auto& c : circles) {
        auto n = c->getRadius();
        sum += n;
        cout << n << endl;
    }
    cout << "The total sum of radii of all curves in the second container: " << sum;

    return 0;
}
