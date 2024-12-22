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
    QPushButton *stop_btn;
    QPushButton *record_btn;
    QPushButton *send_btn;
    QRadioButton *connect_btn;
    QRadioButton *disconnect_btn;
    QSlider *angle1_slider;
    QSlider *angle2_slider;
    QSlider *angle3_slider;
    QSlider *angle4_slider;
    QSlider *angle5_slider;
    QSlider *angle6_slider;
    QLabel *output_screen;
    QLabel *record_st;
    QLabel *angle1_value;
    QLabel *angle2_value;
    QLabel *angle3_value;
    QLabel *angle4_value;
    QLabel *angle5_value;
    QLabel *angle6_value;
    QLabel *cnt_status;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QMenuBar *menubar;
    QMenu *menuController;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(949, 682);
        MainWindow->setWindowOpacity(1.000000000000000);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(212, 212, 212);\n"
"color: rgb(0, 0, 0);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stop_btn = new QPushButton(centralwidget);
        stop_btn->setObjectName("stop_btn");
        stop_btn->setGeometry(QRect(630, 50, 80, 40));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        stop_btn->setFont(font);
        stop_btn->setStyleSheet(QString::fromUtf8("background-color: rgb(124, 124, 124);\n"
"color: rgb(255, 255, 127);"));
        record_btn = new QPushButton(centralwidget);
        record_btn->setObjectName("record_btn");
        record_btn->setGeometry(QRect(530, 50, 83, 40));
        record_btn->setFont(font);
        record_btn->setStyleSheet(QString::fromUtf8("background-color: rgb(124, 124, 124);\n"
"color: rgb(255, 255, 127);"));
        record_btn->setCheckable(false);
        send_btn = new QPushButton(centralwidget);
        send_btn->setObjectName("send_btn");
        send_btn->setGeometry(QRect(70, 500, 101, 41));
        send_btn->setFont(font);
        send_btn->setStyleSheet(QString::fromUtf8("background-color: rgb(168, 168, 168);\n"
"color: rgb(255, 0, 0);"));
        connect_btn = new QRadioButton(centralwidget);
        connect_btn->setObjectName("connect_btn");
        connect_btn->setGeometry(QRect(30, 50, 112, 26));
        QFont font1;
        font1.setBold(true);
        connect_btn->setFont(font1);
        connect_btn->setStyleSheet(QString::fromUtf8("background-color: rgb(194, 194, 194);\n"
"color: rgb(0, 0, 0);\n"
""));
        disconnect_btn = new QRadioButton(centralwidget);
        disconnect_btn->setObjectName("disconnect_btn");
        disconnect_btn->setGeometry(QRect(30, 80, 112, 26));
        disconnect_btn->setFont(font1);
        disconnect_btn->setStyleSheet(QString::fromUtf8("background-color: rgb(194, 194, 194);\n"
"color: rgb(0, 0, 0);\n"
""));
        angle1_slider = new QSlider(centralwidget);
        angle1_slider->setObjectName("angle1_slider");
        angle1_slider->setGeometry(QRect(40, 230, 160, 18));
        angle1_slider->setStyleSheet(QString::fromUtf8(""));
        angle1_slider->setMaximum(180);
        angle1_slider->setOrientation(Qt::Orientation::Horizontal);
        angle2_slider = new QSlider(centralwidget);
        angle2_slider->setObjectName("angle2_slider");
        angle2_slider->setGeometry(QRect(310, 230, 160, 18));
        angle2_slider->setMinimum(120);
        angle2_slider->setMaximum(180);
        angle2_slider->setOrientation(Qt::Orientation::Horizontal);
        angle3_slider = new QSlider(centralwidget);
        angle3_slider->setObjectName("angle3_slider");
        angle3_slider->setGeometry(QRect(40, 285, 160, 18));
        angle3_slider->setMaximum(120);
        angle3_slider->setOrientation(Qt::Orientation::Horizontal);
        angle4_slider = new QSlider(centralwidget);
        angle4_slider->setObjectName("angle4_slider");
        angle4_slider->setGeometry(QRect(310, 285, 160, 18));
        angle4_slider->setMaximum(180);
        angle4_slider->setOrientation(Qt::Orientation::Horizontal);
        angle5_slider = new QSlider(centralwidget);
        angle5_slider->setObjectName("angle5_slider");
        angle5_slider->setGeometry(QRect(40, 340, 160, 18));
        angle5_slider->setMaximum(180);
        angle5_slider->setOrientation(Qt::Orientation::Horizontal);
        angle6_slider = new QSlider(centralwidget);
        angle6_slider->setObjectName("angle6_slider");
        angle6_slider->setGeometry(QRect(310, 340, 160, 18));
        angle6_slider->setMinimum(30);
        angle6_slider->setMaximum(120);
        angle6_slider->setOrientation(Qt::Orientation::Horizontal);
        output_screen = new QLabel(centralwidget);
        output_screen->setObjectName("output_screen");
        output_screen->setGeometry(QRect(200, 480, 611, 71));
        QFont font2;
        font2.setWeight(QFont::ExtraBold);
        font2.setItalic(false);
        font2.setUnderline(false);
        output_screen->setFont(font2);
        output_screen->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        output_screen->setWordWrap(false);
        output_screen->setOpenExternalLinks(false);
        output_screen->setTextInteractionFlags(Qt::TextInteractionFlag::LinksAccessibleByMouse|Qt::TextInteractionFlag::TextSelectableByKeyboard|Qt::TextInteractionFlag::TextSelectableByMouse);
        record_st = new QLabel(centralwidget);
        record_st->setObjectName("record_st");
        record_st->setGeometry(QRect(600, 100, 50, 20));
        record_st->setStyleSheet(QString::fromUtf8("background-color: rgb(152, 152, 152);\n"
"color: rgb(255, 255, 255);"));
        record_st->setAlignment(Qt::AlignmentFlag::AlignCenter);
        angle1_value = new QLabel(centralwidget);
        angle1_value->setObjectName("angle1_value");
        angle1_value->setGeometry(QRect(210, 230, 63, 20));
        angle1_value->setStyleSheet(QString::fromUtf8("background-color: rgb(188, 188, 188);\n"
"color: rgb(0, 0, 0);"));
        angle2_value = new QLabel(centralwidget);
        angle2_value->setObjectName("angle2_value");
        angle2_value->setGeometry(QRect(480, 230, 63, 20));
        angle2_value->setStyleSheet(QString::fromUtf8("background-color: rgb(188, 188, 188);\n"
"color: rgb(0, 0, 0);"));
        angle3_value = new QLabel(centralwidget);
        angle3_value->setObjectName("angle3_value");
        angle3_value->setGeometry(QRect(210, 285, 63, 20));
        angle3_value->setStyleSheet(QString::fromUtf8("background-color: rgb(188, 188, 188);\n"
"color: rgb(0, 0, 0);"));
        angle4_value = new QLabel(centralwidget);
        angle4_value->setObjectName("angle4_value");
        angle4_value->setGeometry(QRect(480, 285, 63, 20));
        angle4_value->setStyleSheet(QString::fromUtf8("background-color: rgb(188, 188, 188);\n"
"color: rgb(0, 0, 0);"));
        angle5_value = new QLabel(centralwidget);
        angle5_value->setObjectName("angle5_value");
        angle5_value->setGeometry(QRect(210, 340, 63, 20));
        angle5_value->setStyleSheet(QString::fromUtf8("background-color: rgb(188, 188, 188);\n"
"color: rgb(0, 0, 0);"));
        angle6_value = new QLabel(centralwidget);
        angle6_value->setObjectName("angle6_value");
        angle6_value->setGeometry(QRect(480, 340, 63, 20));
        angle6_value->setStyleSheet(QString::fromUtf8("background-color: rgb(188, 188, 188);\n"
"color: rgb(0, 0, 0);"));
        cnt_status = new QLabel(centralwidget);
        cnt_status->setObjectName("cnt_status");
        cnt_status->setGeometry(QRect(160, 70, 341, 20));
        cnt_status->setStyleSheet(QString::fromUtf8("background-color: rgb(194, 194, 194);\n"
"color: rgb(0, 0, 0);"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 200, 541, 191));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(104, 104, 104);"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(830, 0, 101, 91));
        label_2->setStyleSheet(QString::fromUtf8("image: url(:/image/\341\272\242nh \341\273\224 D/logo-hust.png);"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(800, 600, 121, 31));
        label_3->setStyleSheet(QString::fromUtf8("image: url(:/image/\341\272\242nh \341\273\224 D/hust.png);"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(670, 240, 191, 121));
        QFont font3;
        font3.setBold(true);
        font3.setItalic(true);
        label_4->setFont(font3);
        label_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        MainWindow->setCentralWidget(centralwidget);
        label->raise();
        stop_btn->raise();
        record_btn->raise();
        send_btn->raise();
        connect_btn->raise();
        disconnect_btn->raise();
        angle1_slider->raise();
        angle2_slider->raise();
        angle3_slider->raise();
        angle4_slider->raise();
        angle5_slider->raise();
        angle6_slider->raise();
        output_screen->raise();
        record_st->raise();
        angle1_value->raise();
        angle2_value->raise();
        angle3_value->raise();
        angle4_value->raise();
        angle5_value->raise();
        angle6_value->raise();
        cnt_status->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 949, 25));
        menuController = new QMenu(menubar);
        menuController->setObjectName("menuController");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuController->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "CONTROLLER", nullptr));
        stop_btn->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        record_btn->setText(QCoreApplication::translate("MainWindow", "Record", nullptr));
        send_btn->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        connect_btn->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        disconnect_btn->setText(QCoreApplication::translate("MainWindow", "Disconnect", nullptr));
        output_screen->setText(QCoreApplication::translate("MainWindow", "Angle Value", nullptr));
        record_st->setText(QCoreApplication::translate("MainWindow", "STATUS", nullptr));
        angle1_value->setText(QCoreApplication::translate("MainWindow", "Value", nullptr));
        angle2_value->setText(QCoreApplication::translate("MainWindow", "Value", nullptr));
        angle3_value->setText(QCoreApplication::translate("MainWindow", "Value", nullptr));
        angle4_value->setText(QCoreApplication::translate("MainWindow", "Value", nullptr));
        angle5_value->setText(QCoreApplication::translate("MainWindow", "Value", nullptr));
        angle6_value->setText(QCoreApplication::translate("MainWindow", "Value", nullptr));
        cnt_status->setText(QCoreApplication::translate("MainWindow", "Disconnected", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Nh\303\263m 7 </p><p>Nguy\341\273\205n \304\220\341\273\251c Huy </p><p>V\305\251 Th\303\240nh \304\220\341\273\251c </p><p>\304\220\341\273\227 Ho\303\240ng Minh</p></body></html>", nullptr));
        menuController->setTitle(QCoreApplication::translate("MainWindow", "Nh\303\263m 7", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
