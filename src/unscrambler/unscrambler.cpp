#include "unscrambler.h"

#include <bits/stdc++.h>

#include "./../decoder/decoder.h"
#include "./../encoder/encoder.h"
#include "./../generator/generator.h"
#include "./../helper/helper.h"
#include "./../scrambler/scrambler.h"

using namespace std;

int main() {
    Generator g;
    Encoder e;
    Decoder d;
    Scrambler s;
    Unscrambler u;

    vector<int> vi = g.getRandomWithZeros(100, 16);
    cout << "vi -> " << to_stringv(vi, "") << endl;

    cout << "HDB3 -> " << to_stringv(d.NRZ_L(u.HDB3(s.HDB3(e.NRZ_L(vi)))), "") << endl;
    cout << "B8ZS -> " << to_stringv(d.NRZ_L(u.B8ZS(s.B8ZS(e.NRZ_L(vi)))), "") << endl;

    return 0;
}
