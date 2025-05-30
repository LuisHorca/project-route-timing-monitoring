#ifndef TRUCK_H
#define TRUCK_H

#include "Vehicle.h"
using namespace std;

class Truck : public Vehicle {
    double capacity;
    double currentLoad;
public:
    Truck(const string& brand, const string& model, double capacity);
    double maxSpeed() const override;
    bool canLoad(double weight) const;
    void load(double weight);
    void unload(double weight);
};

#endif 
