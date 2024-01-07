#include "basic_processing.hpp"

using namespace cv;
using namespace std;

    BasicProcessor::BasicProcessor(const std::string& imagePath) : imagePath_(imagePath) {}

    Mat BasicProcessor:: readImage() const {
        Mat img = imread(imagePath_);
        if (img.empty()) {
            cout<< "Error: Could not read the image." << std::endl;
        }
        return img;
    }

    void BasicProcessor::displayImage(const string& windowName, const Mat& img) const {
        imshow(windowName, img);
        waitKey(0);
    }

    Mat BasicProcessor::convertToGrayscale(const Mat& img) const {
        Mat grayImg;
        cvtColor(img, grayImg, cv::COLOR_BGR2GRAY);
        return grayImg;
    }

    Mat BasicProcessor::applyGaussianBlur(const Mat& img) const {
        Mat blurredImg;
        GaussianBlur(img, blurredImg, Size(3, 3), 0);
        return blurredImg;
    }
    
    Mat BasicProcessor::applyThreshold(const Mat& img) const{
    	Mat threshImg;
    	threshold(img, threshImg, 150, 255, THRESH_BINARY);
    	return threshImg;
    	}


