#include "mainwindow.h"
#include "warstwauslug.h"
#include "oknogenerator.h"
#include "oknoregulator.h"
#include "oknoobiektarx.h"

#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    WarstwaUslug* usluga = new WarstwaUslug;
    MainWindow w(nullptr,usluga);
    w.show();
    return a.exec();
}
