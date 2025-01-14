#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>

std::random_device srng;
std::mt19937 rng;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,s()
    ,czas(0.0)


{
    ui->setupUi(this);
    this->showMaximized();
    this->setStyleSheet("background-color: gray;");
    ui->pushButton->setStyleSheet(
        "QPushButton {"
        "    background-color: white;"
        "    border-radius: 5px;"
        "    border: 1px solid black;"
        "}"
        "QPushButton:hover {"
        "    background-color: lightgray;"
        "    color: gray;"  // Zmieniamy również kolor tekstu na biały przy najechaniu
        "}"
        );
    ui->pushButton_2->setStyleSheet(
        "QPushButton {"
        "    background-color: white;"
        "    border-radius: 5px;"
        "    border: 1px solid black;"
        "}"
        "QPushButton:hover {"
        "    background-color: lightgray;"
        "    color: gray;"  // Zmieniamy również kolor tekstu na biały przy najechaniu
        "}"
        );
    ui->pushButton_3->setStyleSheet(
        "QPushButton {"
        "    background-color: white;"
        "    border-radius: 5px;"
        "    border: 1px solid black;"
        "}"
        "QPushButton:hover {"
        "    background-color: lightgray;"
        "    color: gray;"  // Zmieniamy również kolor tekstu na biały przy najechaniu
        "}"
        );
    ui->StalaD->setStyleSheet("background-color:white");
    ui->StalaI->setStyleSheet("background-color:white");
    ui->A1->setStyleSheet("background-color:white");
    ui->A2->setStyleSheet("background-color:white");
    ui->A3->setStyleSheet("background-color:white");
    ui->B1->setStyleSheet("background-color:white");
    ui->B2->setStyleSheet("background-color:white");
    ui->B3->setStyleSheet("background-color:white");
    ui->Interwal->setStyleSheet("background-color:white");
    ui->SkokWartosc->setStyleSheet("background-color:white");
    ui->ProstokatnyAmplituda->setStyleSheet("background-color:white");
    ui->SinusoidaAmplituda->setStyleSheet("background-color:white");
    ui->SinusoidaOkres->setStyleSheet("background-color:white");
    ui->ProstokatnyWypelnienie->setStyleSheet("background-color:white");
    ui->ProstokatnyOkres->setStyleSheet("background-color:white");
    ui->Wzmocnienie->setStyleSheet("background-color:white");
    ui->Opoznienie->setStyleSheet("background-color:white");
    ui->ustawObiekt->setStyleSheet("background-color:white");
      ui->ustawRegulator->setStyleSheet("background-color:white");
    if(czas==0.0){
        initializeChart();
        initializeChartUchyb();
        initializeChartPID();
    }






    // Ustawienie timera
    simulationTimer = new QTimer(this);
    connect(simulationTimer, &QTimer::timeout, this, &MainWindow::updateChart);
    connect(simulationTimer, &QTimer::timeout, this, &MainWindow::updateChartUchyb);
    connect(simulationTimer, &QTimer::timeout, this, &MainWindow::updateChartPID);

}
void MainWindow::initializeChart()
{
    // Tworzenie serii danych
    series = new QLineSeries();
    seriesWartoscZadana = new QLineSeries();
    seriesWartoscZadana->setColor(Qt::red); // Zmiana koloru drugiej serii

    // Tworzenie wykresu
    chart = new QChart();
    chart->addSeries(series);
    chart->addSeries(seriesWartoscZadana);
    chart->legend()->setVisible(false);

    // Tworzenie osi X i Y
    axisX = new QValueAxis();
    axisX->setRange(0, 30); // Początkowy zakres dla osi X
    axisY = new QValueAxis();

    // Ustawienie początkowego zakresu osi Y
    axisY->setRange(0, s.getWartoscZadana());

    // Dodanie osi X i Y do wykresu
    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);

    // Powiązanie osi z serią danych
    series->attachAxis(axisX);
    series->attachAxis(axisY);

    // Powiązanie osi Y z drugą serią
    seriesWartoscZadana->attachAxis(axisX);
    seriesWartoscZadana->attachAxis(axisY);

    // Tworzenie widoku wykresu
    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // Dodanie wykresu do widoku w UI
    QVBoxLayout *layout = new QVBoxLayout();
    layout->setContentsMargins(0, 0, 0, 0);  // Usunięcie marginesów
    ui->widgetChart->setLayout(layout);

    // Dodanie wykresu do layoutu
    layout->addWidget(chartView);
}

