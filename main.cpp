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
    // Initialize default locations and their pairwise distances (in km)
    vector<string> locs = {"Walmart", "Costco", "Tec de Monterrey"};
    vector<vector<double>> d = {
        {0.0,  0.85, 1.8},   // distances from Walmart
        {0.85, 0.0,  1.2},   // distances from Costco
        {1.8,  1.2,  0.0}    // distances from Tec de Monterrey
    };
    Route route(locs, d);

    Vehicle* currentVehicle = nullptr; // pointer to the selected vehicle (none yet)

    while (true) {
        // Display menu options
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
        cin.ignore();  // clear newline

        if (opt == 0) {
            // Exit the program
            break;
        }

        switch (opt) {
            case 1: {
                // Option 1: list all current locations
                auto all = route.getAllLocations();
                cout << "Locations:\n";
                for (size_t i = 0; i < all.size(); ++i) {
                    cout << "  [" << i << "] " << all[i] << "\n";
                }
                break;
            }
            case 2: {
                // Option 2: add a new location
                // First, show existing locations
                auto all = route.getAllLocations();
                cout << "Current locations:\n";
                for (size_t i = 0; i < all.size(); ++i) {
                    cout << "  [" << i << "] " << all[i] << "\n";
                }

                // Prompt for new location name or cancel
                cout << "Enter new location name (or 'b' to go back): ";
                string name;
                getline(cin, name);
                if (name == "b") break;

                // Gather distances from new location to each existing one
                size_t n = route.getNumLocations();
                vector<double> row(n + 1);
                auto names = route.getAllLocations();
                bool cancelled = false;
                for (size_t i = 0; i < n; ++i) {
                    cout << "Distance to " << names[i]
                         << " (km) (or 'b' to go back): ";
                    string inp;
                    getline(cin, inp);
                    if (inp == "b") { cancelled = true; break; }
                    row[i] = stod(inp);
                }
                if (cancelled) break;

                // Distance from the new location to itself is zero
                row[n] = 0.0;
                route.addLocation(name, row);
                break;
            }
            case 3: {
                // Option 3: remove an existing location
                auto all = route.getAllLocations();
                cout << "Current locations:\n";
                for (size_t i = 0; i < all.size(); ++i) {
                    cout << "  [" << i << "] " << all[i] << "\n";
                }
                cout << "Enter index to remove (or 'b' to go back): ";
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
                // Option 4: query distance between two locations
                auto all = route.getAllLocations();
                cout << "Locations:\n";
                for (size_t i = 0; i < all.size(); ++i) {
                    cout << "  [" << i << "] " << all[i] << "\n";
                }
                // Prompt for origin
                cout << "Enter origin index (or 'b' to go back): ";
                string inp;
                getline(cin, inp);
                if (inp == "b") break;
                size_t i = stoi(inp);
                // Prompt for destination
                cout << "Enter destination index (or 'b' to go back): ";
                getline(cin, inp);
                if (inp == "b") break;
                size_t j = stoi(inp);
                // Display the distance or error if indices invalid
                try {
                    cout << "Distance: " << route.getDistance(i, j) << " km\n";
                } catch (...) {
                    cout << "Invalid indices\n";
                }
                break;
            }
            case 5: {
                // Option 5: estimate travel time using the selected vehicle
                if (!currentVehicle) {
                    cout << "No vehicle selected. Please change vehicle first.\n";
                    break;
                }
                // Show locations for selection
                auto all = route.getAllLocations();
                cout << "Locations:\n";
                for (size_t k = 0; k < all.size(); ++k) {
                    cout << "  [" << k << "] " << all[k] << "\n";
                }
                // Prompt origin
                cout << "Enter origin index (or 'b' to go back): ";
                string inp;
                getline(cin, inp);
                if (inp == "b") break;
                size_t i = stoi(inp);
                // Prompt destination
                cout << "Enter destination index (or 'b' to go back): ";
                getline(cin, inp);
                if (inp == "b") break;
                size_t j = stoi(inp);
                // Calculate distance and travel time
                double dist    = route.getDistance(i, j);
                double hours   = currentVehicle->travelTime(dist);        // default hours
                double minutes = currentVehicle->travelTime(dist, true);  // overloaded minutes
                // Use operator<< to print vehicle identifier
                cout << "Route from " << route.getLocation(i)
                     << " to " << route.getLocation(j)
                     << " by " << *currentVehicle
                     << " takes " << hours << " h ("
                     << static_cast<int>(minutes)
                     << " min) and is " << dist << " km long\n";
                break;
            }
            case 6: {
                // Option 6: change the current vehicle
                Vehicle* oldVehicle = currentVehicle;
                Vehicle* newVehicle = nullptr;

                cout << "Select vehicle type (or 'b' to go back):\n"
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

                // For Foot, no additional parameters needed
                if (v == 5) {
                    newVehicle = new Foot();
                } else {
                    // Gather common parameters: brand & model
                    cout << "Enter brand (or 'b' to go back): ";
                    string brand; getline(cin, brand);
                    if (brand == "b") { /* cancel */ }
                    else {
                        cout << "Enter model (or 'b' to go back): ";
                        string model; getline(cin, model);
                        if (model == "b") { /* cancel */ }
                        else {
                            // Create the selected subtype, prompting its extra field
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

                // Demonstrate operator==: compare old vs. new vehicle
                if (oldVehicle && newVehicle && *oldVehicle == *newVehicle) {
                    cout << "You selected the same vehicle!\n";
                }

                // Replace the currentVehicle pointer
                delete oldVehicle;
                currentVehicle = newVehicle;

                if (currentVehicle)
                    cout << "Selected vehicle: " << *currentVehicle << "\n";
                break;
            }
            default:
                // Handle invalid menu choices
                cout << "Invalid option\n";
        }
    }

    // Clean up before exit
    delete currentVehicle;
    return 0;
}
