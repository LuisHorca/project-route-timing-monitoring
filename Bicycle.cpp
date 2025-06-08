#include "Bicycle.h"

Bicycle::Bicycle(const string& brand, const string& model, bool gears)
  : Vehicle(brand, model), hasGears(gears)
{}

double Bicycle::maxSpeed() const {
    return hasGears ? 30.0 : 15.0; // km/h
}
