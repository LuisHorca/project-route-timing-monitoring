#include "Foot.h"

Foot::Foot()
  : Vehicle("Foot", "Walking") {}

string Foot::displayInfo() const {
    // simple walking info
    return "Walking";
}

double Foot::maxSpeed() const {
    return 5.0;
}
