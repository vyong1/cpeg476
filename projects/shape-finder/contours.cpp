#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace cv;
using namespace std;

void identify_contours(Mat img);

int main(int argc, char **argv)
{
    // Load source image and convert it to gray
    Mat img = imread(argv[1], 1);

    // Create Window
    namedWindow("Source", CV_WINDOW_AUTOSIZE);
    imshow("Source", img);

    identify_contours(img);

    waitKey(0);
    return (0);
}

void identify_contours(Mat img)
{
    int thresh = 100;
    Mat canny_output;
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;

    Scalar contourColor = Scalar(255, 0, 0); // RGB

    // Detect edges using canny
    Canny(img, canny_output, thresh, thresh * 2, 3);
    // Find contours
    findContours(canny_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE);

    // Draw contours
    Mat drawing = img.clone();
    for (unsigned int i = 0; i < contours.size(); i++)
    {
        drawContours(drawing, contours, i, contourColor, 2, 8, hierarchy, 0, Point());
    }

    // Show in a window
    namedWindow("Contours", CV_WINDOW_AUTOSIZE);
    imshow("Contours", drawing);

    // Write output to image
    imwrite("myimage.png", drawing);
}