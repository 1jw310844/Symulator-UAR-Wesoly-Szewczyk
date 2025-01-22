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
    double getWzmocnienie(){return wzmocnienieP;}
    double getStalaI(){return stalaI;}
    double getStalaD(){return stalaD;}
    void ZerowanieNastawaI();
    void ZerowanieNastawaD();
    void setOstatniaNastawa(double on){ostatniaNastawa=on;}
    void setWzmocnienie(double w){wzmocnienieP=w;}
    void setStalaI(double si){stalaI=si;}
    void setStalaD(double sd){stalaD=sd;}



};

#endif // REGULATOR_H
