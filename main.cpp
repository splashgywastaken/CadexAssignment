#include <iostream>
#include <vector>
#include <memory>
#include <random>
#include <algorithm>
#include <numeric>
#include <numbers>

// Curves library
#include <curves>

#include "CurveFactory.h"
#include "CircleFactory.h"
#include "EllipseFactory.h"
#include "HelixFactory.h"

using namespace Curves;

int main() {
    constexpr double t = std::numbers::pi / 4.0;

    std::vector<std::unique_ptr<Curve>> curves;

    // Random number gen for types
    auto gen = std::mt19937(std::random_device{}());
    auto typeDist = std::uniform_int_distribution(0, 2);
    // Inits for factories for curves
    // Made factories to hide buiseness-logic from here, user only need to pass arguments for curves
    const std::unique_ptr<CurveFactory> circleFactory = std::make_unique<CircleFactory>(CircleFactory(
            1.0, 12.0
        ));
    const std::unique_ptr<CurveFactory> ellipseFactory = std::make_unique<EllipseFactory>(EllipseFactory(
            1.0, 12.0,
            3.0, 10
        ));
    const std::unique_ptr<CurveFactory> helixFactory = std::make_unique<HelixFactory>(HelixFactory(
            1.0, 3.5,
            3.0, 10
        ));

    std::cout << "Number of curves to generate: ";
    size_t count;
    std::cin >> count;
    std::cout << std::endl;

    while (count <= 2) {
        std::cout << "Number of curves should be 3 or greater to have all curves presented" << std::endl;
        std::cout << "Number of curves to generate: ";
        std::cin >> count;
        std::cout << std::endl;
    }

    // Add all curve types to ensure that all curves are presented in container
    curves.push_back(circleFactory->CreateUniqueCurve());
    curves.push_back(ellipseFactory->CreateUniqueCurve());
    curves.push_back(helixFactory->CreateUniqueCurve());

    for (size_t i = 3; i < count; i++) {
        // Add curves using uniform distribution
        switch (typeDist(gen)) {
            case 0:
                curves.push_back(circleFactory->CreateUniqueCurve());
                break;
            case 1:
                curves.push_back(ellipseFactory->CreateUniqueCurve());
                break;
            case 2:
                curves.push_back(helixFactory->CreateUniqueCurve());
                break;
            default:
                throw std::invalid_argument("Got wrong data for CurveType while generating new curve");
        }
    }

    // Print values
    for (const auto& curve : curves) {
        const auto p = curve->GetPoint(t);
        const auto d = curve->GetDerivative(t);
        std::cout.precision(3);
        std::cout << "Curve type: " << enumToString(curve->GetType());
        std::cout << "\tPoint: (" << p.x << "," << p.y << "," << p.z << ") ";
        std::cout << "\tDeriv: (" << d.x << "," << d.y << "," << d.z << ")\n";
    }

    // Get all circles
    std::vector<Circle*> circles;
    for (const auto& curve : curves) {
        if (curve->GetType() == CurveType::Circle) {
            circles.push_back(dynamic_cast<Circle*>(curve.get()));
        }
    }

    // Sort
    std::ranges::sort(circles,
        [](const Circle* a, const Circle* b){
            return a->GetRadius() < b->GetRadius();
        }
    );

    // Sum radii
    const double total =
        std::accumulate(circles.begin(), circles.end(), 0.0,
            [](const double sum, const Circle* c) {
                return sum + c->GetRadius();
            }
        );

    std::cout << "\nTotal circle radii: " << total << "\n";
    return 0;
}