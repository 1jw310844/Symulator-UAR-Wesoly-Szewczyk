#include "oknoregulator.h"
#include "ui_oknoregulator.h"
#include "warstwauslug.h"

OknoRegulator::OknoRegulator(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::OknoRegulator)
{
    ui->setupUi(this);
    reg = new Regulator;
    ui->Wzmocnienie->setRange(0, 1000);
    ui->StalaI->setRange(0, 1000);
    ui->StalaD->setRange(0, 1000);
    ui->Wzmocnienie->setSingleStep(0.1);
    ui->StalaI->setSingleStep(0.1);
    ui->StalaD->setSingleStep(0.1);
}

OknoRegulator::~OknoRegulator()
{
    delete ui;
}

void OknoRegulator::on_ZatwierdzenieUstawien_accepted()
{
    qDebug() << "Przed ustawieniem wartości regulatora";
    reg->setWzmocnienie(ui->Wzmocnienie->value());
    reg->setStalaI(ui->StalaI->value());
    reg->setStalaD(ui->StalaD->value());
    qDebug() << "Dane regulatora: " << reg->getWzmocnienie() << ", " << reg->getStalaI() << ", " << reg->getStalaD();
    usluga->SprawdzenieRegulatora(reg);
}


