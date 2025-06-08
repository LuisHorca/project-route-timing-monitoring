#include "Vehicle.h"

Vehicle::Vehicle(const string& brand, const string& model)
  : brand(brand), model(model)
{}

Vehicle::~Vehicle() {}

string Vehicle::getIdentifier() const {
    return brand + " " + model;
}

double Vehicle::travelTime(double distance) const {
    return distance / maxSpeed();
}

double Vehicle::travelTime(double distance, bool inMinutes) const {
    double hours = travelTime(distance);
    return inMinutes ? hours * 60.0 : hours;
}

ostream& operator<<(ostream& os, const Vehicle& v) {
    os << v.getIdentifier();
    return os;
}

bool Vehicle::operator==(const Vehicle& other) const {
    return brand == other.brand && model == other.model;
}

bool Vehicle::operator<(const Vehicle& other) const {
    if (brand != other.brand) return brand < other.brand;
    return model < other.model;
}
