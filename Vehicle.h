#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <ostream>
using namespace std;

// Base class for all vehicles
class Vehicle {
protected:
    string brand;        // vehicle brand
    string model;        // vehicle model
    double currentSpeed; // current speed in km/h
public:
    Vehicle(const string& brand, const string& model);
    virtual ~Vehicle();

    virtual string getIdentifier() const;          // returns brand + model
    virtual string displayInfo() const = 0;        // basic info string
    virtual double maxSpeed() const = 0;           // max possible speed
    virtual double travelTime(double distance) const; // compute travel time
    virtual void accelerate(double amount);        // increase current speed

    friend ostream& operator<<(ostream& os, const Vehicle& v); // print info
    virtual bool operator==(const Vehicle& other) const;       // compare by id
    virtual bool operator<(const Vehicle& other) const;        // order by id
};

#endif 
