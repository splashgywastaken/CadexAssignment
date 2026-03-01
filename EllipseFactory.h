#ifndef ELLIPSEFACTORY_H
#define ELLIPSEFACTORY_H
#include "CurveFactory.h"

class EllipseFactory final : public CurveFactory {
public:
    EllipseFactory(
        double radiusx_min, double radiusx_max,
        double radiusy_min, double radiusy_max
    );

    [[nodiscard("Creates a pointer to new curve")]]
    Curves::Curve* CreateCurve() override;
    [[nodiscard("Creates unique pointer to new curve")]]
    std::unique_ptr<Curves::Curve> CreateUniqueCurve() override;
private:
    std::uniform_real_distribution<> m_radiusXDist = std::uniform_real_distribution(1.0, 10.0);
    std::uniform_real_distribution<> m_radiusYDist = std::uniform_real_distribution(1.0, 10.0);
};

#endif //ELLIPSEFACTORY_H
