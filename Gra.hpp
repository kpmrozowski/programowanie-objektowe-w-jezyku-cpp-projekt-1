#include "RandomNameGenerator.hpp"
#include "RandomFacultyGenerator.hpp"
#include "RandomBoolGeneratorMag.hpp"
#include "RandomDoubleGenerator.hpp"
#include "Firma.hpp"

class Gra {
private:
    bool                     stan;
    std::unique_ptr< Firma > firma   = std::make_unique< Firma >();
    static constexpr double  wygrana = 10.;

public:
	bool get_state() { return stan; }

private:
	void tick() {
		std:: cout << "ilosc pracownikow: " << firma->n_prac << "/" << firma->n_wakatow << "\n";
		firma->otrzymaj_przychod();
		firma->splac_raty();
		firma->zaplac_wynagrodzenie();
		std::cout << "Obecny stan konta: " << firma->get_stan_konta() << "\n";
	}
public:
	Gra() : firma{ new Firma }, stan{ true } {}
	~Gra() { }
	void akcja_gracza() {
		std::cout << "what do you wanna do do? (lp/hinz/hmag/hmkt/hrob/kredyt/tick/koniec) : ";
		std::string akcja;
		std::cin >> akcja;
		if (akcja == "lp") {
			firma->drukuj_pracownikow();
			akcja_gracza();
		}
		else if (akcja == "hinz") {
			firma->zatrudnij(std::make_unique<std::variant<Inz, Mag, Mkt, Rob>>(Inz{}));
			tick();
			std::cout << "\n";
		}
		else if (akcja == "hmag") {
			firma->zatrudnij(std::make_unique<std::variant<Inz, Mag, Mkt, Rob>>(Mag{}));
			tick();
			std::cout << "\n";
		}
		else if (akcja == "hmkt") {
			firma->zatrudnij(std::make_unique<std::variant<Inz, Mag, Mkt, Rob>>(Mkt{}));
			tick();
			std::cout << "\n";
		}
		else if (akcja == "hrob") {
			firma->zatrudnij(std::make_unique<std::variant<Inz, Mag, Mkt, Rob>>(Rob{}));
			tick();
			std::cout << "\n";
		}
		else if (akcja == "kredyt") {
			std::cout << "Kwota kredytu:   ";
			double a, proc{ 0 };
			std::cin >> a;
			int inst{ 1 };
			double a1{ 0.5 * a }, a2{ 0.9 * a }, a3{ 2 * a }, a4{ 2 * a };
			int inst1{ (int)(a / 4) }, inst2{ 3 }, inst3{ (int)(a / 4) }, inst4{ (int)(a / 16 + 4) };
			double proc1{ .8 }, proc2{ .05 }, proc3{ .5 }, proc4{ 0 };
			std::cout << "\nOto lista dostepnych obecnie kredytow:";
			std::cout << "\n1. 'Chwilowka':                     kwota:   " << a1 << ";   raty:   " << inst1 << ";   oprocentowanie:   " << proc1 * 100 << "%";
			std::cout << "\n2. 'Brudne pieniadze od Slawka':    kwota:   " << a2 << ";   raty:   " << inst2 << ";   oprocentowanie:   " << proc2 * 100 << "%";
			std::cout << "\n3. 'Legalne pieniadze z banku':	    kwota:   " << a3 << ";   raty:   " << inst3 << ";   oprocentowanie:   " << proc3 * 100 << "%";
			std::cout << "\n4. 'Pakt z diablem':                kwota:   " << a4 << ";   raty:   " << inst4 << ";   oprocentowanie:   " << proc4 * 100 << "%";
			std::cout << "\nWybieram nr: ";	int nr;  std::cin >> nr;
			if (nr == 1 || nr == 2 || nr == 3 || nr == 4) {
				std::cout << "\nWybrales pozyczke nr " << nr;
				switch (nr) {
				case 1: std::cout << "'Chwilowka'\n";					a = a1;	inst = inst1;	proc = proc1; firma->wez_kredyt(a, inst, proc); break;
				case 2: std::cout << "'Brudne pieniadze od Slawka'\n";	a = a2;	inst = inst2;	proc = proc2; firma->wez_kredyt(a, inst, proc); break;
				case 3: std::cout << "'Legalne pieniadze z banku'\n";	a = a3;	inst = inst3;	proc = proc3; firma->wez_kredyt(a, inst, proc); break;
				case 4: std::cout << "'Pakt z diablem'\n";				a = a4;	inst = inst4;	proc = proc4; firma->wez_kredyt(a, inst, proc); break;
				}
			} else { std::cout << "Niewlasciwy numer, sproboj jeszcze raz wziac kredyt\n";  akcja_gracza(); }
			tick();
			std::cout << "\n";
		}
		else if (akcja == "tick") {
			tick();
			std::cout << "\n";
		}
		else if (akcja == "koniec")
			stan = false;
		else
			std::cout << "niewlasciwa komenda\n";
		if (firma->get_stan_konta() < 0) {
			std::cout << "Jestes bankrutem!\n";
			stan = false;
			return;
		}
		if (firma->wartosc_firmy() > wygrana + firma->splata) {
			std::cout << "Masz monopol na wszystko co sprzedajesz. Wygrales!\n";
			stan = false;
			return;
		}
	}
};