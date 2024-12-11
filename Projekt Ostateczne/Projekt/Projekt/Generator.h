#pragma once


#include <cmath>
#include <random>

enum class RodzajSygnalu { Skok, Sinusoida, Prostokatny };

class Generator {
protected:
    RodzajSygnalu rodzaj;
    double A, T, p, czasAktywacji;

public:
    Generator(RodzajSygnalu r, double a, double t, double pp, double czasAkt = 0);
    double generuj(double czas);
};
