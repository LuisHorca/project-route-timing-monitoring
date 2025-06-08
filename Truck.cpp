#include "Truck.h"

Truck::Truck(const string& brand, const string& model)
  : Vehicle(brand, model)
{}

double Truck::maxSpeed() const {
    return 80.0; // limited speed for trucks
}
