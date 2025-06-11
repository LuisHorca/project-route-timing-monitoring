
#include "Route.h"
#include <stdexcept>

// Constructor: initialize locations and distance matrix
Route::Route(const vector<string>& initialLocations,
             const vector<vector<double>>& initialDistances)
  : locations(initialLocations)
  , distances(initialDistances)
{}

// Return how many locations are stored
size_t Route::getNumLocations() const {
    return locations.size();
}

// Return the name at the given index or throw if out of range
string Route::getLocation(size_t idx) const {
    if (idx < locations.size())
        return locations[idx];
    throw out_of_range("Index out of range");
}

// Return a copy of all location names
vector<string> Route::getAllLocations() const {
    return locations;
}

// Return the distance between two indices or throw if invalid
double Route::getDistance(size_t i, size_t j) const {
    if (i < distances.size() && j < distances.size())
        return distances[i][j];
    throw out_of_range("Index out of range");
}

// Add a new location with its distances row; throw if row size is wrong
size_t Route::addLocation(const string& name,
                          const vector<double>& rowDistances) {
    size_t n = locations.size();
    if (rowDistances.size() != n + 1)
        throw invalid_argument("Row size must be oldSize+1");
    locations.push_back(name);            // add new name
    distances.push_back(rowDistances);     // add new row
    for (size_t i = 0; i < n; ++i)         // update existing rows
        distances[i].push_back(rowDistances[i]);
    return n;                             // return new index
}

// Remove a location and its distances; return false if index invalid
bool Route::removeLocation(size_t idx) {
    size_t n = locations.size();
    if (idx >= n)
        return false;
    locations.erase(locations.begin() + idx);    // remove name
    distances.erase(distances.begin() + idx);    // remove row
    for (auto& row : distances)                  // remove column
        row.erase(row.begin() + idx);
    return true;
}


