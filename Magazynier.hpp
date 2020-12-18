#include "Pracownik.hpp"

class Mag : public Pracownik {
private:
    bool obsl_widl{0};	//default
public:
    Mag() {}
	~Mag() {}
    bool getObslugujeWozek() {
        if (get_random_bool() == "tak")
            obsl_widl = 1;
		else
			obsl_widl = 0;
		return obsl_widl;
	}

	static const double przychod;
	static const double pensja;
};

const double Mag::przychod{ 1.5 };
const double Mag::pensja{ 2 };