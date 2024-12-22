#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QVector>
#include <QTimer>

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
    void on_connect_btn_released();

    void on_record_btn_clicked();

    void on_angle1_slider_valueChanged(int value);

    void on_angle2_slider_valueChanged(int value);

    void on_angle3_slider_valueChanged(int value);

    void on_angle4_slider_valueChanged(int value);

    void on_angle5_slider_valueChanged(int value);

    void on_angle6_slider_valueChanged(int value);

    void on_send_btn_clicked();

    void on_stop_btn_clicked();

private:
    Ui::MainWindow *ui;
    QSerialPort *serialPort;
    bool isRecording = false;
    QVector<QVector<int>> recordedAngles; // Thay đổi kiểu dữ liệu
    QList<int> currentAngles;
    QTimer *timer;
    QString formatDataToSend(const QList<int>& data) const;
    void update_Angle_Record();
};
#endif // MAINWINDOW_H
