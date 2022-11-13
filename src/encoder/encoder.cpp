#include "encoder.h"

#include <iostream>
#include <vector>

#include "./../generator/generator.h"
#include "./../helper/helper.h"

int main() {
    Generator g;
    Encoder e;

    std::vector<int> vi = g.getRandom(100);
    std::cout << "vi -> " << to_stringv(vi, "") << std::endl;

    std::cout << "NRZ_L -> " << to_stringv(e.NRZ_L(vi), "") << std::endl;
    std::cout << "NRZ_I -> " << to_stringv(e.NRZ_I(vi), "") << std::endl;
    std::cout << "Manchester -> " << to_stringv(e.Manchester(vi), "") << std::endl;
    std::cout << "Differential_Manchester -> " << to_stringv(e.Differential_Manchester(vi), "") << std::endl;
    std::cout << "AMI -> " << to_stringv(e.AMI(vi), "") << std::endl;

    return 0;
}
