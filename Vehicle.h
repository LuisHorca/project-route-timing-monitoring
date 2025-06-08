#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <ostream>
using namespace std;

// Abstract base class for all vehicles
class Vehicle {
protected:
    string brand;
    string model;
public:
    Vehicle(const string& brand, const string& model);
    virtual ~Vehicle();

    // Returns "brand model"
    string getIdentifier() const;

    // Must be overridden by each subclass
    virtual double maxSpeed() const = 0;

    // Compute travel time in hours
    virtual double travelTime(double distance) const;

    // Overloaded: compute travel time in hours or minutes
    double travelTime(double distance, bool inMinutes) const;

    // Operator overloads
    friend ostream& operator<<(ostream& os, const Vehicle& v);
    virtual bool operator==(const Vehicle& other) const;
    virtual bool operator<(const Vehicle& other) const;
};

#endif 

