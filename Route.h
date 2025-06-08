#ifndef ROUTE_H
#define ROUTE_H

#include <string>
#include <vector>
using namespace std;

// Manages locations and their distances
class Route {
private:
    vector<string> locations;
    vector<vector<double>> distances;
public:
    Route(const vector<string>& initialLocations,
          const vector<vector<double>>& initialDistances);

    size_t getNumLocations() const;
    string getLocation(size_t idx) const;
    vector<string> getAllLocations() const;
    double getDistance(size_t i, size_t j) const;

    size_t addLocation(const string& name,
                       const vector<double>& rowDistances);
    bool removeLocation(size_t idx);
};

#endif 
