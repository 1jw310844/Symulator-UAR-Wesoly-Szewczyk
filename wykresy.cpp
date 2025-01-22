#include "wykresy.h"

Wykresy::Wykresy(QWidget *parent)
    : QObject(nullptr),parent(parent)
{
    s=new symulator();
}
void Wykresy::wyczyscLayout(QLayout* layout) {
    if (!layout) return;
    while (QLayoutItem* item = layout->takeAt(0)) {
        if (QWidget* widget = item->widget()) {
            widget->deleteLater();
        }
        if (QLayout* childLayout = item->layout()) {
            wyczyscLayout(childLayout);
        }
        delete item;
    }
}

void Wykresy::inicjalizacjaWykresuWartosciZadanej(QVBoxLayout *layout){
    wyczyscLayout(layout);

    // Tworzenie serii danych
    seria[0] = new QLineSeries();
    seria[1] = new QLineSeries();
    seria[0]->setName("Wartość Regulowana");
    seria[1]->setName("Wartość Zadana");
    seria[1]->setColor(Qt::red); // Zmiana koloru drugiej serii

    // Tworzenie wykresu
    wykres[0] = new QChart();
    wykres[0]->addSeries(seria[0]);
    wykres[0]->addSeries(seria[1]);


    // Tworzenie osi X i Y
    osX[0] = new QValueAxis();
    osX[0]->setRange(0, 30); // Początkowy zakres dla osi X
    osY[0] = new QValueAxis();

    // Ustawienie początkowego zakresu osi Y
    osY[0]->setRange(0, s->getWartoscZadana());

    // Dodanie osi X i Y do wykresu
    wykres[0]->addAxis(osX[0], Qt::AlignBottom);
    wykres[0]->addAxis(osY[0], Qt::AlignLeft);

    // Powiązanie osi z serią danych
    seria[0]->attachAxis(osX[0]);
    seria[0]->attachAxis(osY[0]);

    // Powiązanie osi Y z drugą serią
    seria[1]->attachAxis(osX[0]);
    seria[1]->attachAxis(osY[0]);
    // Tworzenie widoku wykresu
    Widok[0] = new QChartView(wykres[0]);
    Widok[0]->setRenderHint(QPainter::Antialiasing);
    Widok[0]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    //Dodanie wykresu do widoku w UI

    layout->addWidget(Widok[0]);
}
void Wykresy::inicjalizacjaWykresuUchybu(QVBoxLayout *layout){
    wyczyscLayout(layout);

    seria[2] = new QLineSeries();
    seria[2]->setName("Wartość Uchybu");
    wykres[1] = new QChart();
    wykres[1]->addSeries(seria[2]);

    osX[1] = new QValueAxis();
    osX[1]->setRange(0, 30);
    osY[1] = new QValueAxis();

    osY[1]->setRange(0, s->getRegulator().getUchyb());

    wykres[1]->addAxis(osX[1], Qt::AlignBottom);
    wykres[1]->addAxis(osY[1], Qt::AlignLeft);

    seria[2]->attachAxis(osX[1]);
    seria[2]->attachAxis(osY[1]);

    Widok[1] = new QChartView(wykres[1]);
    Widok[1]->setRenderHint(QPainter::Antialiasing);
    Widok[1]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    layout->addWidget(Widok[1]);
}
void Wykresy::inicjalizacjaWykresuPID(QVBoxLayout *layout){
    wyczyscLayout(layout);
    seria[3] = new QLineSeries();
    seria[3]->setName("Proporcjonalna");
    seria[4] = new QLineSeries();
    seria[4]->setColor(Qt::red);
    seria[4]->setName("Całkująca");
    seria[5] = new QLineSeries();
    seria[5]->setColor(Qt::black);
    seria[5]->setName("Różniczkująca");

    wykres[2] = new QChart();
    wykres[2]->addSeries(seria[3]);
    wykres[2]->addSeries(seria[4]);
    wykres[2]->addSeries(seria[5]);

    osX[2] = new QValueAxis();
    osX[2]->setRange(0, 30);
    osY[2] = new QValueAxis();

    osY[2]->setRange(0, s->getRegulator().getOstatniaNastawa());

    wykres[2]->addAxis(osX[2], Qt::AlignBottom);
    wykres[2]->addAxis(osY[2], Qt::AlignLeft);

    seria[3]->attachAxis(osX[2]);
    seria[3]->attachAxis(osY[2]);
    seria[4]->attachAxis(osX[2]);
    seria[4]->attachAxis(osY[2]);
    seria[5]->attachAxis(osX[2]);
    seria[5]->attachAxis(osY[2]);
    Widok[2] = new QChartView(wykres[2]);
    Widok[2]->setRenderHint(QPainter::Antialiasing);
    Widok[2]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    layout->addWidget(Widok[2]);
}
void Wykresy::inicjalizacjaWykresuWartosciSterowania(QVBoxLayout *layout){
    wyczyscLayout(layout);
    seria[6] = new QLineSeries();
    seria[6]->setName("Wartość Sterująca");
    wykres[3] = new QChart();
    wykres[3]->addSeries(seria[6]);
    osX[3] = new QValueAxis();
    osX[3]->setRange(0, 30);
    osY[3] = new QValueAxis();

    osY[3]->setRange(0, s->getRegulator().getOstatniaNastawa());

    wykres[3]->addAxis(osX[3], Qt::AlignBottom);
    wykres[3]->addAxis(osY[3], Qt::AlignLeft);

    seria[6]->attachAxis(osX[3]);
    seria[6]->attachAxis(osY[3]);

    Widok[3] = new QChartView(wykres[3]);
    Widok[3]->setRenderHint(QPainter::Antialiasing);
    Widok[3]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);


    layout->addWidget(Widok[3]);
}
void Wykresy::WykresWartosciZadanej(){
    // Symulacja kolejnego kroku
    double wyjscieObiektu = s->symulujKrok(czas);

    // Dodanie nowego punktu do serii danych
    seria[0]->append(czas, wyjscieObiektu);
    seria[1]->append(czas, s->getWartoscZadana());

    // Usuwanie starych punktów, aby seria była "przesuwana"
    const int maxPoints = 30; // Maksymalna liczba widocznych punktów
    if (seria[0]->count() > maxPoints) {
        seria[0]->remove(0); // Usunięcie najstarszego punktu
        seria[1]->remove(0); // Usunięcie najstarszego punktu z wartości zadanej
    }

    // Przesunięcie osi X w miarę przybywania nowych punktów
    if (czas > 30) {
        osX[0]->setRange(czas - 30, czas); // Przesunięcie osi X
    }

    // Zmienna dla zakresu osi Y
    double minY = 0.0, maxY = 0.0;

    // Pobranie generatora i jego parametrów
    Generator generator = s->getGenerator();
    double wartoscZadana = s->getWartoscZadana();
    double margin = 2.0; // Margines do dodania

    // Ustawienie zakresu osi Y w zależności od rodzaju sygnału
    if (generator.getRodzaj() == RodzajSygnalu::Skok) {
        minY = 0; // Minimalna wartość dla skoku
        maxY = wartoscZadana; // Maksymalna wartość
    }
    else if (generator.getRodzaj() == RodzajSygnalu::Sinusoida) {
        double amplituda = generator.getAmplituda();
        minY = -amplituda; // Minimalna wartość dla sinusoidy
        maxY = amplituda;  // Maksymalna wartość dla sinusoidy
    }
    else if (generator.getRodzaj() == RodzajSygnalu::Prostokatny) {
        // Ustawiamy minimalny i maksymalny zakres osi Y
        minY = 0; // Minimalna wartość dla prostokątnego sygnału
        maxY = wartoscZadana;
    }

    // Ustawienie zakresu osi Y z marginesem
    osY[0]->setRange(minY - margin, maxY + margin); // Dodanie marginesu

    czas++;
}
void Wykresy::WykresUchybu(){
    // Symulacja kolejnego kroku
    double wyjscieObiektu = s->symulujKrok(czas);
    Q_UNUSED(wyjscieObiektu);
    // Dodaj punkt do wykresu uchybu
    double uchyb = s->getRegulator().getUchyb();
    seria[2]->append(czas, uchyb);

    // Usuwanie starych punktów, aby seria była "przesuwana"
    const int maxPoints = 30; // Maksymalna liczba widocznych punktów
    if (seria[2]->count() > maxPoints) {
        seria[2]->remove(0); // Usunięcie najstarszego punktu
    }

    // Ustawienie zakresu osi X, przesuwanie w prawo
    if (czas > 30) {
        osX[1]->setRange(czas - 30, czas); // Przesunięcie osi X
    }

    // Dynamically adjust Y axis range based on the current minimum and maximum values of uchyb
    double minY = uchyb;
    double maxY = uchyb;

    // Przeszukaj całą serię punktów, aby znaleźć minimum i maksimum
    for (int i = 0; i < seria[2]->count(); ++i) {
        double yValue = seria[2]->at(i).y();
        if (yValue < minY) {
            minY = yValue;
        }
        if (yValue > maxY) {
            maxY = yValue;
        }
    }

    // Dodaj margines do zakresu Y, aby lepiej widoczny był wykres
    double margin = 0.1 * (maxY - minY); // 10% marginesu wokół wartości minimum i maksimum
    osY[1]->setRange(minY - margin, maxY + margin);

    // Zwiększenie czasu
    czas++;
}
void Wykresy::WykresPID(){
    // Symulacja kolejnego kroku
    double wyjscieObiektu = s->symulujKrok(czas);
    Q_UNUSED(wyjscieObiektu);
    Regulator regulator = s->getRegulator();

    // Dodanie nowego punktu do serii danych
    seria[3]->append(czas, regulator.getNastawaP());
    seria[4]->append(czas, regulator.getNastawaI());
    seria[5]->append(czas, regulator.getNastawaD());

    // Usuwanie starych punktów, aby seria była "przesuwana"
    const int maxPoints = 30; // Maksymalna liczba widocznych punktów
    if (seria[3]->count() > maxPoints) {
        seria[3]->remove(0);
        seria[4]->remove(0);
        seria[5]->remove(0);
    }

    // Przesunięcie osi X w miarę przybywania nowych punktów
    if (czas > maxPoints) {
        osX[2]->setRange(czas - maxPoints, czas); // Przesunięcie osi X
    }


    double minY = std::numeric_limits<double>::max();  // Inicjalizujemy jako bardzo dużą wartość
    double maxY = std::numeric_limits<double>::lowest();  // Inicjalizujemy jako bardzo małą wartość


    for (int i = 0; i < seria[3]->count(); ++i) {
        double yValueP = seria[3]->at(i).y();
        double yValueI = seria[4]->at(i).y();
        double yValueD = seria[5]->at(i).y();


        minY = std::min({minY, yValueP, yValueI, yValueD});
        maxY = std::max({maxY, yValueP, yValueI, yValueD});
    }


    double margin = 5.0;
    minY -= margin;
    maxY += margin;




    if (osY[2]->min() != minY || osY[2]->max() != maxY) {
        osY[2]->setRange(minY, maxY);
    }


    czas++;
}

