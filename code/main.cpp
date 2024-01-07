#include "basic_processing.hpp"
#include "Edge_detector.hpp"
#include "contouring.hpp"
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

int main() {
   BasicProcessor object=BasicProcessor::getInstance("../test.jpg");
    Mat originalImage = object.readImage();

    object.displayImage("Original Image", originalImage);

    Mat grayImage = object.convertToGrayscale(originalImage);
    Mat blurredImage = object.applyGaussianBlur(grayImage);
    Mat threshImage = object.applyThreshold(grayImage);

    Mat sobelEdges = EdgeDetector::SobelEdgeDetector(blurredImage);
    object.displayImage("Sobel XY using Sobel() function", sobelEdges);

    Mat cannyEdges = EdgeDetector::CannyEdgeDetector(blurredImage);
    object.displayImage("Canny edge detection", cannyEdges);
    
    Mat contourImage = Contouring::ChainApproxSimple(originalImage,threshImage);
    object.displayImage("Contouring", contourImage);

    destroyAllWindows();

    return 0;
}
