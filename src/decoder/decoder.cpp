#include "decoder.h"

#include <iostream>
#include <vector>

#include "./../encoder/encoder.h"
#include "./../generator/generator.h"
#include "./../helper/helper.h"

int main() {
    Generator g;
    Encoder e;
    Decoder d;

    std::vector<int> vi = g.getRandom(100);
    std::cout << "vi -> " << to_stringv(vi, "") << std::endl;

    std::cout << "NRZ_L -> " << to_stringv(d.NRZ_L(e.NRZ_L(vi)), "") << std::endl;
    std::cout << "NRZ_I -> " << to_stringv(d.NRZ_I(e.NRZ_I(vi)), "") << std::endl;
    std::cout << "Manchester -> " << to_stringv(d.Manchester(e.Manchester(vi)), "") << std::endl;
    std::cout << "Differential_Manchester -> " << to_stringv(d.Differential_Manchester(e.Differential_Manchester(vi)), "") << std::endl;
    std::cout << "AMI -> " << to_stringv(d.AMI(e.AMI(vi)), "") << std::endl;

    return 0;
}
