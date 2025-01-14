#include "regulator.h"


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
Regulator::Regulator(){};
double Regulator::obliczNastawa() {
    nastawaP = wzmocnienieP * Uchyb;
    nastawaI = 0;
    if (stalaI != 0) {
        nastawaI = sumaUchybow / stalaI;
    }
    nastawaD = stalaD * (Uchyb - WczesniejszyUchyb);

    ostatniaNastawa = nastawaP + nastawaI + nastawaD;
    return ostatniaNastawa;
}

double Regulator::getOstatniaNastawa() {
    return ostatniaNastawa;
}
double Regulator::getUchyb(){
    return Uchyb;
}
double Regulator::getNastawaP(){
    return nastawaP;
}
double Regulator::getNastawaI(){
    return nastawaI;
}
double Regulator::getNastawaD(){
    return nastawaD;
}
void Regulator::ZerowanieNastawaD(){
    sumaUchybow=0;
    nastawaI=0;
}
void Regulator::ZerowanieNastawaI(){
    nastawaI=0;
    nastawaD =0;
}
