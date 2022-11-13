#include <vector>

class Decoder {
   private:
   public:
    Decoder() {
    }

    std::vector<int> NRZ_L(std::vector<int> bits) {
        std::vector<int> result;
        for (auto b : bits) {
            if (b == 1) {
                result.push_back(1);
            } else {
                result.push_back(0);
            }
        }
        return result;
    }

    std::vector<int> NRZ_I(std::vector<int> bits) {
        std::vector<int> result;
        int prev = 1;
        for (auto b : bits) {
            if (b == prev) {
                result.push_back(0);
            } else {
                result.push_back(1);
            }
            prev = b;
        }
        return result;
    }

    std::vector<int> Manchester(std::vector<int> bits) {
        std::vector<int> result;
        bool flag = true;
        for (auto b : bits) {
            flag = !flag;
            if (flag) continue;
            if (b == 1) {
                result.push_back(0);
            } else {
                result.push_back(1);
            }
        }
        return result;
    }

    std::vector<int> Differential_Manchester(std::vector<int> bits) {
        std::vector<int> result;
        bool flag = true;
        int prev = 1;
        for (auto b : bits) {
            flag = !flag;
            if (flag) continue;
            if (b == prev) {
                result.push_back(1);
                prev *= -1;
            } else {
                result.push_back(0);
            }
        }
        return result;
    }

    std::vector<int> AMI(std::vector<int> bits) {
        std::vector<int> result;
        for (auto b : bits) {
            if (b == 0) {
                result.push_back(0);
            } else {
                result.push_back(1);
            }
        }
        return result;
    }
};
