#ifndef _contouring_H_
#define _contouring_H_

#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

class Contouring {
public:
    static Mat ChainApproxSimple(const Mat& img, const Mat& thresh) ;
};

#endif
