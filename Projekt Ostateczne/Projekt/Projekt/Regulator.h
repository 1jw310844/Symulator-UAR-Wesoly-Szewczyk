#pragma once


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
    Regulator(double kp, double ki, double kd);
    void setWartoscZadana(double war);
    double getWartoscZadana() const;
    void aktualizujUchyb(double wartoscRegulowana);
    double obliczNastawa();
    double getOstatniaNastawa();
};

