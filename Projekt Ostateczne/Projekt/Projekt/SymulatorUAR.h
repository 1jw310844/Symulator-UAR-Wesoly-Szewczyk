#pragma once


#include "Generator.h"
#include "Regulator.h"
#include "ObiektARX.h"

class SymulatorUAR {
protected:
    Generator generator;
    double poprzednieWyjscie = 0;
    double wyjscieObiektu = 0;
    Regulator regulator;
    ObiektARX obiekt;

public:
    SymulatorUAR(Generator g, Regulator r, ObiektARX o);
    double symulujKrok(double czas);
    double getWartoscZadana();
    double getZaklocenie();
    double getOstatniaNastawa();
    double getWyjscieObiektu();
};


