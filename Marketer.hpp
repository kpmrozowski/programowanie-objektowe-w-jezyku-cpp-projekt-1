#include "Pracownik.hpp"

class Mkt : public Pracownik {
private:
	int followers{ 0 };	//default

public:
	Mkt() {
		followers = 38 + int(get_random_double(0,1000));
	}
	Mkt(int ifollowers)
		: followers{ ifollowers } {}
	~Mkt() {}
	int getFollowers() { return followers; }

	static const double przychod;
	static const double pensja;
};

const double Mkt::przychod{ 1 };
const double Mkt::pensja{ 2 };