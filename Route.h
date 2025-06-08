#ifndef ROUTE_H
#define ROUTE_H

#include <string>
#include <vector>
using namespace std;

// Manages list of locations and distances
class Route {
private:
    vector<string> locations;         // city names
    vector<vector<double>> distances; // distances[i][j] = km between
public:
    Route(const vector<string>& initialLocations,
          const vector<vector<double>>& initialDistances);

    size_t getNumLocations() const;            // number of locations
    string getLocation(size_t idx) const;      // name at index
    vector<string> getAllLocations() const;    // all names
    double getDistance(size_t i, size_t j) const; // lookup distance
    vector<double> distancesFrom(size_t i) const;  // row data

    size_t addLocation(const string& name,
                       const vector<double>& rowDistances); // add new
    bool removeLocation(size_t idx);                // remove by index
    bool setDistance(size_t i, size_t j, double dist); // update both
};

#endif 
