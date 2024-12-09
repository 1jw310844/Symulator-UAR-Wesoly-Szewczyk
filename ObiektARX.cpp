#include <iostream>
#include <vector>
using namespace std;

class ObiektARX
{
protected:
    double k, z, a1, a2, a3, b1, b2, b3;
    int i = 0;
    vector<double> a = {a1, a2, a3};
    vector<double> b = {b1, b2, b3};
    vector<double> ui = {};
    vector<double> yi = {};
    
public:
    //konstruktor argumentowy
    ObiektARX(double kk, double zz, double a11, double a22, double a33, double b11, double b22, double b33, int ii, double yii)
        :k(kk), z(zz), a1(a11), a2(a22), a3(a33), b1(b11), b2(b22), b3(b33), i(ii){}
    
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
    
    void setAllB(double b11, double b22, double b33)
    {
        b1 = b11;
        b2 = b22;
        b3 = b33;
    }
    vector<double> getA() { return a; }
    vector<double> getB() { return b; }

    
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
    void setUi(double uii)
    {
        ui.push_back(uii);
        ui.erase(ui.begin());
    }
    double getUi(int chwilaCzasowa) { return ui[chwilaCzasowa]; }

    //sygnał wyjściowy
    void setYi(double yii)
    {
        yi.push_back(yii);
        yi.erase(yi.begin());
    }
    double getYi(int chwilaCzasowa) { return yi[chwilaCzasowa]; }
    
    
    double obliczWyjscie(double uii) 
    {
            // Dodaj nową wartość wejściową do wektora
            ui.push_back(uii);
            if (ui.size() > b.size() + k) 
            {
                ui.erase(ui.begin());
            }

            // Oblicz wyjście na podstawie równania ARX
            double wynik = 0.0;

            // Część oparta na sygnale wejściowym (współczynniki b)
            for (size_t j = 0; j < b.size(); ++j) 
            {
                if (i - k - j >= 0 && i - k - j < ui.size()) 
                {
                    wynik += b[j] * ui[ui.size() - 1 - (k + j)];
                }
            }

            // Część oparta na sygnale wyjściowym (współczynniki a)
            for (size_t j = 0; j < a.size(); ++j) 
            {
                if (i - 1 - j >= 0 && i - 1 - j < yi.size()) 
                {
                    wynik -= a[j] * yi[yi.size() - 1 - (1 + j)];
                }
            }

            // Dodaj zakłócenie
            wynik += z;

            // Dodaj wynik do wektora yi
            yi.push_back(wynik);
            if (yi.size() > a.size()) 
            {
                yi.erase(yi.begin());
            }

            // Zwiększ numer chwili czasowej
            ++i;

            return wynik;
    } 
   /*
        vector<double> splotWektorowy(const vector<double>& x, const vector<double>& h)
    {        
        size_t n = x.size();
        size_t m = h.size();
        vector<double> iloczyn(n + m - 1, 0.0);
        for (size_t i = 0; i < iloczyn.size(); ++i) 
        {            
            for (size_t j = 0; j < h.size(); ++j) 
            {
                if (i >= j && (i - j) < x.size()) 
                {
                    iloczyn[i] += x[i - j] * h[j];
                }
            }
        }
        return iloczyn;
    }
   */ 
};

