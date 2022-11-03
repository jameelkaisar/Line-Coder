#include "generator.h"

#include <bits/stdc++.h>

#include "./../helper/helper.h"

using namespace std;

int main() {
    Generator g;

    cout << "getRandom -> " << to_stringv(g.getRandom(10)) << endl;
    cout << "getRandomWithZeros -> " << to_stringv(g.getRandomWithZeros(10, 5)) << endl;
    cout << "getRandomWithOnes -> " << to_stringv(g.getRandomWithOnes(10, 5)) << endl;

    return 0;
}
