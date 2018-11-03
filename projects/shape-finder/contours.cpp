#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace cv;
using namespace std;

void print_usage();
void identify_contours(Mat img);
vector<int> get_contours_to_draw(vector<vector<Point>> contours);

int main(int argc, char **argv)
{
    // Parse arguments
    if(argc > 1 && strcmp(argv[1], "-h") == 0)
    {
        print_usage();
        return 0;
    }

    if(argc != 7)
    {
        cout << "Incorrect usage. Use the '-h' flag for more information" << endl;
        return 0;
    }

    string shape;
    string color;
    string output_image;

    for(int i = 0; i < argc; i++)
    {
        string arg(argv[i]);
    }

    // Load source image and convert it to gray
    Mat img = imread(argv[1], 1);

    // Create Window
    // namedWindow("Source", CV_WINDOW_AUTOSIZE);
    // imshow("Source", img);

    identify_contours(img);

    waitKey(0);
    return (0);
}

void print_usage()
{
    cout << "---- Usage ----" << endl;
    cout << " Flags:" << endl;
    cout << "   -s, --shape     Specify a shape <triangle, square, rectangle, pentagon, hexagon, circle>" << endl;
    cout << "   -c, --color     Specify an RGB hex color (e.g. #ff00ff)" << endl;
    cout << "   -o              The output image" << endl;
    cout << " All 3 flags must be used." << endl;
    cout << " Example usage: 'contours -s triangle -c 00af05 -o myimage.png'" << endl;
}

void identify_contours(Mat img)
{
    int thresh = 100;
    Mat canny_output;
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;

    // Scalar contourColor = Scalar(255, 0, 0); // RGB

    // Detect edges using canny
    Canny(img, canny_output, thresh, thresh * 2, 3);
    // Find contours
    findContours(canny_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE);
    


    // Draw contours
    /*
    Mat drawing = img.clone();
    for (unsigned int i = 0; i < contours.size(); i++)
    {
        drawContours(drawing, contours, i, contourColor, 2, 8, hierarchy, 0, Point());
    }

    // Show in a window
    namedWindow("Contours", CV_WINDOW_AUTOSIZE);
    imshow("Contours", drawing);

    
    */

    // Write output to image
    imwrite("myimage.png", img.clone());
}

vector<int> get_contours_to_draw(vector<vector<Point>> contours, string requestedShape)
{
    vector<int> contoursToDraw;

    // Find contours as polygons
    for (unsigned int i = 0; i < contours.size(); i++)
    {
        vector<Point> contour = contours[i];
        vector<Point> curve;
        float epsilon = 0.01 * arcLength(contour, true); // 1% of contour perimeter

        approxPolyDP(contour, curve, epsilon, true);

        int numberOfCorners = curve.size();

        switch(numberOfCorners)
        {
            case 3: // Triangle
                break;
            case 4: // Rectangle
                // Parse square first
                break;
            case 5: // Pentagon
                break;
            case 16: // Circle
                break;
            default:
                break;
        }
    }


    /*
     
    TODO !!!
    
    */
    return contoursToDraw;
}