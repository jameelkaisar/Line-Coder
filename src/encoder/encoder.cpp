#include "encoder.h"

#include <bits/stdc++.h>

#include "./../generator/generator.h"
#include "./../helper/helper.h"

using namespace std;

int main() {
    Generator g;
    Encoder e;

    vector<int> vi = g.getRandom(100);
    cout << "vi -> " << to_stringv(vi, "") << endl;

    cout << "NRZ_L -> " << to_stringv(e.NRZ_L(vi), "") << endl;
    cout << "NRZ_I -> " << to_stringv(e.NRZ_I(vi), "") << endl;
    cout << "Manchester -> " << to_stringv(e.Manchester(vi), "") << endl;
    cout << "Differential_Manchester -> " << to_stringv(e.Differential_Manchester(vi), "") << endl;
    cout << "AMI -> " << to_stringv(e.AMI(vi), "") << endl;

    return 0;
}