void MainWindow::updateChart()
{
    // Symulacja kolejnego kroku
    double wyjscieObiektu = s.symulujKrok(czas);

    // Dodanie nowego punktu do serii danych
    series->append(czas, wyjscieObiektu);
    seriesWartoscZadana->append(czas, s.getWartoscZadana());

    // Usuwanie starych punktów, aby seria była "przesuwana"
    const int maxPoints = 100; // Maksymalna liczba widocznych punktów
    if (series->count() > maxPoints) {
        series->remove(0); // Usunięcie najstarszego punktu
        seriesWartoscZadana->remove(0); // Usunięcie najstarszego punktu z wartości zadanej
    }

    // Przesunięcie osi X w miarę przybywania nowych punktów
    if (czas > 30) {
        axisX->setRange(czas - 30, czas); // Przesunięcie osi X
    }

    // Zmienna dla zakresu osi Y
    double minY = 0.0, maxY = 0.0;

    // Pobranie generatora i jego parametrów
    Generator generator = s.getGenerator();
    double wartoscZadana = s.getWartoscZadana();
    double margin = 2.0; // Margines do dodania (można dostosować)

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
        double amplituda = wartoscZadana;

        // Określamy okres (generator powinien mieć okres)
        double okres = generator.getOkres();

        // Oblicz czas, w którym sygnał powinien być w stanie wysokim
        double czasWysoki = okres * generator.getWypelnienie();  // Wypełnienie jako procent

        // Obliczamy wartość sygnału na podstawie czasu i wypełnienia
        double signalValue = (static_cast<int>(czas) % static_cast<int>(okres) < czasWysoki) ? amplituda : 0;

        // Ustawiamy minimalny i maksymalny zakres osi Y
        minY = 0; // Minimalna wartość dla prostokątnego sygnału
        maxY = amplituda;
    }

    // Ustawienie zakresu osi Y z marginesem
    axisY->setRange(minY - margin, maxY + margin); // Dodanie marginesu

    // Debugowanie
    qDebug() << "Czas: " << czas
             << ", Wyjście obiektu: " << wyjscieObiektu
             << ", Wartość zadana: " << wartoscZadana
             << ", Zakłócenie: " << s.getZaklocenie()
             << ", Ostatnia nastawa: " << s.getOstatniaNastawa() << Qt::endl;

    // Zwiększenie czasu
    czas++;
}




void MainWindow::initializeChartUchyb()
{
    // Tworzenie serii danych
    seriesUchyb = new QLineSeries();
    chartUchyb = new QChart();
    chartUchyb->addSeries(seriesUchyb);
    axisXUchyb = new QValueAxis();
    axisXUchyb->setRange(0, 30); // Początkowy zakres dla osi X
    axisYUchyb = new QValueAxis();
    axisYUchyb->setRange(0, s.getRegulator().getUchyb());
    chartUchyb->legend()->setVisible(false);
    // Dodanie osi X i Y do wykresu
    chartUchyb->addAxis(axisXUchyb, Qt::AlignBottom);
    chartUchyb->addAxis(axisYUchyb, Qt::AlignLeft);

    // Powiązanie osi z serią danych
    seriesUchyb->attachAxis(axisXUchyb);
    seriesUchyb->attachAxis(axisYUchyb);
    // Tworzenie widoku wykresu
    chartViewUchyb = new QChartView(chartUchyb);
    chartViewUchyb->setRenderHint(QPainter::Antialiasing);
    chartViewUchyb->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // Dodanie wykresu do widoku w UI
    QVBoxLayout *layout = new QVBoxLayout();
    layout->setContentsMargins(0, 0, 0, 0);  // Usunięcie marginesów
    ui->widgetChart_2->setLayout(layout);

    // Dodanie wykresu do layoutu
    layout->addWidget(chartViewUchyb);
}

