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
    // Default locations and their distance matrix
    vector<string> locs = {"Walmart", "Costco", "Tec de Monterrey"};
    vector<vector<double>> d = {
       {0.0, 0.85, 1.8},  // distances from Walmart
        {0.85, 0.0, 1.2},  // distances from Costco
        {1.8, 1.2, 0.0}    // distances from Tec de Monterrey
    };
    Route route(locs, d);

    Vehicle* currentVehicle = nullptr; // no vehicle selected

    while (true) {
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
        cin.ignore();
        if (opt == 0) break;

        switch (opt) {
            case 1: {
                auto all = route.getAllLocations();
                cout << "Locations:\n";
                for (size_t i = 0; i < all.size(); ++i)
                    cout << "  [" << i << "] " << all[i] << "\n";
                break;
            }
            case 2: {
                auto all = route.getAllLocations();
                cout << "Current locations:\n";
                for (size_t i = 0; i < all.size(); ++i)
                    cout << "  [" << i << "] " << all[i] << "\n";

                cout << "Enter new location name (or 'b'): ";
                string name;
                getline(cin, name);
                if (name == "b") break;

                size_t n = route.getNumLocations();
                vector<double> row(n + 1);
                auto names = route.getAllLocations();
                bool cancelled = false;
                for (size_t i = 0; i < n; ++i) {
                    cout << "Distance to " << names[i] << " (km) or 'b': ";
                    string inp; getline(cin, inp);
                    if (inp == "b") { cancelled = true; break; }
                    row[i] = stod(inp);
                }
                if (cancelled) break;
                row[n] = 0.0;
                route.addLocation(name, row);
                break;
            }
            case 3: {
                auto all = route.getAllLocations();
                cout << "Current locations:\n";
                for (size_t i = 0; i < all.size(); ++i)
                    cout << "  [" << i << "] " << all[i] << "\n";

                cout << "Enter index to remove (or 'b'): ";
                string inp; getline(cin, inp);
                if (inp == "b") break;
                size_t idx = stoi(inp);
                if (!route.removeLocation(idx))
                    cout << "Invalid index\n";
                break;
            }
            case 4: {
                auto all = route.getAllLocations();
                cout << "Locations:\n";
                for (size_t i = 0; i < all.size(); ++i)
                    cout << "  [" << i << "] " << all[i] << "\n";

                cout << "Origin index (or 'b'): ";
                string inp; getline(cin, inp);
                if (inp == "b") break;
                size_t i = stoi(inp);

                cout << "Destination index (or 'b'): ";
                getline(cin, inp);
                if (inp == "b") break;
                size_t j = stoi(inp);

                try {
                    cout << "Distance: " << route.getDistance(i, j) << " km\n";
                } catch (...) {
                    cout << "Invalid indices\n";
                }
                break;
            }
            case 5: {
                if (!currentVehicle) {
                    cout << "No vehicle selected. Please change vehicle first.\n";
                    break;
                }
                auto all = route.getAllLocations();
                cout << "Locations:\n";
                for (size_t k = 0; k < all.size(); ++k)
                    cout << "  [" << k << "] " << all[k] << "\n";

                cout << "Origin index (or 'b'): ";
                string inp; getline(cin, inp);
                if (inp == "b") break;
                size_t i = stoi(inp);

                cout << "Destination index (or 'b'): ";
                getline(cin, inp);
                if (inp == "b") break;
                size_t j = stoi(inp);

                double dist = route.getDistance(i, j);
                double minutes = currentVehicle->travelTime(dist, true);
                cout << "Route from " << route.getLocation(i)
                     << " to " << route.getLocation(j)
                     << " by " << *currentVehicle    // operator<<
                     << " takes " << static_cast<int>(minutes)
                     << " min and is " << dist << " km long\n";
                break;
            }
            case 6: {
                delete currentVehicle;
                currentVehicle = nullptr;

                cout << "Select vehicle type (or 'b'): \n"
                     << " 1) Car\n"
                     << " 2) Bicycle\n"
                     << " 3) Truck\n"
                     << " 4) Motorcycle\n"
                     << " 5) Foot\n"
                     << "Choice: ";
                string inp; getline(cin, inp);
                if (inp == "b") break;
                int v = stoi(inp);

                if (v == 5) {
                    currentVehicle = new Foot();
                } else {
                    cout << "Enter brand: ";
                    string brand; getline(cin, brand);
                    cout << "Enter model: ";
                    string model; getline(cin, model);

                    if (v == 1) {
                        cout << "Enter horsepower (CV): ";
                        double hp; cin >> hp; cin.ignore();
                        currentVehicle = new Car(brand, model, hp);
                    } else if (v == 2) {
                        cout << "Has gears? (1=yes 0=no): ";
                        bool gears; cin >> gears; cin.ignore();
                        currentVehicle = new Bicycle(brand, model, gears);
                    } else if (v == 3) {
                        currentVehicle = new Truck(brand, model);
                    } else if (v == 4) {
                        cout << "Enter engine capacity (cc): ";
                        double cc; cin >> cc; cin.ignore();
                        currentVehicle = new Motorcycle(brand, model, cc);
                    } else {
                        cout << "Invalid choice, selecting Foot.\n";
                        currentVehicle = new Foot();
                    }
                }
                cout << "Selected vehicle: " << *currentVehicle << "\n"; // operator<<
                break;
            }
            default:
                cout << "Invalid option\n";
        }
    }

    delete currentVehicle;
    return 0;
}
