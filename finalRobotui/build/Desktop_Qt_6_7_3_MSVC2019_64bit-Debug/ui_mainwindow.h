/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *parameter_screen;
    QLabel *connect_status;
    QLabel *record_status;
    QPushButton *startrc_btn;
    QPushButton *endrc_btn;
    QPushButton *send_btn;
    QPushButton *connect_btn;
    QLabel *logo1;
    QLabel *logo2;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QWidget *layoutWidget;
    QHBoxLayout *mode_layout;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QWidget *layoutWidget1;
    QGridLayout *controller_layout;
    QLabel *angle1_value;
    QLabel *angle2_value;
    QSlider *angle4_slider;
    QLabel *angle6_value;
    QSlider *angle6_slider;
    QSlider *angle2_slider;
    QSlider *angle1_slider;
    QLabel *angle3_value;
    QLabel *angle4_value;
    QSlider *angle5_slider;
    QSlider *angle3_slider;
    QLabel *angle5_value;
    QPushButton *yellow_gripper;
    QLabel *imageValue_screen;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuGiao_di_n_i_u_khi_n_nh_m_7;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1427, 716);
        QFont font;
        font.setPointSize(10);
        MainWindow->setFont(font);
        MainWindow->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(221, 221, 221);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        parameter_screen = new QLabel(centralwidget);
        parameter_screen->setObjectName("parameter_screen");
        parameter_screen->setGeometry(QRect(150, 380, 541, 81));
        QFont font1;
        font1.setBold(true);
        parameter_screen->setFont(font1);
        parameter_screen->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        connect_status = new QLabel(centralwidget);
        connect_status->setObjectName("connect_status");
        connect_status->setGeometry(QRect(160, 19, 431, 31));
        connect_status->setFont(font1);
        connect_status->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        record_status = new QLabel(centralwidget);
        record_status->setObjectName("record_status");
        record_status->setGeometry(QRect(470, 250, 121, 41));
        record_status->setFont(font1);
        record_status->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        record_status->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(255, 0, 0);"));
        record_status->setMargin(0);
        startrc_btn = new QPushButton(centralwidget);
        startrc_btn->setObjectName("startrc_btn");
        startrc_btn->setGeometry(QRect(420, 200, 91, 31));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        startrc_btn->setFont(font2);
        startrc_btn->setStyleSheet(QString::fromUtf8("color: rgb(50, 50, 50);\n"
"background-color: rgb(171, 171, 171);"));
        endrc_btn = new QPushButton(centralwidget);
        endrc_btn->setObjectName("endrc_btn");
        endrc_btn->setGeometry(QRect(540, 200, 91, 31));
        endrc_btn->setFont(font2);
        endrc_btn->setStyleSheet(QString::fromUtf8("color: rgb(50, 50, 50);\n"
"background-color: rgb(171, 171, 171);"));
        send_btn = new QPushButton(centralwidget);
        send_btn->setObjectName("send_btn");
        send_btn->setGeometry(QRect(30, 400, 111, 51));
        QFont font3;
        font3.setPointSize(14);
        font3.setBold(false);
        send_btn->setFont(font3);
        send_btn->setStyleSheet(QString::fromUtf8("background-color: rgb(136, 136, 136);\n"
"color: rgb(0, 0, 0);"));
        connect_btn = new QPushButton(centralwidget);
        connect_btn->setObjectName("connect_btn");
        connect_btn->setGeometry(QRect(20, 10, 121, 51));
        connect_btn->setFont(font3);
        connect_btn->setStyleSheet(QString::fromUtf8("color: rgb(50, 50, 50);\n"
"background-color: rgb(171, 171, 171);"));
        logo1 = new QLabel(centralwidget);
        logo1->setObjectName("logo1");
        logo1->setGeometry(QRect(340, 520, 71, 91));
        logo1->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix2/logo-hust.png);"));
        logo2 = new QLabel(centralwidget);
        logo2->setObjectName("logo2");
        logo2->setGeometry(QRect(520, 560, 71, 21));
        logo2->setStyleSheet(QString::fromUtf8("image: url(:/new/prefix2/hust.png);"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(700, 80, 721, 471));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(160, 70, 481, 41));
        mode_layout = new QHBoxLayout(layoutWidget);
        mode_layout->setObjectName("mode_layout");
        mode_layout->setContentsMargins(0, 0, 0, 0);
        radioButton = new QRadioButton(layoutWidget);
        radioButton->setObjectName("radioButton");
        radioButton->setFont(font1);
        radioButton->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        mode_layout->addWidget(radioButton);

        radioButton_2 = new QRadioButton(layoutWidget);
        radioButton_2->setObjectName("radioButton_2");
        radioButton_2->setFont(font1);
        radioButton_2->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(8, 8, 8);"));

        mode_layout->addWidget(radioButton_2);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(20, 140, 381, 221));
        controller_layout = new QGridLayout(layoutWidget1);
        controller_layout->setObjectName("controller_layout");
        controller_layout->setContentsMargins(0, 0, 0, 0);
        angle1_value = new QLabel(layoutWidget1);
        angle1_value->setObjectName("angle1_value");
        angle1_value->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));

        controller_layout->addWidget(angle1_value, 0, 1, 1, 1);

        angle2_value = new QLabel(layoutWidget1);
        angle2_value->setObjectName("angle2_value");
        angle2_value->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));

        controller_layout->addWidget(angle2_value, 0, 3, 1, 1);

        angle4_slider = new QSlider(layoutWidget1);
        angle4_slider->setObjectName("angle4_slider");
        angle4_slider->setMaximum(180);
        angle4_slider->setOrientation(Qt::Orientation::Horizontal);

        controller_layout->addWidget(angle4_slider, 1, 2, 1, 1);

        angle6_value = new QLabel(layoutWidget1);
        angle6_value->setObjectName("angle6_value");
        angle6_value->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));

        controller_layout->addWidget(angle6_value, 2, 3, 1, 1);

        angle6_slider = new QSlider(layoutWidget1);
        angle6_slider->setObjectName("angle6_slider");
        angle6_slider->setMinimum(40);
        angle6_slider->setMaximum(150);
        angle6_slider->setOrientation(Qt::Orientation::Horizontal);

        controller_layout->addWidget(angle6_slider, 2, 2, 1, 1);

        angle2_slider = new QSlider(layoutWidget1);
        angle2_slider->setObjectName("angle2_slider");
        angle2_slider->setMinimum(110);
        angle2_slider->setMaximum(180);
        angle2_slider->setOrientation(Qt::Orientation::Horizontal);

        controller_layout->addWidget(angle2_slider, 0, 2, 1, 1);

        angle1_slider = new QSlider(layoutWidget1);
        angle1_slider->setObjectName("angle1_slider");
        angle1_slider->setMaximum(180);
        angle1_slider->setOrientation(Qt::Orientation::Horizontal);

        controller_layout->addWidget(angle1_slider, 0, 0, 1, 1);

        angle3_value = new QLabel(layoutWidget1);
        angle3_value->setObjectName("angle3_value");
        angle3_value->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));

        controller_layout->addWidget(angle3_value, 1, 1, 1, 1);

        angle4_value = new QLabel(layoutWidget1);
        angle4_value->setObjectName("angle4_value");
        angle4_value->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));

        controller_layout->addWidget(angle4_value, 1, 3, 1, 1);

        angle5_slider = new QSlider(layoutWidget1);
        angle5_slider->setObjectName("angle5_slider");
        angle5_slider->setMaximum(180);
        angle5_slider->setOrientation(Qt::Orientation::Horizontal);

        controller_layout->addWidget(angle5_slider, 2, 0, 1, 1);

        angle3_slider = new QSlider(layoutWidget1);
        angle3_slider->setObjectName("angle3_slider");
        angle3_slider->setMaximum(180);
        angle3_slider->setOrientation(Qt::Orientation::Horizontal);

        controller_layout->addWidget(angle3_slider, 1, 0, 1, 1);

        angle5_value = new QLabel(layoutWidget1);
        angle5_value->setObjectName("angle5_value");
        angle5_value->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));

        controller_layout->addWidget(angle5_value, 2, 1, 1, 1);

        yellow_gripper = new QPushButton(centralwidget);
        yellow_gripper->setObjectName("yellow_gripper");
        yellow_gripper->setGeometry(QRect(730, 590, 83, 29));
        imageValue_screen = new QLabel(centralwidget);
        imageValue_screen->setObjectName("imageValue_screen");
        imageValue_screen->setGeometry(QRect(860, 580, 461, 51));
        imageValue_screen->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        MainWindow->setCentralWidget(centralwidget);
        layoutWidget->raise();
        layoutWidget->raise();
        parameter_screen->raise();
        connect_status->raise();
        record_status->raise();
        startrc_btn->raise();
        endrc_btn->raise();
        send_btn->raise();
        connect_btn->raise();
        logo1->raise();
        logo2->raise();
        gridLayoutWidget->raise();
        yellow_gripper->raise();
        imageValue_screen->raise();
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1427, 25));
        menuGiao_di_n_i_u_khi_n_nh_m_7 = new QMenu(menubar);
        menuGiao_di_n_i_u_khi_n_nh_m_7->setObjectName("menuGiao_di_n_i_u_khi_n_nh_m_7");
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuGiao_di_n_i_u_khi_n_nh_m_7->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        parameter_screen->setText(QCoreApplication::translate("MainWindow", "Angle ", nullptr));
        connect_status->setText(QCoreApplication::translate("MainWindow", "Not connect", nullptr));
        record_status->setText(QCoreApplication::translate("MainWindow", "record status", nullptr));
        startrc_btn->setText(QCoreApplication::translate("MainWindow", "START", nullptr));
        endrc_btn->setText(QCoreApplication::translate("MainWindow", "END", nullptr));
        send_btn->setText(QCoreApplication::translate("MainWindow", "SEND", nullptr));
        connect_btn->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        logo1->setText(QString());
        logo2->setText(QString());
        radioButton->setText(QCoreApplication::translate("MainWindow", "Controller Mode", nullptr));
        radioButton_2->setText(QCoreApplication::translate("MainWindow", "Imageprocess Mode", nullptr));
        angle1_value->setText(QCoreApplication::translate("MainWindow", "Angle1", nullptr));
        angle2_value->setText(QCoreApplication::translate("MainWindow", "Angle2", nullptr));
        angle6_value->setText(QCoreApplication::translate("MainWindow", "Angle6", nullptr));
        angle3_value->setText(QCoreApplication::translate("MainWindow", "Angle 3", nullptr));
        angle4_value->setText(QCoreApplication::translate("MainWindow", "Angle4", nullptr));
        angle5_value->setText(QCoreApplication::translate("MainWindow", "Angle5", nullptr));
        yellow_gripper->setText(QCoreApplication::translate("MainWindow", "G\341\272\256P", nullptr));
        imageValue_screen->setText(QCoreApplication::translate("MainWindow", "\304\220i\341\273\203m g\341\272\257p + T\341\273\215a \304\221\341\273\231 g\341\272\257p", nullptr));
        menuGiao_di_n_i_u_khi_n_nh_m_7->setTitle(QCoreApplication::translate("MainWindow", "Giao di\341\273\207n \304\221i\341\273\201u khi\341\273\203n nh\303\263m 7", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
