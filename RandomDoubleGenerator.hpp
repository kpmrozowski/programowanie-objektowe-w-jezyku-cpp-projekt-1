//
// Created by jgalecki on 13.11.2020.
//

#ifndef P1_CPP_LAB_RANDOMDOUBLEGENERATOR_HPP
#define P1_CPP_LAB_RANDOMDOUBLEGENERATOR_HPP

#include <array>
#include <random>
#include <string>
#include <sstream>

struct RandomDoubleGeneratorMag {
    static std::mt19937 prng;
};

std::mt19937 RandomDoubleGeneratorMag::prng = std::mt19937{std::random_device{}()};

constexpr std::array doubles{
    "tak",
    "nie",
};

double get_random_double(std::size_t min, std::size_t max) {
    std::uniform_int_distribution< std::size_t > fnd{min, max};
    return fnd(RandomDoubleGeneratorMag::prng);
}

#endif //P1_CPP_LAB_RANDOMBOOLGENERATOR_HPP