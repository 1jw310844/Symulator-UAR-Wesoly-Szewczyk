#include "warstwauslug.h"

WarstwaUslug::WarstwaUslug(QObject *parent)
    : QObject{parent}, s(new symulator())
{
    qDebug() << "WarstwaUslug constructor";
    qDebug() << "symulator zainicjalizowany";
}

void WarstwaUslug::SprawdzenieGeneratora(Generator* g){
    qDebug() << "SprawdzenieGeneratora: " << g->getAmplituda() << ", " << g->getOkres() << ", " << g->getWypelnienie();
    if(g->getRodzaj() == RodzajSygnalu::Skok && g->getAmplituda() > 0) {
        s->setGenerator(*g);
        qDebug() << "Generator ustawiony (Skok)";
    } else if(g->getRodzaj() == RodzajSygnalu::Sinusoida && g->getAmplituda() > 0 && g->getOkres() > 0) {
        s->setGenerator(*g);
        qDebug() << "Generator ustawiony (Sinusoida)";
    } else if(g->getRodzaj() == RodzajSygnalu::Prostokatny && g->getAmplituda() > 0 && g->getOkres() > 0 && g->getWypelnienie() > 0 && g->getWypelnienie() <= 1) {
        s->setGenerator(*g);
        qDebug() << "Generator ustawiony (Prostokatny)";
    } else {
        qDebug() << "Błędny generator";
    }
    qDebug() << "Aktualny stan generatora: " << s->getGenerator().getAmplituda();
}

void WarstwaUslug::SprawdzenieRegulatora(Regulator* r){
    qDebug() << "SprawdzenieRegulatora: " << r->getStalaD() << ", " << r->getStalaI() << ", " << r->getWzmocnienie();
    if(r->getStalaD() >= 0 && r->getStalaI() >= 0 && r->getWzmocnienie() >= 0) {
        if(r->getStalaD() > 0 || r->getStalaI() > 0 || r->getWzmocnienie() > 0) {
            s->setRegulator(*r);
            qDebug() << "Regulator ustawiony";
        } else {
            qDebug() << "Błędny regulator";
        }
    } else {
        qDebug() << "Błędne parametry regulatora";
    }
    qDebug() << "Aktualny stan regulatora: " << s->getRegulator().getWzmocnienie();
}

void WarstwaUslug::SprawdzenieObiektu(ObiektARX* o){
    qDebug() << "SprawdzenieObiektu: " << o->getOpoznienie() << ", " << o->getWielomianA() << ", " << o->getWielomianB();
    int a = 0, b = 0;
    for(double wsp : o->getWielomianA()) {
        if(wsp == 0) a++;
    }
    for(double wsp : o->getWielomianB()) {
        if(wsp == 0) b++;
    }
    if(b != 3 && a != 3 && o->getOpoznienie() >= 0) {
        s->setObiektARX(*o);
        qDebug() << "Obiekt ustawiony";
    } else {
        qDebug() << "Błędny obiekt";
    }
    qDebug() << "Aktualny stan obiektu: " << s->getObiektARX().getOpoznienie();
}

void WarstwaUslug::SprawdzenieWszystkichDanych() {
    bool poprawnyGenerator = true;
    bool poprawnyRegulator = true;
    bool poprawnyObiekt = true;

    // Sprawdzenie generatora
    Generator generator = s->getGenerator();
    qDebug() << "Sprawdzanie generatora: " <<generator.getWypelnienie();
    if (generator.getRodzaj() == RodzajSygnalu::Skok && generator.getAmplituda() <= 0) {
        poprawnyGenerator = false;
    } else if (generator.getRodzaj() == RodzajSygnalu::Sinusoida &&
               (generator.getAmplituda() <= 0 || generator.getOkres() <= 0)) {
        poprawnyGenerator = false;
    } else if (generator.getRodzaj() == RodzajSygnalu::Prostokatny &&
               (generator.getAmplituda() <= 0 || generator.getOkres() <= 0 ||
                generator.getWypelnienie() <= 0 || generator.getWypelnienie() > 1)) {
        poprawnyGenerator = false;
    }

    // Sprawdzenie regulatora
    Regulator regulator = s->getRegulator();
    qDebug() << "Sprawdzanie regulatora: " << regulator.getStalaD();
    if (regulator.getStalaD() < 0 || regulator.getStalaI() < 0 || regulator.getWzmocnienie() < 0 ||
        (regulator.getStalaD() == 0 && regulator.getStalaI() == 0 && regulator.getWzmocnienie() == 0)) {
        poprawnyRegulator = false;
    }

    // Sprawdzenie obiektu
    ObiektARX obiekt = s->getObiektARX();
    qDebug() << "Sprawdzanie obiektu: " << obiekt.getOpoznienie();
    int liczbaZerA = 0;
    int liczbaZerB = 0;

    for (double wsp : obiekt.getWielomianA()) {
        if (wsp == 0) liczbaZerA++;
    }

    for (double wsp : obiekt.getWielomianB()) {
        if (wsp == 0) liczbaZerB++;
    }

    if (liczbaZerA == 3 || liczbaZerB == 3 || obiekt.getOpoznienie() < 0) {
        poprawnyObiekt = false;
    }

    if (!poprawnyGenerator || !poprawnyRegulator || !poprawnyObiekt) {
        emit BledneDane();
        qDebug() << "Błędne dane - sprawdź generator, regulator i obiekt.";
    } else {
        emit PoprawneDane(s);
        qDebug() << "Dane poprawne - generowanie wykresów.";
    }
}


