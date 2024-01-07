#ifndef _basic_processing_H_
#define _basic_processing_H_

#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

class BasicProcessor {
public:
    BasicProcessor(const std::string& imagePath);

    Mat readImage() const;

    void displayImage(const string& windowName, const Mat& img) const;

    Mat convertToGrayscale(const Mat& img) const;

    Mat applyGaussianBlur(const Mat& img) const;
    
    Mat applyThreshold(const Mat& img) const;

private:
    string imagePath_;
};

#endif
