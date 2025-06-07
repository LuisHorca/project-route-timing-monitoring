#ifndef TRUCK_H
#define TRUCK_H

#include "Vehicle.h"
using namespace std;

// Truck subclass
class Truck : public Vehicle {
    double capacity;    // max load in tons
    double currentLoad; // current cargo
public:
    Truck(const string& brand, const string& model, double capacity);

    string displayInfo() const override; // info for Truck
    double maxSpeed() const override;    // Truck speed

    bool canLoad(double weight) const;   // check capacity
    void load(double weight);            // add cargo
    void unload(double weight);          // remove cargo
};

#endif 
