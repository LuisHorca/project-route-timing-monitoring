#include "Route.h"
#include <stdexcept>

// Constructor with initial names and distances
Route::Route(const vector<string>& initialLocations,
             const vector<vector<double>>& initialDistances)
  : locations(initialLocations), distances(initialDistances) {}

// Number of locations
size_t Route::getNumLocations() const {
    return locations.size();
}

// Get name by index
string Route::getLocation(size_t idx) const {
    if (idx < locations.size()) return locations[idx];
    throw out_of_range("Index out of range");
}

// Return copy of all names
vector<string> Route::getAllLocations() const {
    return locations;
}

// Lookup distance between two indices
double Route::getDistance(size_t i, size_t j) const {
    if (i < distances.size() && j < distances.size())
        return distances[i][j];
    throw out_of_range("Index out of range");
}

// Return one row of distances
vector<double> Route::distancesFrom(size_t i) const {
    if (i < distances.size()) return distances[i];
    throw out_of_range("Index out of range");
}

// Add new location with its distance row
size_t Route::addLocation(const string& name,
                          const vector<double>& rowDistances) {
    size_t n = locations.size();
    if (rowDistances.size() != n + 1)
        throw invalid_argument("Row size must be oldSize+1");
    locations.push_back(name);
    distances.push_back(rowDistances);
    for (size_t i = 0; i < n; ++i) {
        distances[i].push_back(rowDistances[i]);
    }
    return n;
}

// Remove location and its row/column
bool Route::removeLocation(size_t idx) {
    size_t n = locations.size();
    if (idx >= n) return false;
    locations.erase(locations.begin() + idx);
    distances.erase(distances.begin() + idx);
    for (auto& row : distances) {
        row.erase(row.begin() + idx);
    }
    return true;
}

// Update symmetric distance
bool Route::setDistance(size_t i, size_t j, double dist) {
    size_t n = locations.size();
    if (i < n && j < n) {
        distances[i][j] = dist;
        distances[j][i] = dist;
        return true;
    }
    return false;
}
