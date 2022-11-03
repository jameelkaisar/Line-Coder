#include "helper.h"

#include <bits/stdc++.h>
#include "./../generator/generator.h"

using namespace std;

int main() {
    Generator g;
    vector<int> v = g.getRandom(100);
    cout << "v -> " << to_stringv(v, "") << endl;
    cout << "getLongestPallindrome -> " << to_stringv(getLongestPallindrome(v), "") << endl;

    vector<int> vi = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "vi -> " << to_stringv(vi) << endl;
    cout << "vi -> " << to_stringv(vi, "") << endl;

    vector<float> vf = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.10};
    cout << "vf -> " << to_stringv(vf) << endl;
    cout << "vf -> " << to_stringv(vf, ",") << endl;

    vector<char> vc = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    cout << "vc -> " << to_stringv(vc) << endl;
    cout << "vc -> " << to_stringv(vc, "") << endl;

    vector<string> vs = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
    cout << "vs -> " << to_stringv(vs) << endl;
    cout << "vs -> " << to_stringv(vs, "-") << endl;

    return 0;
}
