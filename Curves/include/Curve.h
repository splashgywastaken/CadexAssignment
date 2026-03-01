#pragma once
#ifndef CURVE_H
#define CURVE_H
#include <map>
#include <string>

namespace Curves {

struct Point3D{
    double x;
    double y;
    double z;
};

enum class CurveType {
  Circle,
  Ellipse,
  Helix
};

inline std::map<CurveType, std::string> curveTypeToString {
        {CurveType::Circle, "Circle"},
        {CurveType::Ellipse, "Ellipse"},
        {CurveType::Helix, "Hellix"},
};
inline std::string enumToString(const CurveType curveType) {
    return curveTypeToString[curveType];
}

class Curve {
public:
    virtual ~Curve() = default;
    virtual Point3D GetPoint(double t) const noexcept = 0;
    virtual Point3D GetDerivative(double t) const noexcept = 0;

    virtual CurveType GetType() const noexcept = 0;

    virtual double GetRadius() const noexcept{
      return 0.0;
    }
};

} // Curves

#endif //CURVE_H
