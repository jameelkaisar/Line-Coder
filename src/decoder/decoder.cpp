#include "decoder.h"

#include <bits/stdc++.h>

#include "./../encoder/encoder.h"
#include "./../generator/generator.h"
#include "./../helper/helper.h"

using namespace std;

int main() {
    Generator g;
    Encoder e;
    Decoder d;

    vector<int> vi = g.getRandom(100);
    cout << "vi -> " << to_stringv(vi, "") << endl;

    cout << "NRZ_L -> " << to_stringv(d.NRZ_L(e.NRZ_L(vi)), "") << endl;
    cout << "NRZ_I -> " << to_stringv(d.NRZ_I(e.NRZ_I(vi)), "") << endl;
    cout << "Manchester -> " << to_stringv(d.Manchester(e.Manchester(vi)), "") << endl;
    cout << "Differential_Manchester -> " << to_stringv(d.Differential_Manchester(e.Differential_Manchester(vi)), "") << endl;
    cout << "AMI -> " << to_stringv(d.AMI(e.AMI(vi)), "") << endl;

    return 0;
}
