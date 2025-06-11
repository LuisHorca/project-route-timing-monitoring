#ifndef FOOT_H
#define FOOT_H

#include "Vehicle.h"
using namespace std;

// Foot (walking) with standard top speed
class Foot : public Vehicle {
public:
    Foot();
    double maxSpeed() const override;
};

#endif 
