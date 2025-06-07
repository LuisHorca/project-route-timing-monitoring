#ifndef ROUTE_H
#define ROUTE_H

#include <string>
#include <vector>
using namespace std;

// Manage list of locations and distances
class Route {
private:
    vector<string> locations;           // city names
    vector<vector<double>> distances;   // distance matrix
public:
    Route(const vector<string>& initialLocations,
          const vector<vector<double>>& initialDistances);

    size_t getNumLocations() const;           // count
    string getLocation(size_t idx) const;     // name at index
    vector<string> getAllLocations() const;   // all names
    double getDistance(size_t i, size_t j) const; // from matrix
    vector<double> distancesFrom(size_t i) const; // row data

    size_t addLocation(const string& name, const vector<double>& rowDistances);
    bool removeLocation(size_t idx);
    bool setDistance(size_t i, size_t j, double dist);
};

#endif 

