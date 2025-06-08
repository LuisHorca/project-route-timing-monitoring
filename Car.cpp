#include "Car.h"
#include <sstream>

// Car constructor
Car::Car(const string& brand, const string& model, double hp)
  : Vehicle(brand, model), horsepower(hp) {}

// Return descriptive string
string Car::displayInfo() const {
    return "Car: " + brand + " " + model + ", " + to_string(horsepower) + " CV";
}

// Max speed in km/h
double Car::maxSpeed() const {
    return horsepower * 0.3;
}

// Override travelTime (delegates to base)
double Car::travelTime(double distance) const {
    return Vehicle::travelTime(distance);
}

// Fuel consumption per km
double Car::fuelConsumptionPerKm() const {
    return horsepower * 0.0005;
}

// Return fuel needed for given distance
string Car::displayFuelConsumption(double distance) const {
    ostringstream oss;
    oss << "Fuel: " << fuelConsumptionPerKm() * distance << " L";
    return oss.str();
}

// Equality compares horsepower too
bool Car::operator==(const Vehicle& other) const {
    if (auto p = dynamic_cast<const Car*>(&other)) {
        return brand == p->brand
            && model == p->model
            && horsepower == p->horsepower;
    }
    return false;
}

