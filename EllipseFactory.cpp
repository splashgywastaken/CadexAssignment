#include "EllipseFactory.h"

EllipseFactory::EllipseFactory(
    const double radiusx_min, const double radiusx_max,
    const double radiusy_min, const double radiusy_max
) :
    m_radiusXDist(std::uniform_real_distribution(radiusx_min, radiusx_max)),
    m_radiusYDist(std::uniform_real_distribution(radiusy_min, radiusy_max)) {}

Curves::Curve* EllipseFactory::CreateCurve() {
    return new Curves::Ellipse(
        m_radiusXDist(m_gen), m_radiusYDist(m_gen)
    );
}

std::unique_ptr<Curves::Curve> EllipseFactory::CreateUniqueCurve() {
    return std::make_unique<Curves::Ellipse>(Curves::Ellipse(
        m_radiusXDist(m_gen), m_radiusYDist(m_gen)
    ));
}
