#include <vector>

class Unscrambler {
   public:
    std::vector<int> B8ZS(std::vector<int> bits);
    std::vector<int> HDB3(std::vector<int> bits);
};

std::vector<int> Unscrambler::B8ZS(std::vector<int> bits) {
    std::vector<int> result;
    bool expect = true;
    int count = 0;
    int n = bits.size();
    for (int i = 0; i < n; i++) {
        if (bits[i] != 0) {
            result.push_back(1);
            if (expect != (bits[i] > 0)) {
                count++;
            }
            expect = bits[i] < 0;
            if (count == 2) {
                if (i + 1 < n) {
                    expect = bits[i + 1] < 0;
                    bits[i + 1] = 0;
                }
                result[i] = 0;
                if (i - 2 >= 0)
                    result[i - 2] = 0;
                if (i - 3 >= 0)
                    result[i - 3] = 0;
                count = 0;
            }
        } else {
            result.push_back(0);
        }
    }
    return result;
}

std::vector<int> Unscrambler::HDB3(std::vector<int> bits) {
    std::vector<int> result;
    bool expect = true;
    int n = bits.size();
    for (int i = 0; i < n; i++) {
        if (bits[i] != 0) {
            result.push_back(1);
            if (expect != (bits[i] > 0)) {
                result[i] = 0;
                if (i - 3 >= 0)
                    result[i - 3] = 0;
            }
            expect = bits[i] < 0;
        } else {
            result.push_back(0);
        }
    }
    return result;
}
