#include "Car.h"
#include <sstream>

Car::Car(const string& brand, const string& model, double hp)
  : Vehicle(brand, model), horsepower(hp) {}

string Car::displayInfo() const {
    // Car brand/model and power
    return "Car: " + brand + " " + model + ", " + to_string(horsepower) + " CV";
}

double Car::maxSpeed() const {
    // simple formula for max speed
    return horsepower * 0.3;
}

double Car::travelTime(double distance) const {
    // reuse base implementation
    return Vehicle::travelTime(distance);
}

double Car::fuelConsumptionPerKm() const {
    // estimate fuel use
    return horsepower * 0.0005;
}

string Car::displayFuelConsumption(double distance) const {
    // show total fuel use
    ostringstream oss;
    oss << "Fuel: " << fuelConsumptionPerKm() * distance << " L";
    return oss.str();
}

bool Car::operator==(const Vehicle& other) const {
    // compare Car-specific fields
    if (auto p = dynamic_cast<const Car*>(&other)) {
        return brand == p->brand && model == p->model && horsepower == p->horsepower;
    }
    return false;
}
