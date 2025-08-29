#include <iostream>
#include <random>
using namespace std;

const double PI = 3.14159265358979323846;

struct point{
    double x{}, y{}, z{};
};

class Curve{
    public:
        virtual point getPoint(double t) const = 0;
        virtual point getDerivative(double t) const = 0;
        virtual string getName() const = 0;
        virtual ~Curve() = default;
};

class Circle final: public Curve {
    private:
        double radius;

    public:
        explicit Circle(double r) : radius(r) {
            if (radius <= 0) throw invalid_argument("А radius greater than zero is required");
        }

        point getPoint(double t) const override {
            return {radius * cos(t), radius * sin(t), 0.0};
        }

        point getDerivative(double t) const override {
            return {-1 * radius * sin(t), radius * cos(t), 0.0};
        }

        string getName() const override {
            return "Circle";
        }

        double getRadius() {
            return radius;
        }

        ~Circle() = default; 
};

class Ellipse final: public Curve {
    private:
        double x_radius;
        double y_radius; 

    public:
        explicit Ellipse(double x_r, double y_r) : x_radius(x_r), y_radius(y_r) {
            if ((x_radius <= 0) || (y_radius <= 0)) throw invalid_argument("А radius greater than zero is required");
        }

        point getPoint(double t) const override {
            return {x_radius * cos(t), y_radius * sin(t), 0.0};
        }

        point getDerivative(double t) const override {
            return {-1 * x_radius * sin(t), y_radius * cos(t), 0.0};
        }

        string getName() const override {
            return "Ellipse";
        }

        ~Ellipse() = default;
};

class Spiral final: public Curve {
    private:
        double radius;
        double step;

    public:
        explicit Spiral(double r, double s): radius(r), step(s) {
            if (radius <= 0) throw invalid_argument("А radius greater than zero is required");
        }

        point getPoint(double t) const override {
            return {radius * cos(t), radius * sin(t), (step / (2.0 * PI)) * t };
        }

        point getDerivative(double t) const override {
            return {-1 * radius * sin(t), radius * cos(t), step / (2.0 * PI) };
        }

        string getName() const override {
            return "Spiral";
        }

        ~Spiral() = default;
};


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
