//
// Created by jgalecki on 13.11.2020.
//

#ifndef P1_CPP_LAB_RANDOMBOOLGENERATOR_HPP
#define P1_CPP_LAB_RANDOMBOOLGENERATOR_HPP

#include <array>
#include <random>
#include <string>
#include <sstream>

struct RandomBoolGeneratorMag {
    static std::mt19937 prng;
};

std::mt19937 RandomBoolGeneratorMag::prng = std::mt19937{std::random_device{}()};

constexpr std::array bools{
    "tak",
    "nie",
};

std::string get_random_bool() {
    std::uniform_int_distribution< std::size_t > fnd{0, bools.size() - 1};
    std::stringstream bol;
    bol << bools[fnd(RandomBoolGeneratorMag::prng)];
    return bol.str();
}

#endif //P1_CPP_LAB_RANDOMBOOLGENERATOR_HPP