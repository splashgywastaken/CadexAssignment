#ifndef HELIX_H
#define HELIX_H
#include <Curve.h>

namespace Curves {
class Helix final : public Curve {
public:
    explicit Helix(double radius, double step);

    [[nodiscard]]
    Point3D GetPoint(double t) const noexcept override;

    [[nodiscard]]
    Point3D GetDerivative(double t) const noexcept override;

    [[nodiscard]]
    CurveType GetType() const noexcept override;
private:
    double m_radius;
    double m_step;
};
}

#endif //HELIX_H
