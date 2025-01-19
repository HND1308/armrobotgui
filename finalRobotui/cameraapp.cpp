#include "cameraapp.h"

CameraApp::CameraApp(QWidget *parent) : QWidget(parent) {
    // Setup GUI layout
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    imageLabel = new QLabel(this);
    layout->addWidget(imageLabel);
    imageLabel->setScaledContents(true);

    // Start the camera
    string ip_camera_url = "http://192.168.227.124:8080/video"; // Camera IP URL
    cap.open(ip_camera_url);
    if (!cap.isOpened()) {
        cerr << "Unable to connect to camera." << endl;
        return;
    }

    // Setup a timer to periodically capture frames
    captureTimer = new QTimer(this);
    connect(captureTimer, &QTimer::timeout, this, &CameraApp::captureFrame);
    captureTimer->start(30);  // 30 ms for approx 30 FPS
    // Get camera resolution
    double cameraWidth = cap.get(cv::CAP_PROP_FRAME_WIDTH);
    double cameraHeight = cap.get(cv::CAP_PROP_FRAME_HEIGHT);
    double cameraAspect = cameraWidth / cameraHeight;
    // Set window size based on camera aspect ratio
    resize(600, 600 / cameraAspect); // try this
}

CameraApp::~CameraApp() {
    cap.release();
}

void CameraApp::applyNoiseFilter(Mat &image) {
    switch (filterType) {
    case 0: // Gaussian Blur
        GaussianBlur(image, image, Size(9, 9), 2, 2);
        break;
    case 1: // Median Blur
        medianBlur(image, image, 5); // Kernel size 5
        break;
    case 2: // Bilateral Filter
        bilateralFilter(image, image, 9, 75, 75); // Diameter, sigmaColor, sigmaSpace
        break;
    default:
        break;
    }
}

void CameraApp::captureFrame() {
    Mat frame;
    cap >> frame;
    if (frame.empty()) {
        cerr << "Failed to capture frame." << endl;
        return;
    }

    // Apply noise filter before processing
    applyNoiseFilter(frame);

    // Convert the frame to HSV color space
    Mat hsv_frame;
    cvtColor(frame, hsv_frame, COLOR_BGR2HSV);

    // Define color ranges for yellow and red
    Scalar lower_yellow(20, 100, 100), upper_yellow(40, 255, 255);
    Scalar lower_red1(0, 100, 100), upper_red1(10, 255, 255);
    Scalar lower_red2(160, 100, 100), upper_red2(180, 255, 255);

    // Create masks for yellow and red
    Mat mask_yellow, mask_red1, mask_red2, mask_red;
    inRange(hsv_frame, lower_yellow, upper_yellow, mask_yellow);
    inRange(hsv_frame, lower_red1, upper_red1, mask_red1);
    inRange(hsv_frame, lower_red2, upper_red2, mask_red2);
    addWeighted(mask_red1, 1.0, mask_red2, 1.0, 0.0, mask_red);

    // Find contours
    vector<vector<Point>> contours_yellow, contours_red;
    findContours(mask_yellow, contours_yellow, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    findContours(mask_red, contours_red, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

    Mat result = frame.clone();
    QString combinedData = "";
    bool yellowDetected = false;
    bool redDetected = false;
    cv::Point2f center = cv::Point2f(-1, -1);
    QString position = "";
    float halfWidth = frame.cols / 2.0f; // Use frame.cols / 2.0f
    // Process yellow contours
    for (const auto& contour : contours_yellow) {
        if (contourArea(contour) < 500) continue;
        yellowDetected = true;
        Rect yellow_box = boundingRect(contour);
        rectangle(result, yellow_box, Scalar(0, 255, 255), 2);

        center.x = yellow_box.x + yellow_box.width / 2;
        center.y = yellow_box.y + yellow_box.height / 2;

        int center_x = yellow_box.x + yellow_box.width / 2;
        int center_y = yellow_box.y + yellow_box.height / 2;

        // Determine the quadrant (A, B, C, D)
        if(center_x < halfWidth){
            position += "B1";
        }else{
            position += "B2";
        }
    }

    // Process red contours
    for (const auto& contour : contours_red) {
        if (contourArea(contour) < 500) continue;
        redDetected = true;
        Rect red_box = boundingRect(contour);
        rectangle(result, red_box, Scalar(0, 0, 255), 2);
        center.x = red_box.x + red_box.width / 2;
        center.y = red_box.y + red_box.height / 2;

        int center_x = red_box.x + red_box.width / 2;
        int center_y = red_box.y + red_box.height / 2;
        if(center_x < halfWidth){
            position += "A1";
        }else{
            position += "A2";
        }
    }

    if(yellowDetected && redDetected) {
        if(position == "A2B2" || position == "B2A2"){
            combinedData = "A2,B2";
        } else if(position == "A1B1" || position == "B1A1"){
            combinedData = "A1,B1";
        }else if(position == "A1B2" || position == "B2A1"){
            combinedData = "A1,B2";
        } else if(position == "A2B1" || position == "B1A2"){
            combinedData = "A2,B1";
        }
    }else if(redDetected) {
        combinedData = position;
    } else if (yellowDetected){
        combinedData = position;
    }


    QString data = QString("i,%1").arg(combinedData);
    emit sendPositionToMain(position,center);
    emit sendDataToMain(data);

    // Display result
    QImage img(result.data, result.cols, result.rows, result.step, QImage::Format_BGR888);
    imageLabel->setPixmap(QPixmap::fromImage(img));
}

void CameraApp::sendToESP32(const QString &data) {
    emit sendDataToMain(data);
}
