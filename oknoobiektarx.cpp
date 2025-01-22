#include "oknoobiektarx.h"
#include "ui_oknoobiektarx.h"
#include "warstwauslug.h"

OknoObiektARX::OknoObiektARX(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::OknoObiektARX)

{
    ui->setupUi(this);
    obiekt = new ObiektARX;
    usluga = new WarstwaUslug;
    ui->A1->setRange(-1000, 1000);
    ui->A2->setRange(-1000, 1000);
    ui->A3->setRange(-1000, 1000);
    ui->B1->setRange(-1000, 1000);
    ui->B2->setRange(-1000, 1000);
    ui->B3->setRange(-1000, 1000);
    ui->Opoznienie->setRange(0, 1000);
    ui->A1->setSingleStep(0.1);
    ui->A2->setSingleStep(0.1);
    ui->A3->setSingleStep(0.1);
    ui->B1->setSingleStep(0.1);
    ui->B2->setSingleStep(0.1);
    ui->B3->setSingleStep(0.1);
    ui->Opoznienie->setSingleStep(0.1);
}

OknoObiektARX::~OknoObiektARX()
{
    delete ui;
}

void OknoObiektARX::on_ZatwierdzenieUstawien_accepted()
{
    qDebug() << "Przed ustawieniem wartości obiektu";
    obiekt->setOpoznienie(ui->Opoznienie->value());
    obiekt->setWielomianA({ui->A1->value(), ui->A2->value(), ui->A3->value()});
    obiekt->setWielomianB({ui->B1->value(), ui->B2->value(), ui->B3->value()});
    qDebug() << "Dane obiektu: " << obiekt->getOpoznienie() << ", " << obiekt->getWielomianA() << ", " << obiekt->getWielomianB();
    usluga->SprawdzenieObiektu(obiekt);
}

