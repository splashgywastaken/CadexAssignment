#include "CircleFactory.h"

CircleFactory::CircleFactory(
    const double radius_min, const double radius_max
) :
    m_radiusDist(radius_min, radius_max) {}

Curves::Curve * CircleFactory::CreateCurve() {
    return new Curves::Circle(m_radiusDist(m_gen));
}

std::unique_ptr<Curves::Curve> CircleFactory::CreateUniqueCurve() {
    return std::make_unique<Curves::Circle>(Curves::Circle(m_radiusDist(m_gen)));
}
