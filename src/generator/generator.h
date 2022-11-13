#include <time.h>

#include <cstdlib>
#include <vector>

class Generator {
   private:
    std::vector<int> getRandomWith(int n, int zeros, int x);

   public:
    Generator() {
        std::srand(time(0));
    }

    std::vector<int> getRandom(int n, int ph = 0);
    std::vector<int> getRandomWithZeros(int n, int zeros = 4);
    std::vector<int> getRandomWithOnes(int n, int ones = 4);
};

std::vector<int> Generator::getRandomWith(int n, int zeros, int x) {
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

std::vector<int> Generator::getRandom(int n = 256, int ph) {
    std::vector<int> result;
    for (int i = 0; i < n; i++) {
        result.push_back(std::rand() % 2);
    }
    return result;
}

std::vector<int> Generator::getRandomWithZeros(int n = 256, int zeros) {
    return getRandomWith(n, zeros, 0);
}

std::vector<int> Generator::getRandomWithOnes(int n = 256, int ones) {
    return getRandomWith(n, ones, 1);
}
