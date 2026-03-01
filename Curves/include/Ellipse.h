#ifndef ELLIPSE_H
#define ELLIPSE_H
#include <Curve.h>

namespace Curves {

class Ellipse final : public Curve {
public:
    explicit Ellipse(double rx, double ry);

    [[nodiscard]]
    Point3D GetPoint(double t) const noexcept override;

    [[nodiscard]]
    Point3D GetDerivative(double t) const noexcept override;

    [[nodiscard]]
    CurveType GetType() const noexcept override;

private:
    double m_rx;
    double m_ry;
};

}

#endif //ELLIPSE_H
