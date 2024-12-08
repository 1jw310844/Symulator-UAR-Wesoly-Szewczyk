#include <iostream>
#include <vector>
using namespace std;

class ObiektARX
{
protected:
    double k, z, a1, a2, a3, b1, b2, b3, yi;
    int i = 0;
    vector<double> a = {a1, a2, a3};
    vector<double> b = {b1, b2, b3};
    vector<double> ui = {};
    
public:
    //konstruktor argumentowy
    ObiektARX(double kk, double zz, double a11, double a22, double a33, double b11, double b22, double b33, int ii, double yii)
        :k(kk), z(zz), a1(a11), a2(a22), a3(a33), b1(b11), b2(b22), b3(b33), i(ii), yi(yii) {}
    
    //destruktor
    ~ObiektARX() 
    {
        cout << "Destruktor wywołany. ObiektARX usunięty." << endl;
    }

    //opóźnienie transportowe
    void setK(double  kk)
    {
        k = kk;
    }
    double getK() { return k; }

    //zakłócenie
    void setZ(double zz)
    {
        z = zz;
    }
    double getZ() { return z; }


    void setAllA(double a11, double a22, double a33)
    {
        a1 = a11;
        a2 = a22;
        a3 = a33;
    }
    double getA() { return a1, a2, a3; }

    void setAllB(double b11, double b22, double b33)
    {
        b1 = b11;
        b2 = b22;
        b3 = b33;
    }
    double getB() { return b1, b2, b3; }
    
    //numer chwili czasowej
    void setI(int ii)
    {
        i = ii;
    }
    int getI() { return i; }

    void setA(double aa)
    {
        a.push_back(aa);
        a.erase(a.begin());
    }
    void setB(double bb)
    {
        b.push_back(bb);
        b.erase(b.begin());
    }

    //sygnał wejściowy
    void setUi(double uii[)
    {
        ui.push_back(uii);
        ui.erase(ui.begin());
    }
    double getUi(int ii) { return ui[ii]; }
    
    double obliczWyjscie(double uii)
    {
        
    }
};

