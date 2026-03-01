#ifndef CIRCLE_H
#define CIRCLE_H
#include <Curve.h>

namespace Curves {

class Circle final : public Curve {
public:
    explicit Circle(double radius);

    [[nodiscard]]
    double GetRadius() const noexcept override;

    [[nodiscard]]
    Point3D GetPoint(double t) const noexcept override;

    [[nodiscard]]
    Point3D GetDerivative(double t) const noexcept override;

    [[nodiscard]]
    CurveType GetType() const noexcept override;
private:
    double m_radius;
};

}

#endif //CIRCLE_H
