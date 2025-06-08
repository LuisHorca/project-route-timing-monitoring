#include "Motorcycle.h"

Motorcycle::Motorcycle(const string& brand, const string& model, double ec)
  : Vehicle(brand, model), engineCapacity(ec)
{}

double Motorcycle::maxSpeed() const {
    return engineCapacity * 0.05; // km/h
}


