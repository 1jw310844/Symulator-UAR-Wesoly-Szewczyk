#include "oknogenerator.h"
#include "ui_oknogenerator.h"
#include "warstwauslug.h"

OknoGenerator::OknoGenerator(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::OknoGenerator)
{
    ui->setupUi(this);
    gen = new Generator;
    ui->Amplituda->setRange(-100, 1000);
    ui->Okres->setRange(0, 1000);
    ui->Wypelnienie->setRange(0, 1);
    ui->Amplituda->setSingleStep(0.1);
    ui->Wypelnienie->setSingleStep(0.05);
    ui->RodzajeSygnalu->addAction("Sygnał Skokowy");
    ui->RodzajeSygnalu->addAction("Sygnał Sinusoidalny");
    ui->RodzajeSygnalu->addAction("Sygnał Prostokątny");
}

OknoGenerator::~OknoGenerator()
{
    delete ui;
}

void OknoGenerator::on_RodzajeSygnalu_clicked()
{
    ui->RodzajeSygnalu->showMenu();
}

void OknoGenerator::on_RodzajeSygnalu_triggered(QAction *arg1)
{
    QString wybor = arg1->text();
    if (wybor == "Sygnał Skokowy") {
        gen->setRodzaj(RodzajSygnalu::Skok);
        ui->RodzajeSygnalu->setText("Sygnał Skokowy");
    } else if (wybor == "Sygnał Sinusoidalny") {
        gen->setRodzaj(RodzajSygnalu::Sinusoida);
        ui->RodzajeSygnalu->setText("Sygnał Sinusoidalny");
    } else if (wybor == "Sygnał Prostokątny") {
        gen->setRodzaj(RodzajSygnalu::Prostokatny);
        ui->RodzajeSygnalu->setText("Sygnał Prostokątny");
    }
}

void OknoGenerator::on_ZatwierdzenieUstawien_accepted()
{
    qDebug() << "Przed ustawieniem wartości generatora";
    gen->setAmplituda(ui->Amplituda->value());
    gen->setOkres(ui->Okres->value());
    gen->setWypelnienie(ui->Wypelnienie->value());
    qDebug() << "Dane generatora: " << gen->getAmplituda() << ", " << gen->getOkres() << ", " << gen->getWypelnienie();
    usluga->SprawdzenieGeneratora(gen);
}

