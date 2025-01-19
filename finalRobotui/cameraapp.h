#ifndef CAMERAAPP_H
#define CAMERAAPP_H

#include <QCoreApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QImage>
#include <QPixmap>
#include <QTimer>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <opencv2/opencv.hpp>
#include <QVector>

using namespace cv;
using namespace std;

class CameraApp : public QWidget {
    Q_OBJECT

public:
    CameraApp(QWidget *parent = nullptr);
    ~CameraApp();
signals:
    void sendDataToMain(const QString &data);
    void sendPositionToMain(const QString &position,const cv::Point2f &center);
private slots:
    void captureFrame();

private:
    QLabel *imageLabel;
    QTimer *captureTimer;
    QSerialPort *serialPort;
    VideoCapture cap;
    float fx = 500.0f, fy = 500.0f;  // Camera focal length
    float cx = 320.0f, cy = 240.0f;  // Camera center
    float Z = 100.0f;  // Assumed distance
    int filterType = 0;  // 0 = Gaussian, 1 = Median, 2 = Bilateral

    void applyNoiseFilter(Mat &image);
    void sendToESP32(const QString &data);
    cv::Point2f detectedCenter;
    QString detectedPosition;
};
#endif // CAMERAAPP_H
