#include "Motorcycle.h"

Motorcycle::Motorcycle(const string& brand, const string& model, double ec)
  : Vehicle(brand, model), engineCapacity(ec)
{}

double Motorcycle::maxSpeed() const {
    return engineCapacity * 0.05; // speed multiplier factor per cc NOTE: There not exist a mult factor but this works as a prediction.
}



