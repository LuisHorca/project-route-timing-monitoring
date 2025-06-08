#ifndef FOOT_H
#define FOOT_H

#include "Vehicle.h"
using namespace std;

// Foot (walking) with fixed top speed
class Foot : public Vehicle {
public:
    Foot();
    double maxSpeed() const override; // override top speed
};

#endif 
