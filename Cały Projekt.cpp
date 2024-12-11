#include <vector>
#include <iostream>
#include <cmath>
#include <random>
using namespace std;

random_device srng;
mt19937 rng;

enum class RodzajSygnalu { Skok, Sinusoida, Prostokatny };
const char* const rodzajSygnalu[3] = { "Skok", "Sinusoida", "Prostokatny" };

class Generator {
protected:
    RodzajSygnalu rodzaj;
    double A, T, p, czasAktywacji;
public:
    Generator(RodzajSygnalu r, double a, double t, double pp, double czasAkt = 0)
        : rodzaj(r), A(a), T(t), p(pp), czasAktywacji(czasAkt) {};

    double generuj(double czas) {
        switch (rodzaj) {
        case RodzajSygnalu::Skok:
            return (czas >= czasAktywacji) ? A : 0;
        case RodzajSygnalu::Sinusoida:
            return A * sin((2 * 3.14159265359 / T) * fmod(czas, T));
        case RodzajSygnalu::Prostokatny:
            return (fmod(czas, T) < p * T) ? A : 0;
        default:
            return 0.0;
        }
    }
};

class Regulator {
protected:
    double wartoscZadana;
    double wzmocnienieP;
    double stalaI;
    double stalaD;
    double Uchyb;
    double WczesniejszyUchyb;
    double sumaUchybow;
    double ostatniaNastawa;
public:
    Regulator(double kp, double ki, double kd)
        : wartoscZadana(0), wzmocnienieP(kp), stalaI(ki), stalaD(kd), Uchyb(0), WczesniejszyUchyb(0), sumaUchybow(0), ostatniaNastawa(0) {}

    void setWartoscZadana(double war) { wartoscZadana = war; }
    double getWartoscZadana() const { return wartoscZadana; }

    void aktualizujUchyb(double wartoscRegulowana) {
        WczesniejszyUchyb = Uchyb;
        Uchyb = wartoscZadana - wartoscRegulowana;
        if (stalaI != 0) {
            sumaUchybow += Uchyb;
        }
    }

    double obliczNastawa() {
        double nastawaP = wzmocnienieP * Uchyb;
        double nastawaI = 0;
        if (stalaI != 0) {
            nastawaI = sumaUchybow / stalaI;
        }
        double nastawaD = stalaD * (Uchyb - WczesniejszyUchyb);

        ostatniaNastawa = nastawaP + nastawaI + nastawaD;
        return ostatniaNastawa;
    }

    double getOstatniaNastawa() {
        return ostatniaNastawa;
    }
};

class ObiektARX {
protected:
    double k, z;
    vector<double> a;
    vector<double> b;
    vector<double> ui;
    vector<double> yi;
    double mean;
    double stdev;

    mt19937& generator;
    normal_distribution<double> zaklocenie;

    void zaktualizujZaklocenie() {
        zaklocenie = normal_distribution<double>(mean, stdev);
    }

public:
    ObiektARX(double kk, double zz, vector<double> aa, vector<double> bb, mt19937& gen, double mean = 0.3, double stdev = 0.0)
        : k(kk), z(zz), a(aa), b(bb), ui(bb.size() + static_cast<int>(kk), 0),
        yi(aa.size(), 0), mean(mean), stdev(stdev), generator(gen), zaklocenie(mean, stdev) {}

    void setZaklocenie(double newMean, double newStdev) {
        mean = newMean;
        stdev = newStdev;
        zaktualizujZaklocenie();
    }
    double getZaklocenie()
    {
        return z;
    }

    double obliczWyjscie(double uii) {
        ui.push_back(uii);
        if (ui.size() > b.size() + static_cast<int>(k)) {
            ui.erase(ui.begin());
        }
        double wynik = 0.0;

        for (size_t j = 0; j < b.size(); ++j) {
            if (ui.size() > j + static_cast<int>(k)) {
                wynik += b[j] * ui[ui.size() - 1 - j - static_cast<int>(k)];
            }
        }

        for (size_t j = 0; j < a.size(); ++j) {
            if (yi.size() > j) {
                wynik -= a[j] * yi[yi.size() - 1 - j];
            }
        }
        z = zaklocenie(generator);
        wynik += z;

        yi.push_back(wynik);
        if (yi.size() > a.size()) {
            yi.erase(yi.begin());
        }

        return wynik;
    }
};

class SymulatorUAR {
protected:
    Generator generator;
    double poprzednieWyjscie = 0;
    double wyjscieObiektu = 0;
public:
    Regulator regulator;
    ObiektARX obiekt;
    SymulatorUAR(Generator g, Regulator r, ObiektARX o)
        : generator(g), regulator(r), obiekt(o) {}

    double symulujKrok(double czas) {
        double wartoscZadana = generator.generuj(czas);
        regulator.setWartoscZadana(wartoscZadana);
        poprzednieWyjscie = wyjscieObiektu;
        wyjscieObiektu = obiekt.obliczWyjscie(regulator.getOstatniaNastawa());
        regulator.aktualizujUchyb(wyjscieObiektu);
        obiekt.setZaklocenie(0.1, 0.3);
        double sygnalSterowania = regulator.obliczNastawa();
        return wyjscieObiektu;
    }
    double getWartoscZadana() const { return regulator.getWartoscZadana(); }
};

int main() {
    rng.seed(srng());
    Generator generator(RodzajSygnalu::Skok, 66.0, 0.1, 30.0, 0.0);
    Regulator regulator(0.1, 5.0, 0.1);
    ObiektARX obiekt(1, 0.1, { 0.4, -0.3 }, { 0.2, 0.1 }, rng, 0.0, 0.2);
    SymulatorUAR symulator(generator, regulator, obiekt);

    for (double czas = 0.0; czas < 1000.0; czas += 1.0) {
            double wyjscieObiektu = symulator.symulujKrok(czas);
            cout << "Czas: " << czas
                << ", Wyjscie obiektu: " << wyjscieObiektu
                << ", Wartosc zadana: " << symulator.getWartoscZadana()
                << ", Zaklocenie: " << symulator.obiekt.getZaklocenie()
                << ", Ostatnia nastawa: " << symulator.regulator.getOstatniaNastawa() << endl;
    }
    return 0;
}
