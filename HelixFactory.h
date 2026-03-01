#ifndef HELIXFACTORY_H
#define HELIXFACTORY_H
#include "CurveFactory.h"

class HelixFactory final : public CurveFactory {
public:
    HelixFactory() = default;
    HelixFactory(
        double step_min, double step_max,
        double radius_min, double radius_max
    );

    [[nodiscard("Creates a pointer to new curve")]]
    Curves::Curve* CreateCurve() override;
    [[nodiscard("Creates unique pointer to new curve")]]
    std::unique_ptr<Curves::Curve> CreateUniqueCurve() override;

private:
    std::uniform_real_distribution<> m_stepDist = std::uniform_real_distribution(1.0, 5.0);
    std::uniform_real_distribution<> m_radiusDist = std::uniform_real_distribution(1.0, 10.0);
};

#endif //HELIXFACTORY_H
