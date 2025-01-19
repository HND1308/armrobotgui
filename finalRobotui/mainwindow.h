#include "cameraapp.h"
#include <QFileDialog>
#include <QImage>
#include <QPixmap>

#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QtSerialPort>
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

signals: // Thêm tín hiệu
    void sendDataToSerialPort(const QString &data);

private slots:
    void on_connect_btn_clicked();
    void on_send_btn_clicked();
    void on_radioButton_released();
    void on_radioButton_2_released();
    void on_angle1_slider_valueChanged(int value);
    void on_angle2_slider_valueChanged(int value);
    void on_angle3_slider_valueChanged(int value);
    void on_angle4_slider_valueChanged(int value);
    void on_angle5_slider_valueChanged(int value);
    void on_angle6_slider_valueChanged(int value);
    void on_startrc_btn_clicked();
    void on_endrc_btn_clicked();
    void on_cameraDataReceived(const QString &data); // Thêm slot
    void on_yellow_gripper_clicked();
    void sendDataToESP32();
private:
    Ui::MainWindow *ui;
    QSerialPort *serialPort;
    bool isRecording = false;
    QVector<QVector<int>> recordedAngles;
    QList<int> currentAngles;
    QTimer *timer;
    QString formatDataToSend(const QList<int>& data) const;
    void update_Angle_Record();
    CameraApp *cameraApp; // Thêm biến CameraApp
    bool cameraActive = false;
};
#endif // MAINWINDOW_H
