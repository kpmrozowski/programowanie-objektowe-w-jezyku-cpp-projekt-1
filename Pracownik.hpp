#pragma once

class Pracownik {
private:
	std::string imie;
	double przychod{};
	double pensja{};

public:
	Pracownik() : imie{ get_random_name() } {}
	~Pracownik() {}
	Pracownik& operator=(const Pracownik& obj) { return *this; }
	virtual double getPrzychod() { return przychod; }
	virtual double getPensja() { return pensja; }
	virtual std::string getImie() { return imie; }
};