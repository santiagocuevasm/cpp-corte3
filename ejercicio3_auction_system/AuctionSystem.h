#pragma once
#include <set>
#include <unordered_map>
#include <utility>

using namespace std;

class AuctionSystem {
    unordered_map<int, set<pair<int,int>>> items;      // itemId -> {(monto, userId)} ordenado
    unordered_map<int, unordered_map<int,int>> users;  // userId -> {itemId -> monto}

public:
    AuctionSystem() {
        
    }
    
    void addBid(int userId, int itemId, int bidAmount) {
        if (users[userId].count(itemId)) removeBid(userId, itemId);  // reemplaza la puja anterior
        users[userId][itemId] = bidAmount;
        items[itemId].insert({bidAmount, userId});
    }
    
    void updateBid(int userId, int itemId, int newAmount) {
        int old = users[userId][itemId];
        items[itemId].erase({old, userId});
        items[itemId].insert({newAmount, userId});
        users[userId][itemId] = newAmount;
    }
    
    void removeBid(int userId, int itemId) {
        int old = users[userId][itemId];
        items[itemId].erase({old, userId});
        users[userId].erase(itemId);
    }
    
    int getHighestBidder(int itemId) {
        auto it = items.find(itemId);
        if (it == items.end() || it->second.empty()) return -1;  // sin pujas
        return it->second.rbegin()->second;  // mayor monto; si hay empate, mayor userId
    }
};
