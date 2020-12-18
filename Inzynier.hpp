#include "Pracownik.hpp"
#include <iostream>

class Inz : public Pracownik {
    std::string wydzial{get_random_faculty()};
public:
	Inz() {}
	~Inz() {}
	Inz& operator=(const Inz&) { return *this; }
    std::string getWydzial() { return wydzial; }

	static const double przychod;
	static const double pensja;
};

const double Inz::przychod{ 2.25 };
const double Inz::pensja{ 2 };