#include "Ellipse.h"
#include <stdexcept>
#include <cmath>

namespace Curves {
Ellipse::Ellipse(const double rx, const double ry)
    : m_rx(rx), m_ry(ry) {
    if (rx <= 0.0 || ry <= 0.0) {
        throw std::invalid_argument("Radii must be positive");
    }
}

Point3D Ellipse::GetPoint(const double t) const noexcept {
    return {
        m_rx * std::cos(t),
        m_ry * std::sin(t),
        0.0
    };
}

Point3D Ellipse::GetDerivative(const double t) const noexcept {
    return {
        - m_rx * std::sin(t),
        m_ry * std::cos(t),
        0.0
    };
}

CurveType Ellipse::GetType() const noexcept {
    return CurveType::Ellipse;
}
}
