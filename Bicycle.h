#ifndef BICYCLE_H
#define BICYCLE_H

#include "Vehicle.h"
using namespace std;

// Bicycle with optional gears affecting top speed
class Bicycle : public Vehicle {
private:
    bool hasGears;
public:
    Bicycle(const string& brand, const string& model, bool hasGears);
    double maxSpeed() const override;
};

#endif 

