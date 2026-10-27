#pragma once
#include <map>
#include <string>
#include <unordered_map>
#include <utility>

using namespace std;

class UndergroundSystem {
    unordered_map<int, pair<string, int>> inTrip;               // id -> (estación, t)
    map<pair<string, string>, pair<long long, int>> acc;        // (origen,destino) -> (suma, conteo)

public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        inTrip[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto it = inTrip.find(id);
        auto& total = acc[{it->second.first, stationName}];
        total.first += t - it->second.second;
        total.second += 1;
        inTrip.erase(it);
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto& total = acc[{startStation, endStation}];
        return (double) total.first / total.second;
    }
};
