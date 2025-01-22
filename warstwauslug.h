#ifndef WARSTWAUSLUG_H
#define WARSTWAUSLUG_H

#include <QObject>
#include <QDebug>
#include "symulator.h"

class MainWindow;

class WarstwaUslug : public QObject
{
    Q_OBJECT
public:
    explicit WarstwaUslug(QObject *parent = nullptr);
    void SprawdzenieWszystkichDanych();
    void SprawdzenieRegulatora(Regulator* r);
    void SprawdzenieGeneratora(Generator* g);
    void SprawdzenieObiektu(ObiektARX* o);
    void setGUI(MainWindow* ui = nullptr){ GUI = ui; }

signals:
    void PoprawneDane(symulator* s);
    void BledneDane();

private:
    symulator* s;
    MainWindow* GUI = nullptr;
};

#endif // WARSTWAUSLUG_H

