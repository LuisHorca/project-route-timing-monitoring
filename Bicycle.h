#ifndef BICYCLE_H
#define BICYCLE_H

#include "Vehicle.h"
using namespace std;

class Bicycle : public Vehicle {
    bool hasGears;
    int currentGear;
    bool lightsOn;
public:
    Bicycle(const string& brand, const string& model, bool hasGears);
    string displayInfo() const override;
    double maxSpeed() const override;
    void changeGear(int newGear);
    bool areLightsOn() const;
};

#endif 
