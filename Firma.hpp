#include "Inzynier.hpp"
#include "Magazynier.hpp"
#include "Marketer.hpp"
#include "Robotnik.hpp"
#include "Kredyt.hpp"
#include "PrinterPracownikow.hpp"
#include <iostream>
#include <utility>
#include <memory>
#include <variant>

class Firma {
public:
    using pracownik_var = std::variant< Inz, Mag, Mkt, Rob >;
    int                 n_prac{0};
    static const size_t n_wakatow{100};
    double              splata;

private:
        double                             stan_konta{40};
        int                                n_kredytow{0};
        std::unique_ptr< Kredyt >          kredyty[100];
        std::unique_ptr< pracownik_var[] > pracownik;
        int                                n_przych{0};
        double*                            historia_przych = new double[100];

public:
	Firma() : pracownik{ std::make_unique<pracownik_var[]>(n_wakatow)} {}

	~Firma() {}

	void drukuj_pracownikow() const {
		std::cout << "Lista pracownikow:\n";
		PrinterPracownikow<pracownik_var> pp;
		for (int i = 0; i < n_prac; i++) {
			pp(move(pracownik[i]));
		}
	}
	void wez_kredyt(double kwota, int czas_splaty, double proc) {
		kredyty[n_kredytow] = std::make_unique<Kredyt>(kwota * (1 + proc), czas_splaty);
		stan_konta = stan_konta + kwota;
		n_kredytow++;
	}

	void zatrudnij(const std::unique_ptr<std::variant<Inz, Mag, Mkt, Rob>>& obj) {
		pracownik[n_prac] = std::variant<Inz, Mag, Mkt, Rob>(*obj);
		n_prac++;
	}

	void zaplac_wynagrodzenie() {
		double koszt = std::move(oblicz_koszt());
		std::cout << "Koszty w tym miesiacu: " << koszt << "\n";
		stan_konta = stan_konta - koszt;
	}
	void otrzymaj_przychod() {
		double przychod = std::move(oblicz_przychod());
		stan_konta = stan_konta + przychod;
		historia_przych[n_przych] = przychod;
		n_przych++;
		std::cout << "Przychod w tym miesiacu: " << przychod << "\n";
	}
	void splac_raty() {
		double _splata{ 0 };
		for (int i = 0; i < n_kredytow; i++) {
			_splata = _splata + kredyty[i]->splac_rate();
		}
		stan_konta = stan_konta - _splata;
		splata = _splata;
		std::cout << "Suma splaconych rat w tym miesiacu: " << _splata << "\n";
	}

	double get_stan_konta() const { return stan_konta; }
	double wartosc_firmy() {
		//std::cout << "Miesieczny przychod: " << value << "\n";
		return oblicz_przychod() - oblicz_koszt();
	}

private:
        struct Wizytator_przychod
    {
        double przychod = 0;
        void   operator()(const Inz&)
        {
            przychod += Inz::przychod;
        }
        void operator()(const Mag&)
        {
            przychod += Mag::przychod;
        }
        void operator()(const Mkt&)
        {
            przychod += Mkt::przychod;
        }
        void operator()(const Rob&)
        {
            przychod += Rob::przychod;
        }
    };
        double oblicz_przychod() const {
		//double przychod{ 0 };
		Wizytator_przychod w;
		for (int i = 0; i < n_prac; i++) {
			std::visit(w, pracownik[i]);
		}
		return w.przychod;  
		}
        struct Wizytator_pensja
        {
            double pensja = 0;
            void   operator()(const Inz&)
            {
                pensja += Inz::pensja;
            }
            void operator()(const Mag&)
            {
                pensja += Mag::pensja;
            }
            void operator()(const Mkt&)
            {
                pensja += Mkt::pensja;
            }
            void operator()(const Rob&)
            {
                pensja += Rob::pensja;
            }
        };
	double oblicz_koszt() const {
		double koszt{ 10 };
		Wizytator_pensja w;
		for (int i = 0; i < n_prac; i++) {
			std::visit(w, pracownik[i]);
		}
		return w.pensja + koszt;
	}
};