void Wykresy::WykresWartosciSterowania(){
    // Symulacja kolejnego kroku
    double wyjscieObiektu = s->symulujKrok(czas);
    Q_UNUSED(wyjscieObiektu);
    double Sterujaca = s->getRegulator().getOstatniaNastawa();
    seria[3]->append(czas, Sterujaca);

    // Usuwanie starych punktów, aby seria była "przesuwana"
    const int maxPoints = 30; // Maksymalna liczba widocznych punktów
    if (seria[3]->count() > maxPoints) {
        seria[3]->remove(0); // Usunięcie najstarszego punktu
    }

    // Ustawienie zakresu osi X, przesuwanie w prawo
    if (czas > 30) {
        osX[3]->setRange(czas - 30, czas); // Przesunięcie osi X
    }

    // Dynamically adjust Y axis range based on the current minimum and maximum values of uchyb
    double minY = Sterujaca;
    double maxY = Sterujaca;

    // Przeszukaj całą serię punktów, aby znaleźć minimum i maksimum
    for (int i = 0; i < seria[3]->count(); ++i) {
        double yValue = seria[3]->at(i).y();
        if (yValue < minY) {
            minY = yValue;
        }
        if (yValue > maxY) {
            maxY = yValue;
        }
    }

    // Dodaj margines do zakresu Y, aby lepiej widoczny był wykres
    double margin = 0.1 * (maxY - minY); // 10% marginesu wokół wartości minimum i maksimum
    osY[3]->setRange(minY - margin, maxY + margin);

    // Zwiększenie czasu
    czas++;
}
void Wykresy::AktualizujWykresy(){
    WykresWartosciZadanej();
    WykresUchybu();
    WykresPID();
    WykresWartosciSterowania();
}
void Wykresy::InicjalizujWykresy(QVBoxLayout *layout ){
    inicjalizacjaWykresuWartosciZadanej(layout);
    inicjalizacjaWykresuUchybu(layout);
    inicjalizacjaWykresuPID(layout);
    inicjalizacjaWykresuWartosciSterowania(layout);
}

