#include "Car.h"

Car::Car(const string& brand, const string& model, double hp)
  : Vehicle(brand, model), horsepower(hp)
{}

double Car::maxSpeed() const {
    return horsepower * 0.3; // simple formula
}

bool Car::operator==(const Vehicle& other) const {
    if (auto p = dynamic_cast<const Car*>(&other)) {
        return brand == p->brand
            && model == p->model
            && horsepower == p->horsepower;
    }
    return false;
}
