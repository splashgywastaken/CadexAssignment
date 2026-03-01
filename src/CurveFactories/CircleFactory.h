#ifndef CONCRETECURVEFACTORY_H
#define CONCRETECURVEFACTORY_H
#include "CurveFactory.h"

class CircleFactory final : public CurveFactory {
public:
    CircleFactory(double radius_min, double radius_max);

    [[nodiscard("Creates a pointer to new curve")]]
    Curves::Curve* CreateCurve() override;
    [[nodiscard("Creates unique pointer to new curve")]]
    std::unique_ptr<Curves::Curve> CreateUniqueCurve() override;
private:
    std::uniform_real_distribution<> m_radiusDist = std::uniform_real_distribution(1.0, 10.0);
};



#endif //CONCRETECURVEFACTORY_H
