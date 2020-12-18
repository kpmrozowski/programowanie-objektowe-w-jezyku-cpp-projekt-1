class Kredyt {
private:
	double dlug{ 0. };
	int pozostale_raty{ 0 };

public:
	Kredyt() {}
	Kredyt(double kwota, int czas_splaty) {
		dlug = kwota;
		pozostale_raty = czas_splaty;
	}
	~Kredyt() {}
	double splac_rate() {
		if (pozostale_raty > 0) {
			double splata = dlug / (double)pozostale_raty;
			pozostale_raty = pozostale_raty - 1;
			dlug = dlug - splata;
			return splata;
		}
		else return 0;
	}
};

template <int N = 100>
class Kredyty : public Kredyt{
private:
	unsigned int index = 0;
public:
	Kredyt* tab = new Kredyt[N];
	Kredyty& operator[](unsigned int iindex) {
		return tab[iindex];
	}
	Kredyty& operator=(Kredyt&& obj) {
		tab[index] = obj;
		return *this;
	}
};