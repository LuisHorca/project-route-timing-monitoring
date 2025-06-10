#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include "Vehicle.h"
using namespace std;

// Motorcycle with engine capacity-based speed
class Motorcycle : public Vehicle {
private:
    double engineCapacity;
public:
    Motorcycle(const string& brand, const string& model, double engineCapacity);
    double maxSpeed() const override;
};

#endif 
