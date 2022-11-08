#include "unscrambler.h"

#include <bits/stdc++.h>

#include "./../generator/generator.h"
#include "./../helper/helper.h"
#include "./../scrambler/scrambler.h"

using namespace std;

int main() {
    Generator g;
    Scrambler s;
    Unscrambler u;

    vector<int> vi = g.getRandomWithZeros(100, 16);
    cout << "vi -> " << to_stringv(vi, "") << endl;

    cout << "HDB3 -> " << to_stringv(u.HDB3(s.HDB3(vi)), "") << endl;
    cout << "B8ZS -> " << to_stringv(u.B8ZS(s.B8ZS(vi)), "") << endl;

    return 0;
}
