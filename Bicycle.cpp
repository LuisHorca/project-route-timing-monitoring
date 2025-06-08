#include "Bicycle.h"
#include <sstream>

// Bicycle constructor
Bicycle::Bicycle(const string& brand, const string& model, bool gears)
  : Vehicle(brand, model), hasGears(gears), currentGear(1), lightsOn(false) {}

// Return descriptive string
string Bicycle::displayInfo() const {
    ostringstream oss;
    oss << "Bicycle: " << brand << " " << model;
    if (hasGears) oss << ", Gear " << currentGear;
    return oss.str();
}

// Max speed depends on gears
double Bicycle::maxSpeed() const {
    return hasGears ? 30.0 : 15.0;
}

// Change gear within range
void Bicycle::changeGear(int newGear) {
    if (newGear >= 1 && newGear <= 10) currentGear = newGear;
}

// Check if lights are on
bool Bicycle::areLightsOn() const {
    return lightsOn;
}
