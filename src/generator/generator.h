#include <bits/stdc++.h>

using namespace std;

class Generator {
   private:
   public:
    Generator() {
    }

    vector<int> getRandom(int n = 256) {
        vector<int> result;
        return result;
    }

    vector<int> _getRandomWith(int n, int zeros, int x) {
        vector<int> result;
        return result;
    }

    vector<int> getRandomWithZeros(int n = 256, int zeros = 4) {
        return _getRandomWith(n, zeros, 0);
    }

    vector<int> getRandomWithOnes(int n = 256, int ones = 4) {
        return _getRandomWith(n, ones, 1);
    }
};
