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

    // Returns the brand and model 
    string getIdentifier() const;

    // As a abstract class it had been to be overrided on the subclasses
    virtual double maxSpeed() const = 0;

    // Calculate travel time in hours
    virtual double travelTime(double distance) const;

    // Overloading the last method creating another that calculate time in min
    double travelTime(double distance, bool inMinutes) const;
//Operator Overloading 
   // operator<< : print vehicle identifier 
    friend ostream& operator<<(ostream& os, const Vehicle& v);

    // operator== : check if two vehicles have the same brand and model
    virtual bool operator==(const Vehicle& other) const;

    // operator< : determine ordering by brand, then model for sorting
    virtual bool operator<(const Vehicle& other) const;

};

#endif 

