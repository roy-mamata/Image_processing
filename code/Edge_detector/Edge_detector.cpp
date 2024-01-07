#include "Edge_detector.hpp"

using namespace cv;
using namespace std;


    Mat EdgeDetector::SobelEdgeDetector(const Mat& img) {
        Mat sobelx, sobely, sobelxy;
        Sobel(img, sobelx, CV_64F, 1, 0, 5);
        Sobel(img, sobely, CV_64F, 0, 1, 5);
        Sobel(img, sobelxy, CV_64F, 1, 1, 5);
        return sobelxy;
    }

    Mat EdgeDetector::CannyEdgeDetector(const Mat& img) {
        Mat edges;
        Canny(img, edges, 100, 200, 3, false);
        return edges;
    }
