#include "Bicycle.h"
#include <sstream>

Bicycle::Bicycle(const string& brand, const string& model, bool gears)
  : Vehicle(brand, model), hasGears(gears), currentGear(1), lightsOn(false) {}

string Bicycle::displayInfo() const {
    // Bicycle brand/model and gear
    ostringstream oss;
    oss << "Bicycle: " << brand << " " << model;
    if (hasGears) oss << ", Gear " << currentGear;
    return oss.str();
}

double Bicycle::maxSpeed() const {
    // speed depends on gears
    return hasGears ? 30.0 : 15.0;
}

void Bicycle::changeGear(int newGear) {
    // valid gear range 1-10
    if (newGear >= 1 && newGear <= 10) currentGear = newGear;
}

bool Bicycle::areLightsOn() const {
    return lightsOn;
}
