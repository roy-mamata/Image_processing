#ifndef _Edge_detector_H_
#define _Edge_detector_H_

#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

class EdgeDetector {
public:
    static Mat SobelEdgeDetector(const Mat& img) ;

    static Mat CannyEdgeDetector(const Mat& img); 
};

#endif
