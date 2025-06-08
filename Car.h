#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"
using namespace std;

// Car with horsepower-based top speed
class Car : public Vehicle {
    double horsepower;
public:
    Car(const string& brand, const string& model, double horsepower);
    double maxSpeed() const override;
    bool operator==(const Vehicle& other) const override;
};

#endif 
