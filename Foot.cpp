#include "Foot.h"

// Foot constructor sets generic brand/model
Foot::Foot()
  : Vehicle("Foot", "Walking") {}

// Return descriptive string
string Foot::displayInfo() const {
    return "Walking";
}

// Walking speed in km/h
double Foot::maxSpeed() const {
    return 5.0;
}
