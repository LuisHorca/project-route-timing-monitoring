#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
using namespace std;

class Vehicle {
protected:
    string brand;
    string model;
    double currentSpeed;
public:
    Vehicle(const string& brand, const string& model);
    virtual ~Vehicle();
    virtual string getIdentifier() const;
    virtual double maxSpeed() const = 0;
    virtual double travelTime(double distance) const;
    virtual void accelerate(double amount);
};

#endif 
