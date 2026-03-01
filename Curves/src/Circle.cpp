#include "../include/Circle.h"

#include <stdexcept>
#include <cmath>

namespace Curves {

Circle::Circle(const double radius) : m_radius(radius) {
    if (radius <= 0) {
        throw std::invalid_argument("Radius must be positive");
    }
}

double Circle::GetRadius() const noexcept {
    return m_radius;
}

Point3D Circle::GetPoint(const double t) const noexcept {
    return {
        m_radius * std::cos(t),
        m_radius * std::sin(t),
        0.0
    };
}

Point3D Circle::GetDerivative(const double t) const noexcept {
    return {
         - m_radius * std::sin(t),
        m_radius * std::cos(t),
        0.0
    };
}

CurveType Circle::GetType() const noexcept {
    return CurveType::Circle;
}
} // Curves