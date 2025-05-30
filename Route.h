#ifndef ROUTE_H
#define ROUTE_H

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Route {
public:
    static vector<string> getAllOrigins();


    static vector<string> destinationsFrom(const string& origin);


    static double getDistance(const string& origin, const string& destination);

    static bool routeExists(const string& origin, const string& destination);
};

#endif 

