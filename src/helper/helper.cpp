#include "helper.h"

#include <iostream>
#include <string>
#include <vector>

#include "./../generator/generator.h"

int main() {
    Generator g;
    std::vector<int> v = g.getRandom(100);
    std::cout << "v -> " << to_stringv(v, "") << std::endl;
    std::cout << "getLongestPallindrome -> " << to_stringv(getLongestPallindrome(v), "") << std::endl;

    std::vector<int> vi = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::cout << "vi -> " << to_stringv(vi) << std::endl;
    std::cout << "vi -> " << to_stringv(vi, "") << std::endl;

    std::vector<float> vf = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10.10};
    std::cout << "vf -> " << to_stringv(vf) << std::endl;
    std::cout << "vf -> " << to_stringv(vf, ",") << std::endl;

    std::vector<char> vc = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    std::cout << "vc -> " << to_stringv(vc) << std::endl;
    std::cout << "vc -> " << to_stringv(vc, "") << std::endl;

    std::vector<std::string> vs = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
    std::cout << "vs -> " << to_stringv(vs) << std::endl;
    std::cout << "vs -> " << to_stringv(vs, "-") << std::endl;

    return 0;
}
