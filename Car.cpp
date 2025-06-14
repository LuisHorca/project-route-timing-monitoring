#include "Car.h"

Car::Car(const string& brand, const string& model, double hp)
  : Vehicle(brand, model), horsepower(hp)
{}

double Car::maxSpeed() const {
    return horsepower * 0.3; // speed mutliplier factor per hp NOTE: it doesnt exist a mult factor, but this works as a prediction value.
}

bool Car::operator==(const Vehicle& other) const {
    if (auto p = dynamic_cast<const Car*>(&other)) {
        return brand == p->brand
            && model == p->model
            && horsepower == p->horsepower;
    }
    return false;
}
