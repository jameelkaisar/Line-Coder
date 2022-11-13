#include "unscrambler.h"

#include <iostream>
#include <vector>

#include "./../generator/generator.h"
#include "./../helper/helper.h"
#include "./../scrambler/scrambler.h"

int main() {
    Generator g;
    Scrambler s;
    Unscrambler u;

    std::vector<int> vi = g.getRandomWithZeros(100, 16);
    std::cout << "vi -> " << to_stringv(vi, "") << std::endl;

    std::cout << "HDB3 -> " << to_stringv(u.HDB3(s.HDB3(vi)), "") << std::endl;
    std::cout << "B8ZS -> " << to_stringv(u.B8ZS(s.B8ZS(vi)), "") << std::endl;

    return 0;
}
