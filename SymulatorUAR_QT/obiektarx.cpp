#include "obiektarx.h"

ObiektARX::ObiektARX(){}

// Konstruktor z parametrami
ObiektARX::ObiektARX(double kk, double zz, std::vector<double> aa, std::vector<double> bb, std::mt19937 gen, double mean, double stdev)
    : k(kk), z(zz), a(aa), b(bb), ui(bb.size() + static_cast<int>(kk), 0),
    yi(aa.size(), 0), mean(mean), stdev(stdev), generator(gen), zaklocenie(mean, stdev)
{
}

void ObiektARX::setZaklocenie(double newMean, double newStdev) {
    mean = newMean;
    stdev = newStdev;
    zaktualizujZaklocenie();
}

double ObiektARX::getZaklocenie() {
    return z;
}

void ObiektARX::zaktualizujZaklocenie() {
    zaklocenie = std::normal_distribution<double>(mean, stdev);
}

double ObiektARX::obliczWyjscie(double uii) {
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
