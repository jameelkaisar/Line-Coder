#include "scrambler.h"

#include <bits/stdc++.h>

#include "./../generator/generator.h"
#include "./../helper/helper.h"

using namespace std;

int main() {
    Generator g;
    Scrambler s;

    vector<int> vi = g.getRandomWithZeros(100, 16);
    cout << "vi -> " << to_stringv(vi, "") << endl;

    cout << "HDB3 -> " << to_stringv(s.HDB3(vi), "") << endl;
    cout << "B8ZS -> " << to_stringv(s.B8ZS(vi), "") << endl;

    return 0;
}
