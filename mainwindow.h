#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "symulator.h"
#include "wykresy.h"
#include <QMainWindow>
#include <QTimer>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
#include "warstwauslug.h"
#include "oknogenerator.h"
#include "oknoregulator.h"
#include "oknoobiektarx.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE
class WarstwaUslug;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr,
               WarstwaUslug* program = nullptr);
    ~MainWindow();
    void setSymulator(symulator* s){sym=s;};


private slots:

    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_Interwal_textChanged(const QString &arg1);


    //void on_pushButton_3_clicked();

    void on_UstawieniaGeneratora_clicked();

    void on_UstawieniaObiektuARX_clicked();

    void on_UstawieniaRegulatora_clicked();
    void PokazWykres(symulator* s);
    void Blad();

private:
    Ui::MainWindow *ui;
    QTimer *simulationTimer;
    WarstwaUslug* usluga ;
    OknoGenerator* okno_gen;
    OknoRegulator* okno_reg;
    OknoObiektARX* okno_obiekt;
    symulator* sym;
    double czas;
    int interwalCzasowy=0;
    bool isSimulationRunning=true;
    Wykresy* wykres;
    void UstawienieLayout();
    QVBoxLayout *layout[4];
};
#endif // MAINWINDOW_H
