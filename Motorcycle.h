#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include "Vehicle.h"
using namespace std;

class Motorcycle : public Vehicle {
    double engineCapacity;
public:
    Motorcycle(const string& brand, const string& model, double engineCapacity);
    string displayInfo() const override;
    double maxSpeed() const override;
};

#endif 
