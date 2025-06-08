#ifndef TRUCK_H
#define TRUCK_H

#include "Vehicle.h"
using namespace std;

// Truck with fixed top speed
class Truck : public Vehicle {
public:
    Truck(const string& brand, const string& model);
    double maxSpeed() const override;
};

#endif 
