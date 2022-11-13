#include "generator.h"

#include <iostream>

#include "./../helper/helper.h"

int main() {
    Generator g;

    std::cout << "getRandom -> " << to_stringv(g.getRandom(10)) << std::endl;
    std::cout << "getRandomWithZeros -> " << to_stringv(g.getRandomWithZeros(10, 5)) << std::endl;
    std::cout << "getRandomWithOnes -> " << to_stringv(g.getRandomWithOnes(10, 5)) << std::endl;

    return 0;
}
