#include "Motorcycle.h"
#include <sstream>

Motorcycle::Motorcycle(const string& brand, const string& model, double ec)
  : Vehicle(brand, model), engineCapacity(ec) {}

string Motorcycle::displayInfo() const {
    // Motorcycle brand/model and cc
    ostringstream oss;
    oss << "Motorcycle: " << brand << " " << model
        << ", " << engineCapacity << " cc";
    return oss.str();
}

double Motorcycle::maxSpeed() const {
    // simple speed formula
    return engineCapacity * 0.05;
}
