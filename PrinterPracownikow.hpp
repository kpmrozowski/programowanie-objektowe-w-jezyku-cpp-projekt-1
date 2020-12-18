#include <iostream>
#include <variant>

struct Wizytator {
	void operator()( Inz&obj) const { std::cout << "Inz. "<< obj.getImie() 
		<<"   \twydzial:        " << obj.getWydzial() <<"\n"; }
	void operator()( Mag&obj) const { std::cout << "Mag. "<< obj.getImie() 
		<<"   \tobslugujeWozek: " << obj.getObslugujeWozek() <<"\n"; }
	void operator()( Mkt&obj) const { std::cout << "Mkt. "<< obj.getImie() 
		<<"   \tfollowersi:     " << obj.getFollowers() <<"\n"; }
	void operator()( Rob&obj) const { std::cout << "Rob. "<< obj.getImie() 
		<<"   \trozmiar buta:   " << obj.getBut() <<"\n"; }
};// funktor - obiekt funkcyjny  z ()

template <typename T>
struct PrinterPracownikow {
	void operator()(T&& obj) const {
		Wizytator w;
		std::visit(w, obj);
	}
};