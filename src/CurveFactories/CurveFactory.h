#ifndef CURVEFACTORY_H
#define CURVEFACTORY_H

#include <curves>
#include <memory>
#include <random>

// Base class for curves factories
class CurveFactory {
public:
    virtual ~CurveFactory() = default;
    [[nodiscard("Creates a pointer to new curve")]]
    virtual Curves::Curve* CreateCurve() = 0;
    [[nodiscard("Creates unique pointer to new curve")]]
    virtual std::unique_ptr<Curves::Curve> CreateUniqueCurve() = 0;
protected:
    std::mt19937 m_gen = std::mt19937(std::random_device{}());
};

#endif //CURVEFACTORY_H
