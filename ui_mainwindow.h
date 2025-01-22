/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_24;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QWidget *wykresWarZad;
    QWidget *WykUchyb;
    QWidget *WykPID;
    QPushButton *UstawieniaGeneratora;
    QPushButton *UstawieniaRegulatora;
    QPushButton *UstawieniaObiektuARX;
    QLabel *label_26;
    QLabel *label_25;
    QLineEdit *Interwal;
    QWidget *WykSter;
    QLabel *label_27;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1577, 942);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label_21 = new QLabel(centralwidget);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(750, 460, 311, 51));
        QFont font;
        font.setPointSize(16);
        label_21->setFont(font);
        label_22 = new QLabel(centralwidget);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(370, 810, 281, 51));
        label_22->setFont(font);
        label_23 = new QLabel(centralwidget);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(790, 810, 251, 51));
        label_23->setFont(font);
        label_24 = new QLabel(centralwidget);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(110, -30, 1301, 101));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_24->sizePolicy().hasHeightForWidth());
        label_24->setSizePolicy(sizePolicy);
        label_24->setBaseSize(QSize(0, 0));
        QFont font1;
        font1.setPointSize(25);
        font1.setItalic(false);
        font1.setUnderline(false);
        label_24->setFont(font1);
        label_24->setAlignment(Qt::AlignmentFlag::AlignCenter);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(70, 220, 171, 101));
        QFont font2;
        font2.setPointSize(20);
        pushButton->setFont(font2);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(70, 330, 171, 111));
        pushButton_2->setFont(font2);
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(70, 460, 171, 71));
        QFont font3;
        font3.setPointSize(13);
        pushButton_3->setFont(font3);
        wykresWarZad = new QWidget(centralwidget);
        wykresWarZad->setObjectName("wykresWarZad");
        wykresWarZad->setGeometry(QRect(370, 110, 931, 351));
        WykUchyb = new QWidget(centralwidget);
        WykUchyb->setObjectName("WykUchyb");
        WykUchyb->setGeometry(QRect(370, 540, 311, 251));
        WykPID = new QWidget(centralwidget);
        WykPID->setObjectName("WykPID");
        WykPID->setGeometry(QRect(790, 540, 311, 251));
        UstawieniaGeneratora = new QPushButton(centralwidget);
        UstawieniaGeneratora->setObjectName("UstawieniaGeneratora");
        UstawieniaGeneratora->setGeometry(QRect(80, 630, 151, 61));
        UstawieniaRegulatora = new QPushButton(centralwidget);
        UstawieniaRegulatora->setObjectName("UstawieniaRegulatora");
        UstawieniaRegulatora->setGeometry(QRect(80, 770, 151, 61));
        UstawieniaObiektuARX = new QPushButton(centralwidget);
        UstawieniaObiektuARX->setObjectName("UstawieniaObiektuARX");
        UstawieniaObiektuARX->setGeometry(QRect(80, 700, 151, 61));
        label_26 = new QLabel(centralwidget);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(90, 580, 161, 31));
        QFont font4;
        font4.setPointSize(17);
        label_26->setFont(font4);
        label_25 = new QLabel(centralwidget);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(80, 840, 167, 21));
        QFont font5;
        font5.setPointSize(10);
        label_25->setFont(font5);
        Interwal = new QLineEdit(centralwidget);
        Interwal->setObjectName("Interwal");
        Interwal->setGeometry(QRect(80, 870, 167, 22));
        Interwal->setAlignment(Qt::AlignmentFlag::AlignCenter);
        WykSter = new QWidget(centralwidget);
        WykSter->setObjectName("WykSter");
        WykSter->setGeometry(QRect(1180, 540, 311, 251));
        label_27 = new QLabel(centralwidget);
        label_27->setObjectName("label_27");
        label_27->setGeometry(QRect(1240, 810, 251, 51));
        label_27->setFont(font);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1577, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "Warto\305\233\304\207 Zadana i Regulowana", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "Warto\305\233\304\207 Uchybu Regulacji", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "Warto\305\233ci Regulatora PID", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "Symulator Uk\305\202adu Automatycznej Regulacji", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Reset ID", nullptr));
        UstawieniaGeneratora->setText(QCoreApplication::translate("MainWindow", "Generator", nullptr));
        UstawieniaRegulatora->setText(QCoreApplication::translate("MainWindow", "Regulator", nullptr));
        UstawieniaObiektuARX->setText(QCoreApplication::translate("MainWindow", "Obiekt ARX", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "Ustawienia", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "Interwa\305\202 Czasowy", nullptr));
        Interwal->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "Warto\305\233\304\207 Steruj\304\205ca", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
