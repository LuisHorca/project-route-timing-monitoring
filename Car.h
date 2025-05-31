#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"
using namespace std;

class Car : public Vehicle {
    double horsepower;
public:
    Car(const string& brand, const string& model, double horsepower);
    string displayInfo() const override;
    double maxSpeed() const override;
    double travelTime(double distance) const override;
    double fuelConsumptionPerKm() const;
    string displayFuelConsumption(double distance) const;
};

#endif 
