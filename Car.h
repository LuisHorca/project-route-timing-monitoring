#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"
using namespace std;

// Car subclass of Vehicle
class Car : public Vehicle {
    double horsepower; // engine power in CV
public:
    Car(const string& brand, const string& model, double horsepower);

    string displayInfo() const override;               // info for Car
    double maxSpeed() const override;                  // Car max speed
    double travelTime(double distance) const override; // overridden travelTime

    double fuelConsumptionPerKm() const;               // fuel use per km
    string displayFuelConsumption(double distance) const; // fuel for distance

    bool operator==(const Vehicle& other) const override; // Car equality
};

#endif 
