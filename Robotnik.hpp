#include "Pracownik.hpp"
using namespace std;

class Rob : public Pracownik {
private:
	double but{ 39.1 }; //default
public:
	Rob() {
		but = 38.5 + get_random_double(0,20)/2.;
	}
	Rob(double ibut) : but{ ibut } {}
	~Rob() {}
	double getBut() { return but; }
	
	static const double przychod;
	static const double pensja;
};

const double Rob::przychod{ 1.1 };
const double Rob::pensja{ 1 };