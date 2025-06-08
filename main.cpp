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
    // Default locations and distances
    vector<string> locs = {"Walmart", "Costco", "Tec de Monterrey"};
    vector<vector<double>> d = {
        {0.0, 10.5, 25.0}, // from walmart
        {10.5, 0.0, 30.0}, // from Costco
        {25.0, 30.0, 0.0} // from Tec 
    };
    Route route(locs, d);

    Vehicle* currentVehicle = nullptr; // No vehicle selected

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

        if (opt == 0) {
            break;
        }

        switch (opt) {
            case 1: {
                // List locations
                auto all = route.getAllLocations();
                cout << "Locations:\n";
                for (size_t i = 0; i < all.size(); ++i)
                    cout << "  [" << i << "] " << all[i] << "\n";
                break;
            }
            case 2: {
                // Show before adding
                auto all = route.getAllLocations();
                cout << "Current locations:\n";
                for (size_t i = 0; i < all.size(); ++i)
                    cout << "  [" << i << "] " << all[i] << "\n";

                // Add new
                cout << "Enter new location name: ";
                string name;
                getline(cin, name);

                size_t n = route.getNumLocations();
                vector<double> row(n + 1);
                auto names = route.getAllLocations();
                for (size_t i = 0; i < n; ++i) {
                    cout << "Distance to " << names[i] << ": ";
                    cin >> row[i];
                }
                row[n] = 0.0; // to itself
                cin.ignore();
                route.addLocation(name, row);
                break;
            }
            case 3: {
                // Show before removing
                auto all = route.getAllLocations();
                cout << "Current locations:\n";
                for (size_t i = 0; i < all.size(); ++i)
                    cout << "  [" << i << "] " << all[i] << "\n";

                cout << "Enter index to remove: ";
                size_t idx;
                cin >> idx;
                cin.ignore();
                if (!route.removeLocation(idx))
                    cout << "Invalid index\n";
                break;
            }
            case 4: {
                // Show before querying
                auto all = route.getAllLocations();
                cout << "Locations:\n";
                for (size_t i = 0; i < all.size(); ++i)
                    cout << "  [" << i << "] " << all[i] << "\n";

                cout << "Origin index: ";
                size_t i, j;
                cin >> i;
                cout << "Destination index: ";
                cin >> j;
                cin.ignore();
                try {
                    cout << "Distance: " << route.getDistance(i, j) << " km\n";
                } catch (...) {
                    cout << "Invalid indices\n";
                }
                break;
            }
            case 5: {
                // Estimate travel time
                if (!currentVehicle) {
                    cout << "No vehicle selected. Please change vehicle first.\n";
                    break;
                }
                auto all = route.getAllLocations();
                cout << "Locations:\n";
                for (size_t k = 0; k < all.size(); ++k)
                    cout << "  [" << k << "] " << all[k] << "\n";

                cout << "Origin index: ";
                size_t i, j;
                cin >> i;
                cout << "Destination index: ";
                cin >> j;
                cin.ignore();

                double dist = route.getDistance(i, j);
                double minutes = currentVehicle->travelTime(dist) * 60;
                cout << "Route from " << route.getLocation(i)
                     << " to " << route.getLocation(j)
                     << " by " << currentVehicle->getIdentifier()
                     << " takes " << static_cast<int>(minutes)
                     << " min and is " << dist << " km long\n";
                break;
            }
            case 6: {
                // Change vehicle
                delete currentVehicle;
                currentVehicle = nullptr;

                cout << "Select vehicle type:\n"
                     << " 1) Car\n"
                     << " 2) Bicycle\n"
                     << " 3) Truck\n"
                     << " 4) Motorcycle\n"
                     << " 5) Foot\n"
                     << "Choice: ";
                int v;
                cin >> v;
                cin.ignore();

                // Prompt for common fields
                cout << "Brand: ";
                string brand;
                getline(cin, brand);
                cout << "Model: ";
                string model;
                getline(cin, model);

                // Prompt for specific attribute
                switch (v) {
                    case 1: {
                        cout << "Horsepower (CV): ";
                        double hp;
                        cin >> hp;
                        cin.ignore();
                        currentVehicle = new Car(brand, model, hp);
                        break;
                    }
                    case 2: {
                        cout << "Has gears? (1=yes 0=no): ";
                        bool gears;
                        cin >> gears;
                        cin.ignore();
                        currentVehicle = new Bicycle(brand, model, gears);
                        break;
                    }
                    case 3: {
                        cout << "Capacity (tons): ";
                        double cap;
                        cin >> cap;
                        cin.ignore();
                        currentVehicle = new Truck(brand, model, cap);
                        break;
                    }
                    case 4: {
                        cout << "Engine capacity (cc): ";
                        double cc;
                        cin >> cc;
                        cin.ignore();
                        currentVehicle = new Motorcycle(brand, model, cc);
                        break;
                    }
                    default: {
                        currentVehicle = new Foot();
                        break;
                    }
                }
                cout << "Selected vehicle: " << currentVehicle->getIdentifier() << "\n";
                break;
            }
            default:
                cout << "Invalid option\n";
        }
    }

    delete currentVehicle;
    return 0;
}
