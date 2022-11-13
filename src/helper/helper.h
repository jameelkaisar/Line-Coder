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
    std::vector<int> result;
    for (int i = start; i <= end && i < n; i++) {
        result.push_back(result[i]);
    }
    return result;
}
