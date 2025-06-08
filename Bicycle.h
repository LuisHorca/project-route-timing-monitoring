#ifndef BICYCLE_H
#define BICYCLE_H

#include "Vehicle.h"
using namespace std;

// Bicycle subclass
class Bicycle : public Vehicle {
    bool hasGears;    // true if multi-gear
    int currentGear;  // gear number
    bool lightsOn;    // headlight status
public:
    Bicycle(const string& brand, const string& model, bool hasGears);

    string displayInfo() const override; // info for Bicycle
    double maxSpeed() const override;    // Bicycle speed

    void changeGear(int newGear);        // shift gear
    bool areLightsOn() const;            // check lights
};

#endif 
