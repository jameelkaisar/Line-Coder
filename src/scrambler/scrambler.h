#include <vector>

class Scrambler {
   public:
    std::vector<int> B8ZS(std::vector<int> bits);
    std::vector<int> HDB3(std::vector<int> bits);
};

std::vector<int> Scrambler::B8ZS(std::vector<int> bits) {
    std::vector<int> result;
    int zc = 0;
    bool flag = true;
    for (auto x : bits) {
        if (x != 0) {
            result.push_back(flag ? 1 : -1);
            zc = 0;
            flag = !flag;
        } else {
            result.push_back(0);
            zc++;
        }
        if (zc == 8) {
            int n = result.size();
            result[n - 5] = flag ? -1 : 1;
            result[n - 4] = flag ? 1 : -1;
            result[n - 2] = flag ? 1 : -1;
            result[n - 1] = flag ? -1 : 1;
            zc = 0;
        }
    }
    return result;
}

std::vector<int> Scrambler::HDB3(std::vector<int> bits) {
    std::vector<int> result;
    int zc = 0;
    bool flag = true;
    bool prev = false;
    for (auto x : bits) {
        if (x != 0) {
            result.push_back(prev ? -1 : 1);
            zc = 0;
            flag = !flag;
            prev = !prev;
        } else {
            result.push_back(x);
            zc++;
        }
        if (zc == 4) {
            int n = result.size();
            if (flag) {
                result[n - 1] = prev ? -1 : 1;
                result[n - 4] = prev ? -1 : 1;
            } else {
                result[n - 1] = prev ? 1 : -1;
            }
            zc = 0;
            flag = true;
            prev = result[n - 1] > 0;
        }
    }
    return result;
}
