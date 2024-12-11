#pragma once


#include <vector>
#include <random>

class ObiektARX {
protected:
    double k, z;
    std::vector<double> a;
    std::vector<double> b;
    std::vector<double> ui;
    std::vector<double> yi;
    double mean;
    double stdev;

    std::mt19937& generator;
    std::normal_distribution<double> zaklocenie;

    void zaktualizujZaklocenie();

public:
    ObiektARX(double kk, double zz, std::vector<double> aa, std::vector<double> bb, std::mt19937& gen, double mean = 0.3, double stdev = 0.0);
    void setZaklocenie(double newMean, double newStdev);
    double getZaklocenie();
    double obliczWyjscie(double uii);
};

