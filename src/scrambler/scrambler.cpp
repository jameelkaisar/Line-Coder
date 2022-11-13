#include "scrambler.h"

#include <iostream>
#include <vector>

#include "./../generator/generator.h"
#include "./../helper/helper.h"

int main() {
    Generator g;
    Scrambler s;

    std::vector<int> vi = g.getRandomWithZeros(100, 16);
    std::cout << "vi -> " << to_stringv(vi, "") << std::endl;

    std::cout << "HDB3 -> " << to_stringv(s.HDB3(vi), "") << std::endl;
    std::cout << "B8ZS -> " << to_stringv(s.B8ZS(vi), "") << std::endl;

    return 0;
}
