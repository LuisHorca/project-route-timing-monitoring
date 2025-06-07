#ifndef FOOT_H
#define FOOT_H

#include "Vehicle.h"
using namespace std;

// Foot subclass for walking
class Foot : public Vehicle {
public:
    Foot();
    string displayInfo() const override; // info for Foot
    double maxSpeed() const override;    // walking speed
};

#endif 
