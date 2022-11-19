#include <algorithm>
#include <string>
#include <vector>

template <typename T>
std::string to_stringv(const std::vector<T>& vec) {
    typename std::vector<T>::const_iterator it;
    std::string s = "[";
    for (it = vec.begin(); it != vec.end(); it++) {
        if (it != vec.begin()) s += ", ";
        if constexpr (std::is_same_v<T, char> || std::is_same_v<T, std::string>)
            s += *it;
        else
            s += std::to_string(*it);
    }
    s += "]";
    return s;
}

template <typename T>
std::string to_stringv(const std::vector<T>& vec, std::string delim) {
    typename std::vector<T>::const_iterator it;
    std::string s;
    for (it = vec.begin(); it != vec.end(); it++) {
        if (it != vec.begin()) s += delim;
        if constexpr (std::is_same_v<T, char> || std::is_same_v<T, std::string>)
            s += *it;
        else
            s += std::to_string(*it);
    }
    return s;
}

std::vector<int> getLongestPallindrome(std::vector<int> bits) {
    int n = bits.size();
    int new_n = 2 * n + 1;
    std::vector<int> new_bits = std::vector<int>(new_n, -2);
    for (int i = 0; i < n; i++) {
        new_bits[2 * i + 1] = bits[i];
    }
    std::vector<int> pal(new_n);
    int center = 0, right = 0;
    int longest_length = 0, longest_center = 0;
    for (int i = 0; i < new_n; i++) {
        int mirror = 2 * center - i;
        if (right > i) {
            pal[i] = std::min(pal[mirror], right - i);
        }
        int a = i + (pal[i] + 1);
        int b = i - (pal[i] + 1);
        while (b >= 0 && a < new_n && new_bits[a] == new_bits[b]) {
            b--;
            a++;
            pal[i]++;
        }
        if (pal[i] >= longest_length) {
            longest_center = i;
            longest_length = pal[i];
        }
        if (i + pal[i] > right) {
            center = i;
            right = i + pal[i];
        }
    }
    std::vector<int> result;
    for (int i = longest_center - longest_length; i <= longest_center + longest_length; i++) {
        if (new_bits[i] != -2) {
            result.push_back(new_bits[i]);
        }
    }
    return result;
}
