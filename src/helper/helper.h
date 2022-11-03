#include <bits/stdc++.h>

using namespace std;

template <typename T>
string to_stringv(const vector<T>& vec) {
    typename vector<T>::const_iterator it;
    string s = "[";
    for (it = vec.begin(); it != vec.end(); it++) {
        if (it != vec.begin()) s += ", ";
        if constexpr (is_same_v<T, char> || is_same_v<T, string>)
            s += *it;
        else
            s += to_string(*it);
    }
    s += "]";
    return s;
}

template <typename T>
string to_stringv(const vector<T>& vec, string delim) {
    typename vector<T>::const_iterator it;
    string s;
    for (it = vec.begin(); it != vec.end(); it++) {
        if (it != vec.begin()) s += delim;
        if constexpr (is_same_v<T, char> || is_same_v<T, string>)
            s += *it;
        else
            s += to_string(*it);
    }
    return s;
}

vector<int> getLongestPallindrome(vector<int> bits) {
    int n = bits.size();
    int start = 0, end = 0;
    for (int i = 0; i < n; i++) {
        int l = i, r = i;
        while (l >= 0 && r < n && bits[l] == bits[r]) {
            l--;
            r++;
        }
        if (r - l - 1 > end - start + 1) {
            start = l + 1;
            end = r - 1;
        }
        l = i, r = i + 1;
        while (l >= 0 && r < n && bits[l] == bits[r]) {
            l--;
            r++;
        }
        if (r - l - 1 > end - start + 1) {
            start = l + 1;
            end = r - 1;
        }
    }
    vector<int> result;
    for (int i = start; i <= end && i < n; i++) {
        result.push_back(result[i]);
    }
    return result;
}
