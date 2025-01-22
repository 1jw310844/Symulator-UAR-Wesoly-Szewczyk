#include "symulator.h"

symulator::symulator()
    : generator(), regulator(), obiekt() {}
symulator::symulator(Generator g, Regulator r, ObiektARX o)
    : generator(g), regulator(r), obiekt(o) {}

double symulator::symulujKrok(double czas) {
    double wartoscZadana = generator.generuj(czas);  // Używamy obiektu
    regulator.setWartoscZadana(wartoscZadana);
    poprzednieWyjscie = wyjscieObiektu;
    wyjscieObiektu = obiekt.obliczWyjscie(regulator.getOstatniaNastawa());
    setLastRegulatorValue(regulator.getOstatniaNastawa());
    setLastObjectOutput(wyjscieObiektu);
    regulator.aktualizujUchyb(wyjscieObiektu);
    obiekt.setZaklocenie(0.1, 0.3);
    double sygnalSterowania = regulator.obliczNastawa();
    return wyjscieObiektu;
}

double symulator::getWartoscZadana() { return regulator.getWartoscZadana(); }
double symulator::getZaklocenie() { return obiekt.getZaklocenie(); }
double symulator::getOstatniaNastawa() { return regulator.getOstatniaNastawa(); }
double symulator::getWyjscieObiektu() { return wyjscieObiektu; }
void symulator::setGenerator(Generator g) { generator = g; }
void symulator::setRegulator(Regulator r) { regulator = r; }
void symulator::setObiektARX(ObiektARX o) { obiekt = o; }
Generator symulator::getGenerator(){
    return generator;
};
Regulator symulator::getRegulator(){
    return regulator;
};
ObiektARX symulator::getObiektARX(){
    return obiekt;
};


