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
    // Initialize default locations and their distances (in km) i selected some places near Tec
    vector<string> locs = {"Walmart", "Costco", "Tec de Monterrey"};
    vector<vector<double>> d = {
        {0.0,  0.85, 1.8},  // from Walmart
        {0.85, 0.0,  1.2},  // from Costco
        {1.8,  1.2,  0.0}   // from Tec de Monterrey
    };
    Route route(locs, d);

    Vehicle* currentVehicle = nullptr;  // pointer to the selected vehicle

    while (true) {
        // Display the main menu
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
        cin.ignore();  // consume newline

        if (opt == 0) {
            // Exit the application
            break;
        }

        switch (opt) {
            case 1: {
                // List all stored locations
                auto all = route.getAllLocations();
                cout << "Locations:\n";
                for (size_t i = 0; i < all.size(); ++i) {
                    cout << "  [" << i << "] " << all[i] << "\n";
                }
                break;
            }
            case 2: {
                // Add a new location
                auto all = route.getAllLocations();
                cout << "Current locations:\n";
                for (size_t i = 0; i < all.size(); ++i) {
                    cout << "  [" << i << "] " << all[i] << "\n";
                }

                // Prompt for name or back
                cout << "Enter new location name (or 'b' to go back): ";
                string name;
                getline(cin, name);
                if (name == "b") break;

                // Collect distances to existing locations
                size_t n = route.getNumLocations();
                vector<double> row(n + 1);
                auto names = route.getAllLocations();
                bool canceled = false;
                for (size_t i = 0; i < n; ++i) {
                    cout << "Distance to " << names[i]
                         << " (km) (or 'b'): ";
                    string inp;
                    getline(cin, inp);
                    if (inp == "b") { canceled = true; break; }
                    row[i] = stod(inp);
                }
                if (canceled) break;

                // Distance to itself is zero
                row[n] = 0.0;
                route.addLocation(name, row);
                break;
            }
            case 3: {
                // Remove an existing location
                auto all = route.getAllLocations();
                cout << "Current locations:\n";
                for (size_t i = 0; i < all.size(); ++i) {
                    cout << "  [" << i << "] " << all[i] << "\n";
                }

                // Prompt for index or back
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
                // Query distance between two locations
                auto all = route.getAllLocations();
                cout << "Locations:\n";
                for (size_t i = 0; i < all.size(); ++i) {
                    cout << "  [" << i << "] " << all[i] << "\n";
                }

                // Origin place
                cout << "Enter origin index (or 'b'): ";
                string inp;
                getline(cin, inp);
                if (inp == "b") break;
                size_t i = stoi(inp);

                // Destination place
                cout << "Enter destination index (or 'b'): ";
                getline(cin, inp);
                if (inp == "b") break;
                size_t j = stoi(inp);

                // Display distance or error
                try {
                    cout << "Distance: " << route.getDistance(i, j) << " km\n";
                } catch (...) {
                    cout << "Invalid indices\n";
                }
                break;
            }
            case 5: {
                // Estimate travel time using the current vehicle
                if (!currentVehicle) {
                    cout << "No vehicle selected. Please change vehicle first.\n";
                    break;
                }
                auto all = route.getAllLocations();
                cout << "Locations:\n";
                for (size_t k = 0; k < all.size(); ++k) {
                    cout << "  [" << k << "] " << all[k] << "\n";
                }

                // Origin place index
                cout << "Enter origin index (or 'b'): ";
                string inp;
                getline(cin, inp);
                if (inp == "b") break;
                size_t i = stoi(inp);

                // Destination place index
                cout << "Enter destination index (or 'b'): ";
                getline(cin, inp);
                if (inp == "b") break;
                size_t j = stoi(inp);

                // Calculate distance and time of the route
                double dist    = route.getDistance(i, j);
                double hours   = currentVehicle->travelTime(dist);       // base method
                double minutes = currentVehicle->travelTime(dist, true); // overloaded
                cout << "Route from " << route.getLocation(i)
                     << " to " << route.getLocation(j)
                     << " by " << *currentVehicle      // operator<<
                     << " takes " << hours << " h ("
                     << static_cast<int>(minutes)
                     << " min) and is " << dist << " km long\n";
                break;
            }
            case 6: {
                // Change the current vehicle and demonstrate operator== / operator<
                Vehicle* oldVehicle = currentVehicle;
                Vehicle* newVehicle = nullptr;

                cout << "Select vehicle type (or 'b'): \n"
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

                // Foot has no extra parameters
                if (v == 5) {
                    newVehicle = new Foot();
                } else {
                    // Prompt brand and model
                    cout << "Enter brand (or 'b'): ";
                    string brand; getline(cin, brand);
                    if (brand == "b") { /* cancel */ }
                    else {
                        cout << "Enter model (or 'b'): ";
                        string model; getline(cin, model);
                        if (model == "b") { /* cancel */ }
                        else {
                            // Create chosen subtype
                            if (v == 1) {
                                cout << "Enter horsepower (CV) (or 'b'): ";
                                string inhp; getline(cin, inhp);
                                if (inhp != "b")
                                    newVehicle = new Car(brand, model, stod(inhp));
                            }
                            else if (v == 2) {
                                cout << "Has gears? (1=yes 0=no) (or 'b'): ";
                                string ing; getline(cin, ing);
                                if (ing != "b")
                                    newVehicle = new Bicycle(brand, model, ing == "1");
                            }
                            else if (v == 3) {
                                newVehicle = new Truck(brand, model);
                            }
                            else if (v == 4) {
                                cout << "Enter engine capacity (cc) (or 'b'): ";
                                string incc; getline(cin, incc);
                                if (incc != "b")
                                    newVehicle = new Motorcycle(brand, model, stod(incc));
                            }
                            else {
                                cout << "Invalid choice, selecting Foot.\n";
                                newVehicle = new Foot();
                            }
                        }
                    }
                }

                // Compare old vs new with operator==
                if (oldVehicle && newVehicle && *oldVehicle == *newVehicle) {
                    cout << "You selected the same vehicle!\n";
                }
                // Compare order with operator<
                if (oldVehicle && newVehicle && *oldVehicle < *newVehicle) {
                    cout << *oldVehicle << " sorts before " << *newVehicle << "\n";
                } else if (oldVehicle && newVehicle && *newVehicle < *oldVehicle) {
                    cout << *newVehicle << " sorts before " << *oldVehicle << "\n";
                }

                // Replace the current vehicle
                delete oldVehicle;
                currentVehicle = newVehicle;
                if (currentVehicle)
                    cout << "Selected vehicle: " << *currentVehicle << "\n";
                break;
            }
            default:
                // Handle invalid choices
                cout << "Invalid option\n";
        }
    }

    // Clean up selected vehicle before exit
    delete currentVehicle;
    return 0;
}

