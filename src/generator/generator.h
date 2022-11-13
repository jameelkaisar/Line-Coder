#include <time.h>

#include <cstdlib>
#include <vector>

class Generator {
   private:
   public:
    Generator() {
        std::srand(time(0));
    }

    std::vector<int> getRandom(int n = 256, int ph = 0) {
        std::vector<int> result;
        for (int i = 0; i < n; i++) {
            result.push_back(std::rand() % 2);
        }
        return result;
    }

    std::vector<int> _getRandomWith(int n, int zeros, int x) {
        std::vector<int> result;
        int j = std::rand() % (n - zeros);
        for (int i = 0; i < n; i++) {
            if (i >= j && i < j + zeros)
                result.push_back(x);
            else
                result.push_back(std::rand() % 2);
        }
        return result;
    }

    std::vector<int> getRandomWithZeros(int n = 256, int zeros = 4) {
        return _getRandomWith(n, zeros, 0);
    }

    std::vector<int> getRandomWithOnes(int n = 256, int ones = 4) {
        return _getRandomWith(n, ones, 1);
    }
};
