#include <assert.h>

#include <iostream>
#include <vector>

#include "./../src/decoder/decoder.h"
#include "./../src/encoder/encoder.h"
#include "./../src/generator/generator.h"
#include "./../src/helper/helper.h"
#include "./../src/plotter/plotter.h"
#include "./../src/scrambler/scrambler.h"
#include "./../src/unscrambler/unscrambler.h"

int main() {
    // Test Helper
    std::vector<int> hlp1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    assert(to_stringv(hlp1) == "[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]" && std::cout << "Assertion Success: to_stringv(std::vector<int>)" << std::endl);
    assert(to_stringv(hlp1, "") == "12345678910" && std::cout << "Assertion Success: to_stringv(std::vector<int>, std::string)" << std::endl);
    assert(to_stringv(hlp1, "#") == "1#2#3#4#5#6#7#8#9#10" && std::cout << "Assertion Success: to_stringv(std::vector<int>, std::string)" << std::endl);

    std::vector<std::string> hlp2 = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
    assert(to_stringv(hlp2) == "[one, two, three, four, five, six, seven, eight, nine, ten]" && std::cout << "Assertion Success: to_stringv(std::vector<string>)" << std::endl);
    assert(to_stringv(hlp2, "") == "onetwothreefourfivesixseveneightnineten" && std::cout << "Assertion Success: to_stringv(std::vector<string>, std::string)" << std::endl);
    assert(to_stringv(hlp2, "#") == "one#two#three#four#five#six#seven#eight#nine#ten" && std::cout << "Assertion Success: to_stringv(std::vector<string>, std::string)" << std::endl);

    std::vector<int> hlp3 = {1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0};
    std::vector<int> hlp4 = {1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1};
    assert(getLongestPallindrome(hlp3) == hlp4 && std::cout << "Assertion Success: getLongestPallindrome(std::vector<int>)" << std::endl);

    // Test Generator
    Generator g;
    std::vector<int> gen1 = g.getRandom(100);
    std::vector<int> gen2 = g.getRandom(100);
    assert(gen1 != gen2 && std::cout << "Assertion Success: Generator::getRandom()" << std::endl);

    std::vector<int> gen3 = g.getRandomWithZeros(100, 10);
    assert(to_stringv(gen3, "").find("0000000000") != std::string::npos && std::cout << "Assertion Success: Generator::getRandomWithZeros()" << std::endl);

    std::vector<int> gen4 = g.getRandomWithOnes(100, 10);
    assert(to_stringv(gen4, "").find("1111111111") != std::string::npos && std::cout << "Assertion Success: Generator::getRandomWithOnes()" << std::endl);

    // Test Encoder
    Encoder e;
    std::vector<int> enc1 = {1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0};
    std::vector<int> enc2 = {1, -1, -1, 1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, 1, -1, -1, 1, 1, -1, 1, 1, 1, 1, 1, -1, -1, 1, -1, -1, -1, -1, -1, 1, -1, 1, -1, 1, 1, -1, -1, 1, -1, 1, -1, 1, 1, -1, -1, 1, -1, -1, -1, -1, 1, 1, -1, 1, -1, -1, 1, -1, 1, 1, -1, 1, -1, -1, -1, -1, -1, 1, 1, -1, -1, -1, -1, -1, -1, -1, 1, 1, -1, 1, 1, -1, 1, 1, 1, 1, -1, 1, -1, 1, -1, -1, -1, 1, -1};
    std::vector<int> enc3 = {-1, -1, -1, 1, 1, -1, 1, 1, 1, -1, 1, 1, 1, -1, 1, -1, -1, -1, 1, -1, -1, 1, -1, 1, -1, 1, 1, 1, -1, -1, -1, -1, -1, -1, 1, 1, -1, -1, 1, -1, -1, -1, 1, 1, -1, -1, 1, -1, -1, -1, 1, 1, 1, 1, 1, -1, 1, 1, -1, -1, -1, 1, 1, -1, 1, 1, -1, -1, -1, -1, -1, -1, 1, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1, 1, -1, -1, 1, -1, 1, -1, -1, 1, 1, -1, -1, -1, -1, 1, 1};
    std::vector<int> enc4 = {-1, 1, 1, -1, 1, -1, -1, 1, 1, -1, -1, 1, -1, 1, 1, -1, 1, -1, -1, 1, -1, 1, 1, -1, 1, -1, -1, 1, -1, 1, -1, 1, 1, -1, 1, -1, -1, 1, -1, 1, 1, -1, -1, 1, -1, 1, -1, 1, -1, 1, -1, 1, 1, -1, 1, -1, -1, 1, 1, -1, 1, -1, 1, -1, 1, -1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, -1, 1, 1, -1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, -1, 1, 1, -1, 1, -1, -1, 1, 1, -1, 1, -1, 1, -1, 1, -1, -1, 1, -1, 1, 1, -1, -1, 1, 1, -1, 1, -1, -1, 1, 1, -1, -1, 1, -1, 1, 1, -1, -1, 1, 1, -1, 1, -1, 1, -1, 1, -1, 1, -1, -1, 1, -1, 1, 1, -1, 1, -1, 1, -1, 1, -1, 1, -1, 1, -1, 1, -1, -1, 1, -1, 1, 1, -1, -1, 1, -1, 1, 1, -1, -1, 1, -1, 1, -1, 1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, 1, -1, 1, -1, -1, 1, 1, -1};
    std::vector<int> enc5 = {1, -1, 1, -1, 1, -1, -1, 1, -1, 1, 1, -1, -1, 1, -1, 1, -1, 1, 1, -1, -1, 1, -1, 1, -1, 1, 1, -1, -1, 1, 1, -1, 1, -1, 1, -1, -1, 1, 1, -1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, -1, 1, -1, 1, -1, 1, 1, -1, 1, -1, 1, -1, 1, -1, 1, -1, 1, -1, -1, 1, -1, 1, 1, -1, 1, -1, -1, 1, 1, -1, 1, -1, 1, -1, -1, 1, -1, 1, 1, -1, 1, -1, -1, 1, 1, -1, 1, -1, 1, -1, -1, 1, -1, 1, -1, 1, -1, 1, -1, 1, 1, -1, -1, 1, -1, 1, 1, -1, 1, -1, 1, -1, -1, 1, -1, 1, 1, -1, -1, 1, -1, 1, 1, -1, 1, -1, 1, -1, 1, -1, 1, -1, 1, -1, -1, 1, 1, -1, 1, -1, 1, -1, 1, -1, 1, -1, 1, -1, 1, -1, 1, -1, -1, 1, 1, -1, 1, -1, -1, 1, 1, -1, 1, -1, -1, 1, 1, -1, -1, 1, 1, -1, 1, -1, -1, 1, -1, 1, 1, -1, 1, -1, 1, -1, 1, -1, -1, 1, -1, 1};
    std::vector<int> enc6 = {1, 0, 0, -1, 0, 1, -1, 0, 0, 1, -1, 0, 0, 1, -1, 1, 0, 0, -1, 1, 0, -1, 1, -1, 1, -1, 0, 0, 1, 0, 0, 0, 0, 0, -1, 0, 1, 0, -1, 1, 0, 0, -1, 0, 1, 0, -1, 1, 0, 0, -1, 0, 0, 0, 0, 1, -1, 0, 1, 0, 0, -1, 0, 1, -1, 0, 1, 0, 0, 0, 0, 0, -1, 1, 0, 0, 0, 0, 0, 0, 0, -1, 1, 0, -1, 1, 0, -1, 1, -1, 1, 0, -1, 0, 1, 0, 0, 0, -1, 0};

    assert(e.NRZ_L(enc1) == enc2 && std::cout << "Assertion Success: Encoder::NRZ_L()" << std::endl);
    assert(e.NRZ_I(enc1) == enc3 && std::cout << "Assertion Success: Encoder::NRZ_I()" << std::endl);
    assert(e.Manchester(enc1) == enc4 && std::cout << "Assertion Success: Encoder::Manchester()" << std::endl);
    assert(e.Differential_Manchester(enc1) == enc5 && std::cout << "Assertion Success: Encoder::Differential_Manchester()" << std::endl);
    assert(e.AMI(enc1) == enc6 && std::cout << "Assertion Success: Encoder::AMI()" << std::endl);

    // Test Decoder
    Decoder d;
    std::vector<int> dec1 = g.getRandom(100);

    assert(d.NRZ_L(e.NRZ_L(dec1)) == dec1 && std::cout << "Assertion Success: Decoder::NRZ_L()" << std::endl);
    assert(d.NRZ_I(e.NRZ_I(dec1)) == dec1 && std::cout << "Assertion Success: Decoder::NRZ_I()" << std::endl);
    assert(d.Manchester(e.Manchester(dec1)) == dec1 && std::cout << "Assertion Success: Decoder::Manchester()" << std::endl);
    assert(d.Differential_Manchester(e.Differential_Manchester(dec1)) == dec1 && std::cout << "Assertion Success: Decoder::Differential_Manchester()" << std::endl);
    assert(d.AMI(e.AMI(dec1)) == dec1 && std::cout << "Assertion Success: Decoder::AMI()" << std::endl);

    // Test Scrambler
    Scrambler s;
    std::vector<int> scr1 = {0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0};
    std::vector<int> scr2 = {0, 0, 1, -1, 1, -1, 0, 0, 1, -1, 0, 1, -1, 0, 1, 0, -1, 0, 0, 0, 1, -1, 1, -1, 1, 0, 0, -1, 1, 0, -1, 1, -1, 1, 0, 0, 1, -1, 1, -1, 0, 1, -1, 1, 0, 0, 0, -1, 0, 0, 1, 0, 0, 0, -1, 1, 0, -1, 1, -1, 0, 0, 0, 1, 0, -1, 1, -1, 0, 0, -1, 0, 0, 1, 0, 0, -1, 0, 1, 0, 0, 0, 1, -1, 0, 0, -1, 1, 0, 0, 1, -1, 0, 0, -1, 0, 0, 1, 0, 0};
    std::vector<int> scr3 = {0, 0, 1, -1, 1, -1, 0, 0, 1, -1, 0, 1, -1, 0, 1, 0, -1, 0, 0, 0, 1, -1, 1, -1, 1, 0, 0, -1, 1, 0, -1, 1, -1, 0, 0, 0, 0, 1, -1, 1, 0, -1, 1, -1, 0, 0, 0, 1, 0, 0, -1, 0, 0, 0, 1, -1, 0, 1, -1, 1, 0, 0, 0, -1, 0, 1, -1, 0, 0, 0, 0, 0, 0, 1, 0, 0, -1, 0, 1, 0, 0, 0, 1, -1, 0, -1, 1, 0, 0, 0, 1, -1, 0, -1, 1, 0, 0, -1, 0, 0};

    assert(s.HDB3(scr1) == scr2 && std::cout << "Assertion Success: Scrambler::HDB3()" << std::endl);
    assert(s.B8ZS(scr1) == scr3 && std::cout << "Assertion Success: Scrambler::B8ZS()" << std::endl);

    // Test Unscrambler
    Unscrambler u;
    std::vector<int> uns1 = g.getRandomWithZeros(100, 16);

    assert(u.HDB3(s.HDB3(uns1)) == uns1 && std::cout << "Assertion Success: Unscrambler::HDB3()" << std::endl);
    assert(u.B8ZS(s.B8ZS(uns1)) == uns1 && std::cout << "Assertion Success: Unscrambler::B8ZS()" << std::endl);

    return 0;
}
