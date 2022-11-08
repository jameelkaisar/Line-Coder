#include <bits/stdc++.h>

using namespace std;

class Generator {
   private:
   public:
    Generator() {
        srand(time(0));
    }

    vector<int> getRandom(int n = 256, int ph = 0) {
        vector<int> result;
        for (int i = 0; i < n; i++) {
            result.push_back(rand() % 2);
        }
        return result;
    }

    vector<int> _getRandomWith(int n, int zeros, int x) {
        vector<int> result;
        int j = rand() % (n - zeros);
        for (int i = 0; i < n; i++) {
            if (i >= j && i < j + zeros)
                result.push_back(x);
            else
                result.push_back(rand() % 2);
        }
        return result;
    }

    vector<int> getRandomWithZeros(int n = 256, int zeros = 4) {
        return _getRandomWith(n, zeros, 0);
    }

    vector<int> getRandomWithOnes(int n = 256, int ones = 4) {
        return _getRandomWith(n, ones, 1);
    }
};
