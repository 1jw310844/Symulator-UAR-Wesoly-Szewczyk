#ifndef REGULATOR_H
#define REGULATOR_H



class Regulator
{

    double wartoscZadana;
    double wzmocnienieP;
    double stalaI;
    double stalaD;
    double Uchyb;
    double WczesniejszyUchyb;
    double sumaUchybow;
    double ostatniaNastawa;
    double nastawaP;
    double nastawaI;
    double nastawaD;
public:

    Regulator();
    Regulator(double kp, double ki, double kd);
    void setWartoscZadana(double war);
    double getWartoscZadana() const;
    void aktualizujUchyb(double wartoscRegulowana);
    double obliczNastawa();
    double getOstatniaNastawa();
    double getUchyb();
    double getNastawaP();
    double getNastawaI();
    double getNastawaD();
    void ZerowanieNastawaI();
    void ZerowanieNastawaD();
    void setOstatniaNastawa(double on){ostatniaNastawa=on;}



};

#endif // REGULATOR_H
