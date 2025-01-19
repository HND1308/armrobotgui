#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cameraapp.h"
#include <QMessageBox>
#include <QDebug>
#include <QStringList>
#include <QException>
#include <opencv2/opencv.hpp>
#include <QTimer>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    serialPort = new QSerialPort(this);
    serialPort->setPortName("COM4");
    serialPort->setBaudRate(QSerialPort::Baud9600);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);
    ui->send_btn->setEnabled(false);
    ui->endrc_btn->setEnabled(false);
    ui->startrc_btn->setEnabled(false);
    ui->radioButton->setEnabled(false);
    ui->radioButton_2->setEnabled(false);

    timer = new QTimer(this);

}

MainWindow::~MainWindow()
{
    if (serialPort && serialPort->isOpen()) {
        serialPort->close();
    }
    delete serialPort;
    timer->stop();
    delete timer;
    delete ui;
    if (cameraApp) delete cameraApp;
}

void MainWindow::on_connect_btn_clicked()
{
    if (ui->connect_btn->text() == "Connect") {
        if (!serialPort->isOpen()) {
            if (serialPort->open(QIODevice::ReadWrite)) {
                ui->connect_status->setText("Connected");
                ui->connect_btn->setText("Disconnect");
                ui->radioButton->setEnabled(true);
                ui->radioButton_2->setEnabled(true);
            } else {
                ui->connect_status->setText("Connection failed: " + serialPort->errorString());
                QMessageBox::critical(this, "Lỗi", "Không thể mở cổng nối tiếp: " + serialPort->errorString());
            }
        }
    } else {
        if (serialPort->isOpen()) {
            serialPort->close();
            ui->connect_status->setText("Disconnected");
            ui->connect_btn->setText("Connect");
            ui->send_btn->setEnabled(false);
            ui->endrc_btn->setEnabled(false);
            ui->startrc_btn->setEnabled(false);
            ui->radioButton->setEnabled(false);
            ui->radioButton_2->setEnabled(false);
        }
    }
}

void MainWindow::on_send_btn_clicked()
{
    if (serialPort && serialPort->isOpen()) {
        QList<int> data;
        data << ui->angle1_slider->value()
             << ui->angle2_slider->value()
             << ui->angle3_slider->value()
             << ui->angle4_slider->value()
             << ui->angle5_slider->value()
             << ui->angle6_slider->value();

        const QString result = formatDataToSend(data);

        qint64 bytesWritten = serialPort->write(result.toUtf8());
        if (bytesWritten == -1) {
            QMessageBox::critical(this, "Lỗi", "Lỗi gửi dữ liệu: " + serialPort->errorString());
        } else if (bytesWritten != result.toUtf8().size()) {
            QMessageBox::warning(this, "Cảnh báo", "Không gửi được toàn bộ dữ liệu!");
        } else {
            if (serialPort->waitForBytesWritten(500)) {
                ui->parameter_screen->setText(result);
            } else {
                QMessageBox::warning(this, "Cảnh báo", "Timeout khi gửi dữ liệu!");
            }
        }
    } else {
        QMessageBox::warning(this, "Cảnh báo", "Vui lòng kết nối thiết bị trước khi gửi dữ liệu!");
    }
}

void MainWindow::on_radioButton_released()
{
    cameraActive = false;
    ui->send_btn->setEnabled(true);
    ui->startrc_btn->setEnabled(true);
    if (cameraApp){
        disconnect(this, &MainWindow::sendDataToSerialPort, this, &MainWindow::sendDataToESP32);
        disconnect(cameraApp, &CameraApp::sendDataToMain, this, &MainWindow::on_cameraDataReceived);
        delete cameraApp;
        cameraApp = nullptr;
    }
}

void MainWindow::on_radioButton_2_released()
{
    cameraActive = true;
    ui->send_btn->setEnabled(false);

    // Khởi tạo CameraApp và thêm vào layout
    cameraApp = new CameraApp(this);
    ui->gridLayout->addWidget(cameraApp, 0, 0, 1, 5);
    connect(this, &MainWindow::sendDataToSerialPort, this, &MainWindow::sendDataToESP32);
    connect(cameraApp, &CameraApp::sendDataToMain, this, &MainWindow::on_cameraDataReceived);


}

void MainWindow::on_angle1_slider_valueChanged(int value)
{
    ui->angle1_value->setText(QString::number(value));
}

