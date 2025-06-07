#include <iostream>
#include <vector>
#include <memory>
#include "Route.h"
#include "Car.h"
#include "Bicycle.h"
#include "Truck.h"
#include "Motorcycle.h"
#include "Foot.h"
using namespace std;

int main() {
    vector<string> locs = {"A","B","C"};
    vector<vector<double>> d = {{0,100,200},{100,0,150},{200,150,0}};
    Route route(locs, d);

    while (true) {
        cout << "\nMenu:\n"
             << "1) List locations\n"
             << "2) Add location\n"
             << "3) Remove location\n"
             << "4) Get distance\n"
             << "5) Estimate travel time\n"
             << "0) Exit\n"
             << "Option: ";
        int opt; cin >> opt; cin.ignore();
        if (opt == 0) break;

        switch (opt) {
            case 1: {
                auto all = route.getAllLocations();
                for (size_t i = 0; i < all.size(); ++i)
                    cout << i << ": " << all[i] << "\n";
                break;
            }
            case 2: {
                cout << "Name: ";
                string name; getline(cin,name);
                vector<double> row(route.getNumLocations()+1);
                cout << "Enter distances to existing (and self 0):\n";
                for (size_t i=0;i<row.size();++i) {
                    cout << "d to " << i << ": "; cin >> row[i];
                }
                cin.ignore();
                route.addLocation(name,row);
                break;
            }
            case 3: {
                cout << "Index to remove: ";
                size_t i; cin >> i; cin.ignore();
                if (!route.removeLocation(i)) cout << "Invalid index\n";
                break;
            }
            case 4: {
                cout << "i j: ";
                size_t i,j; cin >> i >> j; cin.ignore();
                try { cout << "Distance: " << route.getDistance(i,j) << "\n"; }
                catch(...) { cout << "Invalid\n"; }
                break;
            }
            case 5: {
                cout << "origin dest: ";
                size_t i,j; cin >> i >> j;
                double dist = route.getDistance(i,j);
                cout << "Select vehicle: 1)Car 2)Bike 3)Truck 4)Moto 5)Foot: ";
                int v; cin >> v; cin.ignore();
                unique_ptr<Vehicle> veh;
                switch(v) {
                    case 1: veh = make_unique<Car>("Toyota","X",150); break;
                    case 2: veh = make_unique<Bicycle>("Trek","Y",true); break;
                    case 3: veh = make_unique<Truck>("Volvo","Z",5); break;
                    case 4: veh = make_unique<Motorcycle>("Yamaha","R",1000); break;
                    default: veh = make_unique<Foot>(); break;
                }
                cout << "Time: " << veh->travelTime(dist) << " h\n";
                break;
            }
            default:
                cout << "Invalid\n";
        }
    }
    return 0;
}