void MainWindow::updateChartUchyb()
{
    // Symulacja kolejnego kroku
    double wyjscieObiektu = s.symulujKrok(czas);

    // Dodaj punkt do wykresu uchybu
    double uchyb = s.getRegulator().getUchyb();
    seriesUchyb->append(czas, uchyb);

    // Usuwanie starych punktów, aby seria była "przesuwana"
    const int maxPoints = 100; // Maksymalna liczba widocznych punktów
    if (seriesUchyb->count() > maxPoints) {
        seriesUchyb->remove(0); // Usunięcie najstarszego punktu
    }

    // Ustawienie zakresu osi X, przesuwanie w prawo
    if (czas > 30) {
        axisXUchyb->setRange(czas - 30, czas); // Przesunięcie osi X
    }

    // Dynamically adjust Y axis range based on the current minimum and maximum values of uchyb
    double minY = uchyb;
    double maxY = uchyb;

    // Przeszukaj całą serię punktów, aby znaleźć minimum i maksimum
    for (int i = 0; i < seriesUchyb->count(); ++i) {
        double yValue = seriesUchyb->at(i).y();
        if (yValue < minY) {
            minY = yValue;
        }
        if (yValue > maxY) {
            maxY = yValue;
        }
    }

    // Dodaj margines do zakresu Y, aby lepiej widoczny był wykres
    double margin = 0.1 * (maxY - minY); // 10% marginesu wokół wartości minimum i maksimum
    axisYUchyb->setRange(minY - margin, maxY + margin);

    // Zwiększenie czasu
    czas++;
}

void MainWindow::initializeChartPID()
{
    // Tworzenie serii danych
    seriesCalka = new QLineSeries();
    seriesProp = new QLineSeries();
    seriesRozniczka = new QLineSeries();
    seriesRozniczka->setColor(Qt::red); // Zmiana koloru drugiej serii
    seriesCalka->setColor(Qt::green); // Zmiana koloru drugiej serii
    chartPID = new QChart();
    chartPID->addSeries(seriesCalka);
    chartPID->addSeries(seriesRozniczka);
    chartPID->addSeries(seriesProp);
    chartPID->legend()->setVisible(false);

    // Tworzenie osi X i Y
    axisXPID = new QValueAxis();
    axisXPID->setRange(0, 30); // Początkowy zakres dla osi X
    //axisX->setTitleText("Czas (s)");

    axisYPID = new QValueAxis();
    //axisY->setTitleText("Wyjście Obiektu");

    // Początkowy zakres osi Y
    axisYPID->setRange(0, s.getWartoscZadana());

    // Dodanie osi X i Y do wykresu
    chartPID->addAxis(axisXPID, Qt::AlignBottom);
    chartPID->addAxis(axisYPID, Qt::AlignLeft);

    // Powiązanie osi z serią danych
    seriesCalka->attachAxis(axisXPID);
    seriesCalka->attachAxis(axisYPID);

    // Powiązanie osi Y z drugą serią
    seriesRozniczka->attachAxis(axisXPID);
    seriesRozniczka->attachAxis(axisYPID);
    seriesProp->attachAxis(axisXPID);
    seriesProp->attachAxis(axisYPID);
    chartViewPID = new QChartView(chartPID);
    chartViewPID->setRenderHint(QPainter::Antialiasing);
    chartViewPID->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    QVBoxLayout *layout = new QVBoxLayout();
    layout->setContentsMargins(0, 0, 0, 0);  // Usunięcie marginesów
    ui->widgetChart_3->setLayout(layout);

    // Dodanie wykresu do layoutu
    layout->addWidget(chartViewPID);
}

