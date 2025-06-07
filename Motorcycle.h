#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include "Vehicle.h"
using namespace std;

// Motorcycle subclass
class Motorcycle : public Vehicle {
    double engineCapacity; // in cc
public:
    Motorcycle(const string& brand, const string& model, double engineCapacity);

    string displayInfo() const override; // info for Motorcycle
    double maxSpeed() const override;    // Motorcycle speed
};

#endif 
