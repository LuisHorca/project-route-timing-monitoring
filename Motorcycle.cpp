#include "Motorcycle.h"
#include <sstream>

// Motorcycle constructor
Motorcycle::Motorcycle(const string& brand, const string& model, double ec)
  : Vehicle(brand, model), engineCapacity(ec) {}

// Return descriptive string
string Motorcycle::displayInfo() const {
    ostringstream oss;
    oss << "Motorcycle: " << brand << " " << model
        << ", " << engineCapacity << " cc";
    return oss.str();
}

// Max speed in km/h
double Motorcycle::maxSpeed() const {
    return engineCapacity * 0.05;
}

