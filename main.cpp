#include <iostream>
#include <vector>
#include "Route.h"
#include "Car.h"
#include "Bicycle.h"
#include "Truck.h"
#include "Motorcycle.h"
#include "Foot.h"
using namespace std;

int main() {
    // Set up default places and how far apart they are (in km)
    vector<string> locs = {"Walmart", "Costco", "Tec de Monterrey"};
    vector<vector<double>> d = {
        {0.0,  0.85, 1.8},   // distances from Walmart to [Walmart, Costco, Tec]
        {0.85, 0.0,  1.2},   // distances from Costco
        {1.8,  1.2,  0.0}    // distances from Tec de Monterrey
    };
    Route route(locs, d);

    Vehicle* currentVehicle = nullptr;  // start with no vehicle chosen

    while (true) {
        // Show the user what they can do
        cout << "\nMenu:\n"
             << "1) List locations\n"
             << "2) Add location\n"
             << "3) Remove location\n"
             << "4) Get distance\n"
             << "5) Estimate travel time\n"
             << "6) Change vehicle\n"
             << "0) Exit\n"
             << "Option: ";
        int opt;
        cin >> opt;
        cin.ignore();  // consume the newline

        if (opt == 0) {
            // exit sequence 
            break;
        }

        switch (opt) {
            case 1: {
                // List all current locations
                auto all = route.getAllLocations();
                cout << "Locations:\n";
                for (size_t i = 0; i < all.size(); ++i) {
                    cout << "  [" << i << "] " << all[i] << "\n";
                }
                break;
            }
            case 2: {
                // Add a new location: show old ones first
                auto all = route.getAllLocations();
                cout << "Current locations:\n";
                for (size_t i = 0; i < all.size(); ++i) {
                    cout << "  [" << i << "] " << all[i] << "\n";
                }

                // ask for the new place name
                cout << "Enter new location name (or 'b' to go back): ";
                string name;
                getline(cin, name);
                if (name == "b") break;

                // ask distances to each existing place
                size_t n = route.getNumLocations();
                vector<double> row(n + 1);
                auto names = route.getAllLocations();
                bool cancel = false;
                for (size_t i = 0; i < n; ++i) {
                    cout << "Distance to " << names[i]
                         << " in km (or 'b'): ";
                    string inp;
                    getline(cin, inp);
                    if (inp == "b") { cancel = true; break; }
                    row[i] = stod(inp);
                }
                if (cancel) break;

                // distance to itself is zero
                row[n] = 0.0;
                route.addLocation(name, row);
                break;
            }
            case 3: {
                // Remove a location: show list first
                auto all = route.getAllLocations();
                cout << "Current locations:\n";
                for (size_t i = 0; i < all.size(); ++i) {
                    cout << "  [" << i << "] " << all[i] << "\n";
                }
                cout << "Enter index to remove (or 'b'): ";
                string inp;
                getline(cin, inp);
                if (inp == "b") break;
                size_t idx = stoi(inp);
                if (!route.removeLocation(idx)) {
                    cout << "Invalid index\n";
                }
                break;
            }
            case 4: {
                // Get distance between two places
                auto all = route.getAllLocations();
                cout << "Locations:\n";
                for (size_t i = 0; i < all.size(); ++i) {
                    cout << "  [" << i << "] " << all[i] << "\n";
                }

                cout << "Enter origin index (or 'b'): ";
                string inp;
                getline(cin, inp);
                if (inp == "b") break;
                size_t i = stoi(inp);

                cout << "Enter destination index (or 'b'): ";
                getline(cin, inp);
                if (inp == "b") break;
                size_t j = stoi(inp);

                double dist = route.getDistance(i, j);
                if (dist < 0) {
                    cout << "Invalid indices\n";
                } else {
                    cout << "Distance between " << route.getLocation(i)
                         << " and " << route.getLocation(j)
                         << " is " << dist << " km\n";
                }
                break;
            }
            case 5: {
                // Estimate how long it takes with the current vehicle
                if (!currentVehicle) {
                    cout << "No vehicle selected. Please change vehicle first.\n";
                    break;
                }
                auto all = route.getAllLocations();
                cout << "Locations:\n";
                for (size_t k = 0; k < all.size(); ++k) {
                    cout << "  [" << k << "] " << all[k] << "\n";
                }

                cout << "Enter origin index (or 'b'): ";
                string inp;
                getline(cin, inp);
                if (inp == "b") break;
                size_t i = stoi(inp);

                cout << "Enter destination index (or 'b'): ";
                getline(cin, inp);
                if (inp == "b") break;
                size_t j = stoi(inp);

                // compute distance and time
                double dist    = route.getDistance(i, j);
                double hours   = currentVehicle->travelTime(dist);        // hours
                double minutes = currentVehicle->travelTime(dist, true);  // minutes
                cout << "Route from " << route.getLocation(i)
                     << " to " << route.getLocation(j)
                     << " by " << *currentVehicle
                     << " takes " << hours << " h ("
                     << static_cast<int>(minutes)
                     << " min) and is " << dist << " km long\n";
                break;
            }
            case 6: {
                // Change vehicle type
                Vehicle* oldVehicle = currentVehicle;
                Vehicle* newVehicle = nullptr;

                cout << "Select vehicle (or 'b'): \n"
                     << " 1) Car\n"
                     << " 2) Bicycle\n"
                     << " 3) Truck\n"
                     << " 4) Motorcycle\n"
                     << " 5) Foot\n"
                     << "Choice: ";
                string inp;
                getline(cin, inp);
                if (inp == "b") break;
                int v = stoi(inp);

                if (v == 5) {
                    newVehicle = new Foot();  // walking
                } else {
                    // ask brand/model or back out
                    cout << "Enter brand (or 'b'): ";
                    string brand; getline(cin, brand);
                    if (brand == "b") break;
                    cout << "Enter model (or 'b'): ";
                    string model; getline(cin, model);
                    if (model == "b") break;

                    if (v == 1) {
                        // Car: ask horsepower
                        cout << "Enter horsepower (CV) (or 'b'): ";
                        string inhp; getline(cin, inhp);
                        if (inhp != "b") newVehicle = new Car(brand, model, stod(inhp));
                    }
                    else if (v == 2) {
                        // Bicycle: ask if has gears
                        cout << "Has gears? (1=yes 0=no) (or 'b'): ";
                        string ing; getline(cin, ing);
                        if (ing != "b") newVehicle = new Bicycle(brand, model, ing == "1");
                    }
                    else if (v == 3) {
                        // Truck has no extra data
                        newVehicle = new Truck(brand, model);
                    }
                    else if (v == 4) {
                        // Motorcycle: ask engine capacity
                        cout << "Enter engine capacity (cc) (or 'b'): ";
                        string incc; getline(cin, incc);
                        if (incc != "b") newVehicle = new Motorcycle(brand, model, stod(incc));
                    }
                    else {
                        cout << "Invalid choice, selecting Foot.\n";
                        newVehicle = new Foot();
                    }
                }

                // operator==: check if same
                if (oldVehicle && newVehicle && *oldVehicle == *newVehicle) {
                    cout << "You selected the same vehicle!\n";
                }
                // operator<: show which sorts first
                if (oldVehicle && newVehicle && *oldVehicle < *newVehicle) {
                    cout << *oldVehicle << " comes before " << *newVehicle << "\n";
                } else if (oldVehicle && newVehicle && *newVehicle < *oldVehicle) {
                    cout << *newVehicle << " comes before " << *oldVehicle << "\n";
                }

                delete oldVehicle;
                currentVehicle = newVehicle;
                if (currentVehicle) {
                    cout << "Selected vehicle: " << *currentVehicle << "\n";
                }
                break;
            }
            default:
                // handle wrong menu choice
                cout << "Invalid option\n";
        }
    }

    // cleanup
    delete currentVehicle;
    return 0;
}