void MainWindow::updateChartPID()
{
    // Symulacja kolejnego kroku
    double wyjscieObiektu = s.symulujKrok(czas);
    Regulator regulator = s.getRegulator();

    // Dodanie nowego punktu do serii danych
    seriesProp->append(czas, regulator.getNastawaP());
    seriesCalka->append(czas, regulator.getNastawaI());
    seriesRozniczka->append(czas, regulator.getNastawaD());

    // Usuwanie starych punktów, aby seria była "przesuwana"
    const int maxPoints = 30; // Maksymalna liczba widocznych punktów
    if (seriesProp->count() > maxPoints) {
        seriesProp->remove(0); // Usunięcie najstarszego punktu
        seriesCalka->remove(0); // Usunięcie najstarszego punktu z wartości zadanej
        seriesRozniczka->remove(0);
    }

    // Przesunięcie osi X w miarę przybywania nowych punktów
    if (czas > maxPoints) {
        axisXPID->setRange(czas - maxPoints, czas); // Przesunięcie osi X
    }

    // Zmienna dla zakresu osi Y
    double minY = std::numeric_limits<double>::max();  // Inicjalizujemy jako bardzo dużą wartość
    double maxY = std::numeric_limits<double>::lowest();  // Inicjalizujemy jako bardzo małą wartość

    // Iteracja przez wszystkie serie i znalezienie minimalnych i maksymalnych wartości
    for (int i = 0; i < seriesProp->count(); ++i) {
        double yValueP = seriesProp->at(i).y();
        double yValueI = seriesCalka->at(i).y();
        double yValueD = seriesRozniczka->at(i).y();

        // Sprawdzamy, czy wartość należy do nowych minimum lub maksimum
        minY = std::min({minY, yValueP, yValueI, yValueD});
        maxY = std::max({maxY, yValueP, yValueI, yValueD});
    }

    // Dodanie marginesu do zakresu Y
    // Może warto dostosować margines w zależności od tego, jak duże są wartości
    double margin = 1.0; // Można zmniejszyć margines, aby uniknąć wychodzenia poza zakres
    minY -= margin;
    maxY += margin;

    // Jeśli minY jest ujemne i chcesz widzieć wszystkie wartości, możesz ustawić minY na 0
    if (minY < 0) {
        minY = 0;
    }

    // Ustawienie zakresu osi Y tylko w przypadku rzeczywistej zmiany
    if (axisYPID->min() != minY || axisYPID->max() != maxY) {
        axisYPID->setRange(minY, maxY); // Zastosowanie nowego zakresu
    }

    // Zwiększenie czasu
    czas++;
}


MainWindow::~MainWindow()
{
    delete ui;
}







void MainWindow::on_doubleSpinBox_valueChanged(double arg1)
{
    Q_UNUSED(arg1);
}


void MainWindow::on_pushButton_clicked()
{
    if (UstawienieObiektu && UstawienieGeneratora && UstawienieRegulatora && interwalCzasowy > 0) {
        // Jeśli symulacja została zatrzymana, wznowić od ostatniego punktu
        if (!isSimulationRunning) {
            // Przywrócenie stanu symulacji (np. ostatnie wartości regulatora i obiektu)
            s.getRegulator().setOstatniaNastawa(s.getLastRegulatorValue());  // Przykład przywrócenia ostatniej nastawy
            s.setWyjscieObiektu(s.getWyjscieObiektu());  // Ostatnie wyjście obiektu ARX
            isSimulationRunning = true;  // Ustawienie flagi, że symulacja jest w toku
        }

        // Uruchomienie timera
        simulationTimer->start(interwalCzasowy);
    }
    else {
        QMessageBox::warning(this, "Uwaga", "Nie uzupełniłeś wszystkich danych");
    }
}
void MainWindow::on_pushButton_2_clicked()
{
    // Zatrzymanie timera symulacji
    simulationTimer->stop();

    // Stan symulacji jest utrzymywany, nie resetujemy wartości obiektów
    // Możemy dodać flagę, która informuje, że symulacja została zatrzymana
    isSimulationRunning = false;  // Flaga, którą można zainicjować w klasie
}

