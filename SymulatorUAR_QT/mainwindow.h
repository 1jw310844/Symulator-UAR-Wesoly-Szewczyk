#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "symulator.h"
#include <QMainWindow>
#include <QTimer>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:

    void on_doubleSpinBox_valueChanged(double arg1);

    void on_pushButton_clicked();


    void on_Skok_clicked();

    void on_Sinusoida_clicked();

    void on_Prostokat_clicked();

    void on_pushButton_2_clicked();

    void on_ustawRegulator_clicked();

    void on_ustawObiekt_clicked();

    void on_Interwal_textChanged(const QString &arg1);
    void initializeChart();
    void updateChart();
    void initializeChartUchyb();
    void updateChartUchyb();
    void initializeChartPID();
    void updateChartPID();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *simulationTimer;
    QLineSeries *series;       // Deklaracja serii danych wykresu
    QLineSeries *seriesWartoscZadana;
    QChart *chart;
    QValueAxis *axisX;
    QValueAxis *axisY;
    QChartView *chartView;
    //Uchyb
    QLineSeries *seriesUchyb;
    QChart *chartUchyb;
    QValueAxis *axisXUchyb;
    QValueAxis *axisYUchyb;
    QChartView *chartViewUchyb;
    //Wykres PID
    QLineSeries *seriesCalka;
    QLineSeries *seriesRozniczka;
    QLineSeries *seriesProp;
    QChart *chartPID;
    QValueAxis *axisXPID;
    QValueAxis *axisYPID;
    QChartView *chartViewPID;
    symulator s;
    double czas;
    int interwalCzasowy=0;
    bool UstawienieObiektu=false;
    bool UstawienieRegulatora=false;
    bool UstawienieGeneratora=false;
    bool isSimulationRunning=true;
};
#endif // MAINWINDOW_H
