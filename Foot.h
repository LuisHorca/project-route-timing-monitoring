#ifndef FOOT_H
#define FOOT_H

#include "Vehicle.h"
using namespace std;

class Foot : public Vehicle {
public:
    Foot();
    string displayInfo() const override;
    double maxSpeed() const override;
};

#endif 

