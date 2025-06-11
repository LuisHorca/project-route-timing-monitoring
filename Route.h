#ifndef ROUTE_H
#define ROUTE_H

#include <string>
#include <vector>
using namespace std;

// Manages a list of places and the distances between them
class Route {
private:
    vector<string> locations;           // list of place names
    vector<vector<double>> distances;   // distances[i][j] is km from locations[i] to locations[j]
public:
    Route(const vector<string>& initialLocations,
          const vector<vector<double>>& initialDistances);  // initialize with defaults

    size_t getNumLocations() const;       // how many places we have
    string getLocation(size_t idx) const; // name of the place at index idx
    vector<string> getAllLocations() const; // get all place names
    double getDistance(size_t i, size_t j) const; // km between two indices

    size_t addLocation(const string& name,
                       const vector<double>& rowDistances);  // add a new place with its distances
    bool removeLocation(size_t idx);  // remove the place at idx
};

#endif 
