#include "Vehicle.h"
#include "Route.h"

Vehicle::Vehicle(const string& brand, const string& model)
  : brand(brand), model(model), currentSpeed(0.0) {}

Vehicle::~Vehicle() {}

string Vehicle::getIdentifier() const {
    // Combine brand and model
    return brand + " " + model;
}

double Vehicle::travelTime(double distance) const {
    // time = distance / speed
    return distance / maxSpeed();
}

void Vehicle::accelerate(double amount) {
    // increase speed but not above max
    currentSpeed += amount;
    if (currentSpeed > maxSpeed()) currentSpeed = maxSpeed();
}

ostream& operator<<(ostream& os, const Vehicle& v) {
    // use displayInfo for output
    os << v.displayInfo();
    return os;
}

bool Vehicle::operator==(const Vehicle& other) const {
    // equal if same brand and model
    return brand == other.brand && model == other.model;
}

bool Vehicle::operator<(const Vehicle& other) const {
    // compare by brand then model
    if (brand != other.brand) return brand < other.brand;
    return model < other.model;
}

