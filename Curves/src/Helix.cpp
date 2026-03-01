#include "../include/Helix.h"

#include <numbers>
#include <cmath>
#include <stdexcept>

Curves::Helix::Helix(const double radius, const double step)
    : m_radius(radius), m_step(step) {
    if (radius <= 0 || step <= 0) {
        throw std::invalid_argument("radius and/or step must be positive");
    }
}

Curves::Point3D Curves::Helix::GetPoint(const double t) const noexcept {
    return {
        m_radius * std::cos(t),
        m_radius * std::sin(t),
        (m_step / (2.0 * std::numbers::pi) * t)
    };
}

Curves::Point3D Curves::Helix::GetDerivative(const double t) const noexcept {
    return {
        - m_radius * std::sin(t),
        m_radius * std::cos(t),
        (m_step / (2.0 * std::numbers::pi))
    };
}

Curves::CurveType Curves::Helix::GetType() const noexcept {
    return CurveType::Helix;
}


