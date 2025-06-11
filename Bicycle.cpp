#include "Bicycle.h"

Bicycle::Bicycle(const string& brand, const string& model, bool gears)
  : Vehicle(brand, model), hasGears(gears)
{}

double Bicycle::maxSpeed() const {
    return hasGears ? 30.0 : 15.0; // top speed for bike with gears and not NOTE: The full speed depends on the weight of the user and the kind of terrain. So this only works as a mean of the 2 types of bikes.
}
