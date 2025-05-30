#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"
using namespace std;

class Car : public Vehicle {
    double horsepower;
public:
    Car(const string& brand, const string& model, double horsepower);
    double maxSpeed() const override;
    double fuelConsumptionPerKm() const;
    double travelTime(double distance) const override;
};

#endif 
