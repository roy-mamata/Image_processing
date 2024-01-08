#ifndef _basic_processing_H_
#define _basic_processing_H_

#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

class BasicProcessor {

private:

    static BasicProcessor* Instance;
    string imagePath_;
    BasicProcessor()=default; 
    ~BasicProcessor() = default;
    
    
public:
    BasicProcessor(const BasicProcessor& obj)=delete;
    
    static BasicProcessor* getInstance();
    
    void setValues(string imagePath);

    Mat readImage() const;

    void displayImage(const string& windowName, const Mat& img) const;

    Mat convertToGrayscale(const Mat& img) const;

    Mat applyGaussianBlur(const Mat& img) const;
    
    Mat applyThreshold(const Mat& img) const;

};

#endif
