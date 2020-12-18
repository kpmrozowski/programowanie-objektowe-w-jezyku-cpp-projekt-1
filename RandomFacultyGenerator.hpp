//
// Created by jgalecki on 13.11.2020.
//

#ifndef P1_CPP_LAB_RANDOMDACULTYGENERATOR_HPP
#define P1_CPP_LAB_RANDOMDACULTYGENERATOR_HPP

#include <array>
#include <random>
#include <string>
#include <sstream>

struct RandomFacultyGenerator{
    static std::mt19937 prng;
};

std::mt19937 RandomFacultyGenerator::prng = std::mt19937{std::random_device{}()};

constexpr std::array faculties{
    "MEiL",
    "WEiTI",
    "IChiP",
    "Architektoniczny",
    "IL",
    "Elektrycznego",
    "AiNS",
    "MiNI",
    "SiMR",
    "WIP",
};

std::string get_random_faculty() {
    std::uniform_int_distribution< std::size_t > fnd{0, faculties.size() - 1};
    std::stringstream faculty;
    faculty << faculties[fnd(RandomFacultyGenerator::prng)];
    return faculty.str();
}

#endif // P1_CPP_LAB_RANDOMSTRINGGENERATOR_HPP