#include "Regulator.h"

Regulator::Regulator(double kp, double ki, double kd)
    : wartoscZadana(0), wzmocnienieP(kp), stalaI(ki), stalaD(kd), Uchyb(0), WczesniejszyUchyb(0), sumaUchybow(0), ostatniaNastawa(0) {}

void Regulator::setWartoscZadana(double war) { wartoscZadana = war; }
double Regulator::getWartoscZadana() const { return wartoscZadana; }

void Regulator::aktualizujUchyb(double wartoscRegulowana) {
    WczesniejszyUchyb = Uchyb;
    Uchyb = wartoscZadana - wartoscRegulowana;
    if (stalaI != 0) {
        sumaUchybow += Uchyb;
    }
}

double Regulator::obliczNastawa() {
    double nastawaP = wzmocnienieP * Uchyb;
    double nastawaI = 0;
    if (stalaI != 0) {
        nastawaI = sumaUchybow / stalaI;
    }
    double nastawaD = stalaD * (Uchyb - WczesniejszyUchyb);

    ostatniaNastawa = nastawaP + nastawaI + nastawaD;
    return ostatniaNastawa;
}

double Regulator::getOstatniaNastawa() {
    return ostatniaNastawa;
}
