#include "Truck.h"
#include <sstream>

// Truck constructor
Truck::Truck(const string& brand, const string& model, double cap)
  : Vehicle(brand, model), capacity(cap), currentLoad(0.0) {}

// Return descriptive string
string Truck::displayInfo() const {
    ostringstream oss;
    oss << "Truck: " << brand << " " << model
        << ", Load " << currentLoad << "/" << capacity << " t";
    return oss.str();
}

// Max speed decreases with load
double Truck::maxSpeed() const {
    return 80.0 - currentLoad * 2.0;
}

// Can we load additional weight?
bool Truck::canLoad(double weight) const {
    return currentLoad + weight <= capacity;
}

// Add cargo if possible
void Truck::load(double weight) {
    if (canLoad(weight)) currentLoad += weight;
}

// Remove cargo if available
void Truck::unload(double weight) {
    if (weight <= currentLoad) currentLoad -= weight;
}
