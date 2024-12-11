#include "SymulatorUAR.h"

SymulatorUAR::SymulatorUAR(Generator g, Regulator r, ObiektARX o)
    : generator(g), regulator(r), obiekt(o) {}

double SymulatorUAR::symulujKrok(double czas) {
    double wartoscZadana = generator.generuj(czas);
    regulator.setWartoscZadana(wartoscZadana);
    poprzednieWyjscie = wyjscieObiektu;
    wyjscieObiektu = obiekt.obliczWyjscie(regulator.getOstatniaNastawa());
    regulator.aktualizujUchyb(wyjscieObiektu);
    obiekt.setZaklocenie(0.1, 0.3);
    double sygnalSterowania = regulator.obliczNastawa();
    return wyjscieObiektu;
}

double SymulatorUAR::getWartoscZadana() { return regulator.getWartoscZadana(); }
double SymulatorUAR::getZaklocenie() { return obiekt.getZaklocenie(); }
double SymulatorUAR::getOstatniaNastawa() { return regulator.getOstatniaNastawa(); }
double SymulatorUAR::getWyjscieObiektu() { return wyjscieObiektu; }
