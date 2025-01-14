#ifndef SYMULATOR_H
#define SYMULATOR_H


#include "Generator.h"
#include "Regulator.h"
#include "ObiektARX.h"

class symulator
{

    Generator generator;       // Generator przechowywany jako obiekt
    double poprzednieWyjscie = 0;
    double wyjscieObiektu = 0;
    Regulator regulator;       // Regulator przechowywany jako obiekt
    ObiektARX obiekt;
    double lastRegulatorValue = 0;
    double lastObjectOutput = 0 ;       // Obiekt ARX przechowywany jako obiekt
public:

    symulator();
    symulator(Generator g, Regulator r, ObiektARX o);
    double symulujKrok(double czas);
    double getWartoscZadana();
    double getZaklocenie();
    double getOstatniaNastawa();
    double getWyjscieObiektu();
    void setGenerator(Generator g);
    void setRegulator(Regulator r);
    void setObiektARX(ObiektARX o);
    Generator getGenerator();
    Regulator getRegulator();
    ObiektARX getObiektARX();
    void setLastRegulatorValue(double value) { lastRegulatorValue = value; }
    void setLastObjectOutput(double value) { lastObjectOutput = value; }

    double getLastRegulatorValue()  { return lastRegulatorValue; }
    double getLastObjectOutput()  { return lastObjectOutput; }
    void setWyjscieObiektu(double wo){wyjscieObiektu=wo;};

};

#endif // SYMULATOR_H

