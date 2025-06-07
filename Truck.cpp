#include "Truck.h"
#include <sstream>

Truck::Truck(const string& brand, const string& model, double cap)
  : Vehicle(brand, model), capacity(cap), currentLoad(0.0) {}

string Truck::displayInfo() const {
    // Truck brand/model and load
    ostringstream oss;
    oss << "Truck: " << brand << " " << model
        << ", Load " << currentLoad << "/" << capacity << " t";
    return oss.str();
}

double Truck::maxSpeed() const {
    // speed drops if heavily loaded
    return 80.0 - currentLoad * 2.0;
}

bool Truck::canLoad(double weight) const {
    return currentLoad + weight <= capacity;
}

void Truck::load(double weight) {
    if (canLoad(weight)) currentLoad += weight;
}

void Truck::unload(double weight) {
    if (weight <= currentLoad) currentLoad -= weight;
}
