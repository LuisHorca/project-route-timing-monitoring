#include "Foot.h"

Foot::Foot()
  : Vehicle("Foot", "Walking")
{}

double Foot::maxSpeed() const {
    return 5.0; // mean speed of a human walking
}
