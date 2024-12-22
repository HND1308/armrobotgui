#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QTimer>
#include <QStringList>
#include <QtSerialPort/QSerialPort>
#include <QException>


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
    // Vô hiệu hóa nút stop khi khởi động
    ui->stop_btn->setEnabled(false);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::update_Angle_Record);
    timer->start(200); // Cập nhật mỗi 200ms

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
}

void MainWindow::on_connect_btn_released()
{
    if (ui->connect_btn->text() == "Connect") {
        if (!serialPort->isOpen()) {
            if (serialPort->open(QIODevice::ReadWrite)) {
                ui->cnt_status->setText("Connected");
                ui->connect_btn->setText("Disconnect");
                ui->send_btn->setEnabled(true);
            } else {
                ui->cnt_status->setText("Connection failed: " + serialPort->errorString());
                QMessageBox::critical(this, "Lỗi", "Không thể mở cổng nối tiếp: " + serialPort->errorString());
            }
        }
    } else {
        if (serialPort->isOpen()) {
            serialPort->close();
            ui->cnt_status->setText("Disconnected");
            ui->connect_btn->setText("Connect");
            ui->send_btn->setEnabled(false);
        }
    }
}

void MainWindow::on_record_btn_clicked()
{
    if(serialPort && serialPort->isOpen()){
        recordedAngles.clear();
        isRecording = true;
        ui->record_st->setText("Recording");
        ui->record_btn->setEnabled(false); // Vô hiệu hóa nút Record
        ui->stop_btn->setEnabled(true);    // Kích hoạt nút Stop
    } else {
        QMessageBox::warning(this, "Cảnh báo", "Vui lòng kết nối thiết bị trước!");
    }
}

void MainWindow::on_stop_btn_clicked()
{
    isRecording = false;
    if (serialPort && serialPort->isOpen()) {
        // Không gửi "RecordMode\n"
        // serialPort->write("RecordMode\n");

        // Sử dụng QTimer::singleShot thay vì QThread::msleep
        QTimer::singleShot(200, this, [this]() {
            QString data = "";
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
                    if (serialPort->waitForBytesWritten(500)) { // Đợi tối đa 500ms
                        ui->record_st->setText("Record finish");
                    } else {
                        QMessageBox::warning(this, "Cảnh báo", "Timeout khi gửi dữ liệu record!");
                    }
                }
            } else {
                QMessageBox::warning(this, "Warning", "Disconnected from port");
            }
            ui->record_btn->setEnabled(true); // Kích hoạt lại nút Record
            ui->stop_btn->setEnabled(false);   // Vô hiệu hóa nút Stop
        });
    }
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

QString MainWindow::formatDataToSend(const QList<int>& data) const
{
    QString result = "";
    for (int i = 0; i < data.size(); ++i) {
        result += QString::number(data[i]);
        if (i < data.size() - 1) {
            result += ",";
        }
    }
    result += "\n";
    return result;
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
            if (serialPort->waitForBytesWritten(500)) { // Đợi tối đa 500ms
                ui->output_screen->setText(result);
            } else {
                QMessageBox::warning(this, "Cảnh báo", "Timeout khi gửi dữ liệu!");
            }
        }
    } else {
        QMessageBox::warning(this, "Cảnh báo", "Vui lòng kết nối thiết bị trước khi gửi dữ liệu!");
    }
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

        // Chỉ ghi lại nếu giá trị thay đổi và mảng không rỗng
        if (!recordedAngles.isEmpty() && newAngles != recordedAngles.last()) {
            recordedAngles.append(newAngles);
        } else if (recordedAngles.isEmpty()){
            recordedAngles.append(newAngles);
        }
    }
}