void MainWindow::on_Skok_clicked()
{
    if(ui->SkokWartosc->value()!=0){
       Generator g(RodzajSygnalu::Skok,ui->SkokWartosc->value(),0.0,0.0,czas);
        s.setGenerator(g);
       UstawienieGeneratora=true;
    }
    else{
        QMessageBox::warning(this,"Błąd","Nie uzupełniłeś wszytskich danych");

    }

}


void MainWindow::on_Sinusoida_clicked()
{
    if(ui->SinusoidaAmplituda->value()!=0&&ui->SinusoidaOkres->value()>0){
        Generator g(RodzajSygnalu::Sinusoida,ui->SinusoidaAmplituda->value(),ui->SinusoidaOkres->value(),0.0,czas);
        s.setGenerator(g);
        UstawienieGeneratora=true;
    }
    else{
        QMessageBox::warning(this,"Błąd","Nie uzupełniłeś wszytskich danych");

    }
}


void MainWindow::on_Prostokat_clicked()
{
    if(ui->ProstokatnyAmplituda->value()!=0&&ui->ProstokatnyWypelnienie->value()!=0&&ui->ProstokatnyOkres->value()>0){
        Generator g(RodzajSygnalu::Prostokatny,ui->ProstokatnyAmplituda->value(),ui->ProstokatnyOkres->value(),ui->ProstokatnyWypelnienie->value(),czas);
        s.setGenerator(g);
        UstawienieGeneratora=true;
    }
    else{
        QMessageBox::warning(this,"Błąd","Nie uzupełniłeś wszytskich danych");

    }
}






void MainWindow::on_ustawRegulator_clicked()
{
    double wzmocnienie = ui->Wzmocnienie->value();
    double stalaI = ui->StalaI->value();
    double stalaD = ui->StalaD->value();
    if(wzmocnienie==0&&stalaI==0&&stalaD==0){
       QMessageBox::critical(this,"Błąd","Przynajmniej Jedna nastawa musi mieć wartość");
    }else{
        Regulator r(wzmocnienie,stalaI,stalaD);
        s.setRegulator(r);
        UstawienieRegulatora=true;
    }

}


void MainWindow::on_ustawObiekt_clicked()
{
    double a1=ui->A1->value();
    double a2=ui->A2->value();
    double a3=ui->A3->value();
    double b1=ui->B1->value();
    double b2=ui->B2->value();
    double b3=ui->B3->value();
    double opoznienie = ui->Opoznienie->value();
    if((a1==0&&a2==0&&a3==0)||(b1==0&&b2==0&&b3==0)){
        QMessageBox::critical(this,"Błąd","Uzupelnij wartości wielomianów");
    }
    else{
        ObiektARX o(opoznienie,0.01,{a1,a2,a3},{b1,b2,b3},rng,0.0,0.05);
        s.setObiektARX(o);
        UstawienieObiektu=true;
    }
}


void MainWindow::on_Interwal_textChanged(const QString &arg1)
{
    if(arg1.toInt()>0){
        interwalCzasowy=arg1.toInt();
    }else{
        QMessageBox::critical(this,"Błąd","Błędny Interwał Czasowy");
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->StalaD->setValue(0);
    ui->StalaI->setValue(0);
    s.getRegulator().ZerowanieNastawaD();
    s.getRegulator().ZerowanieNastawaI();
}

