#pragma once
#include <algorithm>
#include <vector>

using namespace std;

class ATM {
    long long cnt[5] = {0, 0, 0, 0, 0};          // billetes de 20, 50, 100, 200, 500
    const int val[5] = {20, 50, 100, 200, 500};  // valor de cada denominación

public:
    ATM() {
        
    }
    
    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < 5; ++i) cnt[i] += banknotesCount[i];
    }
    
    vector<int> withdraw(int amount) {
        vector<int> used(5, 0);
        long long rest = amount;

        // De la denominación mayor a la menor, tomando todos los billetes posibles
        for (int i = 4; i >= 0; --i) {
            long long take = min(cnt[i], rest / val[i]);
            used[i] = (int) take;
            rest -= take * val[i];
        }

        if (rest != 0) return {-1};  // no se pudo completar: no se toca nada

        for (int i = 0; i < 5; ++i) cnt[i] -= used[i];
        return used;
    }
};
