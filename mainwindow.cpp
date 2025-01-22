#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "oknogenerator.h"
#include "oknoregulator.h"
#include "oknoobiektarx.h"
#include <QDebug>
#include <QMessageBox>

std::random_device srng;
std::mt19937 rng;

MainWindow::MainWindow(QWidget *parent, WarstwaUslug *prog)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , usluga(prog)
    , sym(new symulator())
    ,czas(0.0)
{
    qDebug() << "MainWindow constructor";
    usluga->setGUI(this);
    ui->setupUi(this);
    wykres=new  Wykresy();
    okno_gen = new OknoGenerator(this);
    okno_gen->setWarstwaUslug(usluga);
    okno_reg = new OknoRegulator(this);
    okno_reg->setWarstwaUslug(usluga);
    okno_obiekt = new OknoObiektARX(this);
    okno_obiekt->setWarstwaUslug(usluga);

    this->showMaximized();
    simulationTimer = new QTimer(this);
    this->setStyleSheet("background-color: gray;");
    ui->pushButton->setStyleSheet(
        "QPushButton {"
        "    background-color: white;"
        "    border-radius: 5px;"
        "    border: 1px solid black;"
        "}"
        "QPushButton:hover {"
        "    background-color: lightgray;"
        "    color: gray;"
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
        "    color: gray;"
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
        "    color: gray;"
        "}"
        );

    wykres = new Wykresy;
    ui->Interwal->setStyleSheet("background-color:white");

    //symulator* s=new symulator;

    UstawienieLayout();

    connect(usluga, &WarstwaUslug::PoprawneDane, this, &MainWindow::PokazWykres);
    connect(usluga, &WarstwaUslug::BledneDane, this, &MainWindow::Blad);
    qDebug() << "Sygnały połączone";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::UstawienieLayout(){
    qDebug() << "Ustawianie layoutu";
    for(int i=0;i<4;i++){
        layout[i] = new QVBoxLayout();
        layout[i]->setContentsMargins(0, 0, 0, 0);
    }
    ui->wykresWarZad->setLayout(layout[0]);
    ui->WykUchyb->setLayout(layout[1]);
    ui->WykPID->setLayout(layout[2]);
    ui->WykSter->setLayout(layout[3]);
    qDebug() << "Layout ustawiony";
}

void MainWindow::on_pushButton_clicked()
{
    qDebug() << "Przycisk Start kliknięty";
    usluga->SprawdzenieWszystkichDanych();
    qDebug() << "Sprawdzenie wszystkich danych zakończone";
}

void MainWindow::on_pushButton_2_clicked()
{
    qDebug() << "Przycisk Stop kliknięty";
    simulationTimer->stop();
    isSimulationRunning = false;  // Flaga, którą można zainicjować w klasie
    qDebug() << "Timer zatrzymany";
}

void MainWindow::on_Interwal_textChanged(const QString &arg1)
{
    qDebug() << "Zmiana interwału czasowego";
    if(arg1.toInt()>0){
        interwalCzasowy=arg1.toInt();
        qDebug() << "Nowy interwał czasowy: " << interwalCzasowy;
    }else{
        QMessageBox::critical(this, "Błąd", "Błędny Interwał Czasowy");
        qDebug() << "Błędny interwał czasowy";
    }
}

void MainWindow::PokazWykres(symulator* s) {
    if (!s) {
        qDebug() << "symulator* s jest nullptr!";
        return;
    }
    qDebug() << "Inicjalizacja wykresów";
    setSymulator(s);
    wykres->setSymulator(sym);
    for (int i = 0; i < 4; i++) {
        wykres->InicjalizujWykresy(layout[i]);
        qDebug() << "Wykres " << i << " zainicjalizowany";
    }
    connect(simulationTimer, &QTimer::timeout, this, [=]() {
        if (sym) {
            wykres->AktualizujWykresy();
        } else {
            qDebug() << "symulator* s jest nullptr podczas timeout!";
        }
    });
    if (interwalCzasowy > 0) {
        simulationTimer->start(interwalCzasowy);
        qDebug() << "Timer uruchomiony z interwałem " << interwalCzasowy;
    } else {
        qDebug() << "Błędny interwał czasowy";
    }
}


void MainWindow::Blad(){
    qDebug() << "Wywołano funkcję Blad()";
    QMessageBox::warning(this, "Ostrzeżenie", "Nie uzupełniłeś Wszystkich Danych");
}

void MainWindow::on_UstawieniaGeneratora_clicked()
{
    qDebug() << "Ustawienia Generatora kliknięte";
    okno_gen->exec();
}

void MainWindow::on_UstawieniaObiektuARX_clicked()
{
    qDebug() << "Ustawienia Obiektu ARX kliknięte";
    okno_obiekt->exec();
}

void MainWindow::on_UstawieniaRegulatora_clicked()
{
    qDebug() << "Ustawienia Regulatora kliknięte";
    okno_reg->exec();
}
