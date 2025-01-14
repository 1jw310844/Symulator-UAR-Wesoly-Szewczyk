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
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
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
    QWidget *widgetChart;
    QWidget *widgetChart_2;
    QWidget *widgetChart_3;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_10;
    QDoubleSpinBox *A1;
    QDoubleSpinBox *A2;
    QDoubleSpinBox *A3;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_11;
    QDoubleSpinBox *B1;
    QDoubleSpinBox *B2;
    QDoubleSpinBox *B3;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_8;
    QDoubleSpinBox *Opoznienie;
    QPushButton *ustawObiekt;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_8;
    QLabel *label;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_12;
    QDoubleSpinBox *Wzmocnienie;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_5;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_13;
    QDoubleSpinBox *StalaI;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_6;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_14;
    QDoubleSpinBox *StalaD;
    QPushButton *ustawRegulator;
    QWidget *widget2;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_9;
    QRadioButton *Skok;
    QHBoxLayout *horizontalLayout;
    QLabel *label_20;
    QDoubleSpinBox *SkokWartosc;
    QRadioButton *Sinusoida;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_18;
    QDoubleSpinBox *SinusoidaOkres;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_19;
    QDoubleSpinBox *SinusoidaAmplituda;
    QRadioButton *Prostokat;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_15;
    QDoubleSpinBox *ProstokatnyOkres;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_16;
    QDoubleSpinBox *ProstokatnyAmplituda;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_17;
    QDoubleSpinBox *ProstokatnyWypelnienie;
    QWidget *widget3;
    QVBoxLayout *verticalLayout_12;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_25;
    QLineEdit *Interwal;
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
        label_21->setGeometry(QRect(370, 470, 311, 51));
        QFont font;
        font.setPointSize(16);
        label_21->setFont(font);
        label_22 = new QLabel(centralwidget);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(770, 470, 281, 51));
        label_22->setFont(font);
        label_23 = new QLabel(centralwidget);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(1210, 460, 251, 51));
        label_23->setFont(font);
        label_24 = new QLabel(centralwidget);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(90, 50, 1301, 101));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_24->sizePolicy().hasHeightForWidth());
        label_24->setSizePolicy(sizePolicy);
        label_24->setBaseSize(QSize(0, 0));
        QFont font1;
        font1.setPointSize(48);
        font1.setItalic(false);
        font1.setUnderline(false);
        label_24->setFont(font1);
        label_24->setAlignment(Qt::AlignmentFlag::AlignCenter);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(130, 220, 171, 101));
        QFont font2;
        font2.setPointSize(20);
        pushButton->setFont(font2);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(130, 340, 171, 111));
        pushButton_2->setFont(font2);
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(140, 580, 151, 71));
        QFont font3;
        font3.setPointSize(13);
        pushButton_3->setFont(font3);
        widgetChart = new QWidget(centralwidget);
        widgetChart->setObjectName("widgetChart");
        widgetChart->setGeometry(QRect(370, 210, 311, 251));
        widgetChart_2 = new QWidget(centralwidget);
        widgetChart_2->setObjectName("widgetChart_2");
        widgetChart_2->setGeometry(QRect(760, 210, 311, 251));
        widgetChart_3 = new QWidget(centralwidget);
        widgetChart_3->setObjectName("widgetChart_3");
        widgetChart_3->setGeometry(QRect(1160, 210, 311, 251));
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(370, 570, 261, 181));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");
        QFont font4;
        font4.setPointSize(14);
        label_3->setFont(font4);

        verticalLayout_2->addWidget(label_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_7 = new QLabel(widget);
        label_7->setObjectName("label_7");

        verticalLayout->addWidget(label_7);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_10 = new QLabel(widget);
        label_10->setObjectName("label_10");

        horizontalLayout_7->addWidget(label_10);

        A1 = new QDoubleSpinBox(widget);
        A1->setObjectName("A1");

        horizontalLayout_7->addWidget(A1);

        A2 = new QDoubleSpinBox(widget);
        A2->setObjectName("A2");

        horizontalLayout_7->addWidget(A2);

        A3 = new QDoubleSpinBox(widget);
        A3->setObjectName("A3");

        horizontalLayout_7->addWidget(A3);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        label_11 = new QLabel(widget);
        label_11->setObjectName("label_11");

        horizontalLayout_8->addWidget(label_11);

        B1 = new QDoubleSpinBox(widget);
        B1->setObjectName("B1");

        horizontalLayout_8->addWidget(B1);

        B2 = new QDoubleSpinBox(widget);
        B2->setObjectName("B2");

        horizontalLayout_8->addWidget(B2);

        B3 = new QDoubleSpinBox(widget);
        B3->setObjectName("B3");

        horizontalLayout_8->addWidget(B3);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        label_8 = new QLabel(widget);
        label_8->setObjectName("label_8");

        horizontalLayout_9->addWidget(label_8);

        Opoznienie = new QDoubleSpinBox(widget);
        Opoznienie->setObjectName("Opoznienie");

        horizontalLayout_9->addWidget(Opoznienie);


        verticalLayout->addLayout(horizontalLayout_9);

        ustawObiekt = new QPushButton(widget);
        ustawObiekt->setObjectName("ustawObiekt");

        verticalLayout->addWidget(ustawObiekt);


        verticalLayout_2->addLayout(verticalLayout);

        widget1 = new QWidget(centralwidget);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(770, 570, 301, 227));
        verticalLayout_8 = new QVBoxLayout(widget1);
        verticalLayout_8->setObjectName("verticalLayout_8");
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget1);
        label->setObjectName("label");
        label->setFont(font4);

        verticalLayout_8->addWidget(label);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        label_4 = new QLabel(widget1);
        label_4->setObjectName("label_4");
        QFont font5;
        font5.setPointSize(11);
        label_4->setFont(font5);

        horizontalLayout_10->addWidget(label_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_12 = new QLabel(widget1);
        label_12->setObjectName("label_12");
        QFont font6;
        font6.setPointSize(10);
        label_12->setFont(font6);

        verticalLayout_3->addWidget(label_12);

        Wzmocnienie = new QDoubleSpinBox(widget1);
        Wzmocnienie->setObjectName("Wzmocnienie");

        verticalLayout_3->addWidget(Wzmocnienie);


        horizontalLayout_10->addLayout(verticalLayout_3);


        verticalLayout_6->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        label_5 = new QLabel(widget1);
        label_5->setObjectName("label_5");
        label_5->setFont(font5);

        horizontalLayout_11->addWidget(label_5);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_13 = new QLabel(widget1);
        label_13->setObjectName("label_13");
        label_13->setFont(font6);

        verticalLayout_4->addWidget(label_13);

        StalaI = new QDoubleSpinBox(widget1);
        StalaI->setObjectName("StalaI");

        verticalLayout_4->addWidget(StalaI);


        horizontalLayout_11->addLayout(verticalLayout_4);


        verticalLayout_6->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        label_6 = new QLabel(widget1);
        label_6->setObjectName("label_6");
        label_6->setFont(font5);

        horizontalLayout_12->addWidget(label_6);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        label_14 = new QLabel(widget1);
        label_14->setObjectName("label_14");
        label_14->setFont(font6);

        verticalLayout_5->addWidget(label_14);

        StalaD = new QDoubleSpinBox(widget1);
        StalaD->setObjectName("StalaD");

        verticalLayout_5->addWidget(StalaD);


        horizontalLayout_12->addLayout(verticalLayout_5);


        verticalLayout_6->addLayout(horizontalLayout_12);


        verticalLayout_7->addLayout(verticalLayout_6);

        ustawRegulator = new QPushButton(widget1);
        ustawRegulator->setObjectName("ustawRegulator");

        verticalLayout_7->addWidget(ustawRegulator);


        verticalLayout_8->addLayout(verticalLayout_7);

        widget2 = new QWidget(centralwidget);
        widget2->setObjectName("widget2");
        widget2->setGeometry(QRect(1230, 570, 191, 317));
        verticalLayout_10 = new QVBoxLayout(widget2);
        verticalLayout_10->setObjectName("verticalLayout_10");
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget2);
        label_2->setObjectName("label_2");
        label_2->setFont(font4);

        verticalLayout_10->addWidget(label_2);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName("verticalLayout_9");
        label_9 = new QLabel(widget2);
        label_9->setObjectName("label_9");
        label_9->setFont(font5);

        verticalLayout_9->addWidget(label_9);

        Skok = new QRadioButton(widget2);
        Skok->setObjectName("Skok");
        Skok->setFont(font6);

        verticalLayout_9->addWidget(Skok);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_20 = new QLabel(widget2);
        label_20->setObjectName("label_20");

        horizontalLayout->addWidget(label_20);

        SkokWartosc = new QDoubleSpinBox(widget2);
        SkokWartosc->setObjectName("SkokWartosc");

        horizontalLayout->addWidget(SkokWartosc);


        verticalLayout_9->addLayout(horizontalLayout);

        Sinusoida = new QRadioButton(widget2);
        Sinusoida->setObjectName("Sinusoida");
        Sinusoida->setFont(font6);

        verticalLayout_9->addWidget(Sinusoida);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_18 = new QLabel(widget2);
        label_18->setObjectName("label_18");

        horizontalLayout_2->addWidget(label_18);

        SinusoidaOkres = new QDoubleSpinBox(widget2);
        SinusoidaOkres->setObjectName("SinusoidaOkres");

        horizontalLayout_2->addWidget(SinusoidaOkres);


        verticalLayout_9->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_19 = new QLabel(widget2);
        label_19->setObjectName("label_19");

        horizontalLayout_3->addWidget(label_19);

        SinusoidaAmplituda = new QDoubleSpinBox(widget2);
        SinusoidaAmplituda->setObjectName("SinusoidaAmplituda");

        horizontalLayout_3->addWidget(SinusoidaAmplituda);


        verticalLayout_9->addLayout(horizontalLayout_3);

        Prostokat = new QRadioButton(widget2);
        Prostokat->setObjectName("Prostokat");
        Prostokat->setFont(font6);

        verticalLayout_9->addWidget(Prostokat);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_15 = new QLabel(widget2);
        label_15->setObjectName("label_15");

        horizontalLayout_4->addWidget(label_15);

        ProstokatnyOkres = new QDoubleSpinBox(widget2);
        ProstokatnyOkres->setObjectName("ProstokatnyOkres");

        horizontalLayout_4->addWidget(ProstokatnyOkres);


        verticalLayout_9->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_16 = new QLabel(widget2);
        label_16->setObjectName("label_16");

        horizontalLayout_5->addWidget(label_16);

        ProstokatnyAmplituda = new QDoubleSpinBox(widget2);
        ProstokatnyAmplituda->setObjectName("ProstokatnyAmplituda");

        horizontalLayout_5->addWidget(ProstokatnyAmplituda);


        verticalLayout_9->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_17 = new QLabel(widget2);
        label_17->setObjectName("label_17");

        horizontalLayout_6->addWidget(label_17);

        ProstokatnyWypelnienie = new QDoubleSpinBox(widget2);
        ProstokatnyWypelnienie->setObjectName("ProstokatnyWypelnienie");

        horizontalLayout_6->addWidget(ProstokatnyWypelnienie);


        verticalLayout_9->addLayout(horizontalLayout_6);


        verticalLayout_10->addLayout(verticalLayout_9);

        widget3 = new QWidget(centralwidget);
        widget3->setObjectName("widget3");
        widget3->setGeometry(QRect(140, 670, 151, 61));
        verticalLayout_12 = new QVBoxLayout(widget3);
        verticalLayout_12->setObjectName("verticalLayout_12");
        verticalLayout_12->setContentsMargins(0, 0, 0, 0);
        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName("verticalLayout_11");
        label_25 = new QLabel(widget3);
        label_25->setObjectName("label_25");
        label_25->setFont(font6);

        verticalLayout_11->addWidget(label_25);

        Interwal = new QLineEdit(widget3);
        Interwal->setObjectName("Interwal");
        Interwal->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_11->addWidget(Interwal);


        verticalLayout_12->addLayout(verticalLayout_11);

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
        label_3->setText(QCoreApplication::translate("MainWindow", "Obiekt ARX", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Wsp\303\263\305\202czynniki wielomian\303\263w A i B", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "A", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "B", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Op\303\263\305\272nienie", nullptr));
        ustawObiekt->setText(QCoreApplication::translate("MainWindow", "Ustaw", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Regulator", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Nastawa P", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Wzmocnienie", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Nastawa I", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Sta\305\202a", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Nastawa D", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Sta\305\202a", nullptr));
        ustawRegulator->setText(QCoreApplication::translate("MainWindow", "Ustaw", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Generator", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Rodzaj Sygna\305\202u", nullptr));
        Skok->setText(QCoreApplication::translate("MainWindow", "Skok Jednostkowy", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "Warto\305\233\304\207 Zadana", nullptr));
        Sinusoida->setText(QCoreApplication::translate("MainWindow", "Sinusoidalny", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "Okres", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "Amplituda", nullptr));
        Prostokat->setText(QCoreApplication::translate("MainWindow", "Prostok\304\205tny", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Okres", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Amplituda", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Wype\305\202nienie", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "Interwa\305\202 Czasowy", nullptr));
        Interwal->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