void MainWindow::on_angle2_slider_valueChanged(int value)
{
    ui->angle2_value->setText(QString::number(value));
}

void MainWindow::on_angle3_slider_valueChanged(int value)
{
    ui->angle3_value->setText(QString::number(value));
}

void MainWindow::on_angle4_slider_valueChanged(int value)
{
    ui->angle4_value->setText(QString::number(value));
}

void MainWindow::on_angle5_slider_valueChanged(int value)
{
    ui->angle5_value->setText(QString::number(value));
}

void MainWindow::on_angle6_slider_valueChanged(int value)
{
    ui->angle6_value->setText(QString::number(value));
}

void MainWindow::on_startrc_btn_clicked()
{
    if(!cameraActive && serialPort && serialPort->isOpen()){
        recordedAngles.clear();
        isRecording = true;
        ui->record_status->setText("Recording");
        ui->startrc_btn->setEnabled(false);
        ui->endrc_btn->setEnabled(true);
    } else if (cameraActive){
        QMessageBox::warning(this, "Warning", "This function is not enabled when camera is active");
    }else{
        QMessageBox::warning(this, "Warning", "Connect to port before recording");
    }
}
void MainWindow::on_endrc_btn_clicked()
{
    isRecording = false;
    if(!cameraActive && serialPort && serialPort->isOpen()){

        QTimer::singleShot(200, this, [this]() {
            QString data = "r,";
            for (int i = 0; i < recordedAngles.size(); i++) {
                QStringList values;
                for (int j = 0; j < recordedAngles[i].size(); j++) {
                    values << QString::number(recordedAngles[i][j]);
                }
                data += values.join(",");
                if (i < recordedAngles.size() - 1) {
                    data += ";";
                }
            }
            data += "\n";

            if (serialPort && serialPort->isOpen()) {
                qint64 bytesWritten = serialPort->write(data.toUtf8());
                if (bytesWritten == -1) {
                    QMessageBox::critical(this, "Lỗi", "Lỗi gửi dữ liệu record: " + serialPort->errorString());
                } else if (bytesWritten != data.toUtf8().size()) {
                    QMessageBox::warning(this, "Cảnh báo", "Không gửi được toàn bộ dữ liệu record!");
                } else {
                    if (serialPort->waitForBytesWritten(500)) {
                        ui->record_status->setText("Record finish");
                    } else {
                        QMessageBox::warning(this, "Cảnh báo", "Timeout khi gửi dữ liệu record!");
                    }
                }
            } else {
                QMessageBox::warning(this, "Warning", "Disconnected from port");
            }
            ui->startrc_btn->setEnabled(true);
            ui->endrc_btn->setEnabled(false);
        });
    }
    else if (cameraActive){
        QMessageBox::warning(this, "Warning", "This function is not enabled when camera is active");
    }else{
        QMessageBox::warning(this, "Warning", "Connect to port before recording");
    }
}

QString MainWindow::formatDataToSend(const QList<int>& data) const
{
    QString result = "n,";
    for (int i = 0; i < data.size(); ++i) {
        result += QString::number(data[i]);
        if (i < data.size() - 1) {
            result += ",";
        }
    }
    result += "\n";
    return result;
}

void MainWindow::update_Angle_Record()
{
    if (isRecording) {
        QVector<int> newAngles;
        newAngles << ui->angle1_slider->value()
                  << ui->angle2_slider->value()
                  << ui->angle3_slider->value()
                  << ui->angle4_slider->value()
                  << ui->angle5_slider->value()
                  << ui->angle6_slider->value();

        if (!recordedAngles.isEmpty() && newAngles != recordedAngles.last()) {
            recordedAngles.append(newAngles);
        } else if (recordedAngles.isEmpty()){
            recordedAngles.append(newAngles);
        }
    }
}
QString imageResult;

void MainWindow::on_cameraDataReceived(const QString &data)
{
    if (cameraActive && serialPort && serialPort->isOpen()) {
        ui->imageValue_screen->setText(QString("%1 ").arg(data));
        imageResult = data;
    }

}

void MainWindow::on_yellow_gripper_clicked()
{
    emit sendDataToSerialPort(imageResult);
}

void MainWindow::sendDataToESP32(){
    if (serialPort && serialPort->isOpen()) {
        serialPort->write((imageResult + "\n").toUtf8());
    }
}

