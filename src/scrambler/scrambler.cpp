#include "scrambler.h"

#include <bits/stdc++.h>

#include "./../encoder/encoder.h"
#include "./../generator/generator.h"
#include "./../helper/helper.h"

using namespace std;

int main() {
    Generator g;
    Encoder e;
    Scrambler s;

    vector<int> vi = g.getRandomWithZeros(100, 16);
    cout << "vi -> " << to_stringv(vi, "") << endl;

    cout << "HDB3 -> " << to_stringv(s.HDB3(e.NRZ_L(vi)), "") << endl;
    cout << "B8ZS -> " << to_stringv(s.B8ZS(e.NRZ_L(vi)), "") << endl;

    return 0;
}
