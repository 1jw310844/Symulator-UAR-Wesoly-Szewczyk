#include <iostream>
#include <cmath>
using namespace std;

enum class RodzajSygnalu { Skok, Sinusoida, Prostokatny };
const char* const rodzajSygnalu[3] = { "Skok", "Sinusoida", "Prostokatny" };

class Generator {
protected:
    RodzajSygnalu rodzaj;
    double A, T, p, czasAktywacji, i; 
public:
    // Konstruktor
    Generator(RodzajSygnalu r, double a, double t, double pp, double czasAkt = 0)
        : rodzaj(r), A(a), T(t), p(pp), czasAktywacji(czasAkt), i(0) {};

    // Generowanie wartości sygnału
    double generuj(double czas) {
        switch (rodzaj) {
        case RodzajSygnalu::Skok:
            // Skok jednostkowy: A, jeśli czas >= czas aktywacji, w przeciwnym razie 0
            return (czas >= czasAktywacji) ? A : 0;

        case RodzajSygnalu::Sinusoida:
            // Sinusoida: A * sin((2 * pi / T) * (czas mod T))
            return A * sin((2 * 3,1492 / T) * fmod(czas, T));

        case RodzajSygnalu::Prostokatny:
            // Prostokątny: A, jeśli (czas mod T) < p * T, w przeciwnym razie 0
            return (fmod(czas, T) < p * T) ? A : 0;

        default:
            return 0.0; // Domyślna wartość dla nieobsługiwanego typu
        }
    }

    // Wyświetlanie parametrów sygnału
    void wypiszParametry() {
        cout << "Rodzaj sygnału: " << (rodzaj == RodzajSygnalu::Skok ? "Skok" :
            rodzaj == RodzajSygnalu::Sinusoida ? "Sinusoida" : "Prostokatny")
            << ", Amplituda: " << A
            << ", Okres: " << T
            << ", Wypełnienie/Faza: " << p
            << ", Czas aktywacji (dla skoku): " << czasAktywacji << endl;
    }
};

int main() {
    // Tworzymy generator dla każdego typu sygnału

    // Skok jednostkowy
    Generator genSkok(RodzajSygnalu::Skok, 5.0, 0, 0, 2.0); // Amplituda = 5, aktywacja w t = 2

    // Sinusoida
    Generator genSinusoida(RodzajSygnalu::Sinusoida, 3.0, 10.0, 0); // Amplituda = 3, okres = 10

    // Sygnał prostokątny
    Generator genProstokatny(RodzajSygnalu::Prostokatny, 4.0, 8.0, 0.25); // Amplituda = 4, okres = 8, wypełnienie = 25%

    // Wyświetlamy parametry i generujemy sygnały
    cout << "Skok jednostkowy:" << endl;
    genSkok.wypiszParametry();
    for (double t = 0; t < 10; t += 1) {
        cout << "Czas: " << t << ", Wartość: " << genSkok.generuj(t) << endl;
    }

    cout << "\nSinusoida:" << endl;
    genSinusoida.wypiszParametry();
    for (double t = 0; t < 10; t += 1) {
        cout << "Czas: " << t << ", Wartość: " << genSinusoida.generuj(t) << endl;
    }

    cout << "\nSygnał prostokątny:" << endl;
    genProstokatny.wypiszParametry();
    for (double t = 0; t < 20; t += 1) {
        cout << "Czas: " << t << ", Wartość: " << genProstokatny.generuj(t) << endl;
    }

    return 0;
}
