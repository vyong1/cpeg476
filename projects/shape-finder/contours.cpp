#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace cv;
using namespace std;

Mat src;
int thresh = 100;
RNG rng(12345);

void identify_contours();

int main(int argc, char **argv)
{
    // Load source image and convert it to gray
    src = imread(argv[1], 1);

    // Create Window
    namedWindow("Source", CV_WINDOW_AUTOSIZE);
    imshow("Source", src);

    identify_contours();

    waitKey(0);
    return (0);
}

void identify_contours()
{
    Mat canny_output;
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;

    // Detect edges using canny
    Canny(src, canny_output, thresh, thresh * 2, 3);
    // Find contours
    findContours(canny_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));

    // Draw contours
    Mat drawing = Mat::zeros(canny_output.size(), CV_8UC3);
    for (unsigned int i = 0; i < contours.size(); i++)
    {
        Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
        drawContours(drawing, contours, i, color, 2, 8, hierarchy, 0, Point());
    }

    // Show in a window
    namedWindow("Contours", CV_WINDOW_AUTOSIZE);
    imshow("Contours", drawing);
}