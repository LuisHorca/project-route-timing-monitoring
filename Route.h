#ifndef ROUTE_H
#define ROUTE_H

#include <string>
#include <vector>
using namespace std;

// Manages locations and their pairwise distances
class Route {
private:
    vector<string> locations;
    vector<vector<double>> distances;
public:
    Route(const vector<string>& initialLocations,
          const vector<vector<double>>& initialDistances);

    size_t getNumLocations() const;              // number of locations
    string getLocation(size_t idx) const;        // name at index
    vector<string> getAllLocations() const;      // all names
    double getDistance(size_t i, size_t j) const;// km between i and j

    size_t addLocation(const string& name,
                       const vector<double>& rowDistances); // add new
    bool removeLocation(size_t idx);              // remove by index
};

#endif 

