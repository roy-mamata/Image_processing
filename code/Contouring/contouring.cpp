#include "contouring.hpp"

using namespace cv;
using namespace std;


    Mat Contouring::ChainApproxSimple(const Mat& img, const Mat& thresh) {
        vector<vector<Point>> contours;
        // detect contours on thresholded image
        findContours(thresh, contours, RETR_TREE, CHAIN_APPROX_NONE);
        
       // draw contours on the original image
        Mat image_copy = img.clone();
        drawContours(image_copy, contours, -1, Scalar(0, 255, 0), 2);
          
        return image_copy;
    }
