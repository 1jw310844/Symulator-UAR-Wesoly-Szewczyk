#ifndef OKNOOBIEKTARX_H
#define OKNOOBIEKTARX_H

#include <QDialog>
#include "obiektarx.h"
#include "warstwauslug.h"

namespace Ui {
class OknoObiektARX;
}

class OknoObiektARX : public QDialog
{
    Q_OBJECT

public:
    explicit OknoObiektARX(QWidget *parent = nullptr);
    ~OknoObiektARX();
    void setWarstwaUslug(WarstwaUslug* w){usluga=w;};

private slots:
    void on_ZatwierdzenieUstawien_accepted();

private:
    Ui::OknoObiektARX *ui;
    ObiektARX *obiekt;
    WarstwaUslug *usluga;
    std::mt19937 generator;
};

#endif // OKNOOBIEKTARX_H

