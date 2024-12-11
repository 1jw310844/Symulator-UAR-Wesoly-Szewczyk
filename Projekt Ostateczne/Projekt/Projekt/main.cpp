#include <iostream>
#include <random>
#include "SymulatorUAR.h"
#include "Generator.h"
#include "Regulator.h"
#include "ObiektARX.h"

std::random_device srng;
std::mt19937 rng;

int main() {
    rng.seed(srng());
    Generator generator(RodzajSygnalu::Skok, 66.0, 0.1, 30.0, 0.0);
    Regulator regulator(0.1, 5.0, 0.1);
    ObiektARX obiekt(1, 0.1, { 0.4, -0.3 }, { 0.2, 0.1 }, rng, 0.0, 0.2);
    SymulatorUAR symulator(generator, regulator, obiekt);

    for (double czas = 0.0; czas < 100.0; czas += 1.0) {
        double wyjscieObiektu = symulator.symulujKrok(czas);
        std::cout << "Czas: " << czas
            << ", Wyjscie obiektu: " << symulator.getWyjscieObiektu()
            << ", Wartosc zadana: " << symulator.getWartoscZadana()
            << ", Zaklocenie: " << symulator.getZaklocenie()
            << ", Ostatnia nastawa: " << symulator.getOstatniaNastawa()
            << std::endl;
    }

    return 0;
}
