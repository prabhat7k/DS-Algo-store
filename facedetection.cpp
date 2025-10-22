#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

void detectFaces(const string& imagePath) {
    CascadeClassifier faceCascade;
    if (!faceCascade.load("haarcascade_frontalface_default.xml")) {
        cerr << "Error loading face cascade.\n";
        return;
    }

    Mat img = imread(imagePath);
    if (img.empty()) {
        cerr << "Could not open image file.\n";
        return;
    }

    vector<Rect> faces;
    Mat gray;
    cvtColor(img, gray, COLOR_BGR2GRAY);
    faceCascade.detectMultiScale(gray, faces, 1.1, 4);

    for (auto& face : faces) {
        rectangle(img, face, Scalar(255, 0, 0), 2);
    }

    imshow("Detected Faces", img);
    waitKey(0);
}

int main() {
    detectFaces("photo.jpg");
    return 0;
}
