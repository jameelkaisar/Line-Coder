#include <bits/stdc++.h>

using namespace std;

class Decoder {
   private:
   public:
    Decoder() {
    }

    vector<int> NRZ_L(vector<int> bits) {
        vector<int> result;
        for (auto b: bits) {
            if (b == 1) {
                result.push_back(1);
            } else {
                result.push_back(0);
            }
        }
        return result;
    }

    vector<int> NRZ_I(vector<int> bits) {
        vector<int> result;
        return result;
    }

    vector<int> Manchester(vector<int> bits) {
        vector<int> result;
        return result;
    }

    vector<int> Differential_Manchester(vector<int> bits) {
        vector<int> result;
        return result;
    }

    vector<int> AMI(vector<int> bits) {
        vector<int> result;
        return result;
    }
};
