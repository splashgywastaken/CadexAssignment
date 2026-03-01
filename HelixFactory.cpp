#include "HelixFactory.h"

HelixFactory::HelixFactory(
    const double step_min, const double step_max,
    const double radius_min, const double radius_max
) :
    m_stepDist(std::uniform_real_distribution(step_min, step_max)),
    m_radiusDist(std::uniform_real_distribution(radius_min, radius_max)) {}

Curves::Curve* HelixFactory::CreateCurve() {
    return new Curves::Helix(
        m_stepDist(m_gen), m_stepDist(m_gen)
    );
}

std::unique_ptr<Curves::Curve> HelixFactory::CreateUniqueCurve() {
    return std::make_unique<Curves::Helix>(Curves::Helix(
        m_stepDist(m_gen), m_stepDist(m_gen)
    ));
}
