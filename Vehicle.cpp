#include "Vehicle.h"
#include "Route.h"

// Base class constructor
Vehicle::Vehicle(const string& brand, const string& model)
  : brand(brand), model(model), currentSpeed(0.0) {}

Vehicle::~Vehicle() {}

// Returns "brand model"
string Vehicle::getIdentifier() const {
    return brand + " " + model;
}

// Compute travel time (hours) given distance (km)
double Vehicle::travelTime(double distance) const {
    return distance / maxSpeed();
}

// Increase current speed by amount, capped at maxSpeed
void Vehicle::accelerate(double amount) {
    currentSpeed += amount;
    if (currentSpeed > maxSpeed()) currentSpeed = maxSpeed();
}

// Stream-insertion operator uses displayInfo()
ostream& operator<<(ostream& os, const Vehicle& v) {
    os << v.displayInfo();
    return os;
}

// Compare two vehicles by brand and model
bool Vehicle::operator==(const Vehicle& other) const {
    return brand == other.brand && model == other.model;
}

// Order vehicles by brand then model
bool Vehicle::operator<(const Vehicle& other) const {
    if (brand != other.brand) return brand < other.brand;
    return model < other.model;
}

