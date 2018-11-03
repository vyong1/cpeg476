#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contours.h"

using namespace cv;
using namespace std;

int main(int argc, char **argv)
{
    string shape;
    string color;
    string output_image;

    if(parse_args(argc, argv, &shape, &color, &output_image) == -1)
    {
        // Exit if args were parsed incorrectly
        return 0;
    }

    Scalar contour_color = parse_color_string(color);

    // Load source image and convert it to gray
    Mat img = imread("shapes.ppm", 1);

    identify_and_draw_contours(img, contour_color, shape);

    waitKey(0);
    return (0);
}

int parse_args(int argc, char** argv, string* shape, string* color, string* output_image)
{
    if (argc > 1 && strcmp(argv[1], "-h") == 0)
    {
        print_usage();
        return -1;
    }

    if (argc != 7)
    {
        cout << "Incorrect usage. Use the '-h' flag for more information" << endl;
        return -1;
    }

    for (int i = 1; i < argc; i++)
    {
        string arg(argv[i]);
        if (arg == "-c" || arg == "--color")
        {
            if (i + 1 < argc)
            {
                *color = argv[i + 1];
            }
            else
            {
                cout << "Incorrect usage. Use the '-h' flag for more information" << endl;
                return -1;
            }

            i++;
        }
        else if (arg == "-s" || arg == "--shape")
        {
            if (i + 1 < argc)
            {
                *shape = argv[i + 1];
            }
            else
            {
                cout << "Incorrect usage. Use the '-h' flag for more information" << endl;
                return -1;
            }

            i++;
        }
        else if (arg == "-o")
        {
            if (i + 1 < argc)
            {
                *output_image = argv[i + 1];
            }
            else
            {
                cout << "Incorrect usage. Use the '-h' flag for more information" << endl;
                return -1;
            }

            i++;
        }
        else
        {
            cout << "Incorrect usage. Use the '-h' flag for more information" << endl;
            return -1;
        }
    }

    return 1;
}

Scalar parse_color_string(string color_string)
{
    // Try pre-defined colors first
    if (color_string == "red")
        return Scalar(0, 0, 255);
    else if (color_string == "blue")
        return Scalar(255, 0, 0);
    else if (color_string == "green")
        return Scalar(0, 255, 0);
    else if (color_string == "white")
        return Scalar(255, 255, 255);
    else if (color_string == "black")
        return Scalar(0, 0, 0);
    else if (color_string == "grey")
        return Scalar(127, 127, 127);
    else // Parse as hex
    {
        int r, g, b;
        sscanf(color_string.c_str(), "%02x%02x%02x", &b, &g, &r);
        return Scalar(r, g, b);
    }
}

void print_usage()
{
    cout << "---- Usage ----" << endl;
    cout << " Flags:" << endl;
    cout << "   -s, --shape     Specify a shape <triangle, square, rectangle, pentagon, hexagon, circle>" << endl;
    cout << "   -c, --color     Specify an RGB hex color (e.g. ff00ff) or any of these" << endl;
    cout << "                   pre-defined colrs: <red, blue, green, white, black, grey>" << endl;
    cout << "   -o              The output image" << endl;
    cout << " All 3 flags must be used." << endl;
    cout << " Example usage: 'contours -s triangle -c 00af05 -o myimage.png'" << endl;
}

void identify_and_draw_contours(Mat img, Scalar contour_color, string shape)
{
    int thresh = 100;
    Mat canny_output;
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;

    // Detect edges with CAnny algorithm
    Canny(img, canny_output, thresh, thresh * 2, 3);
    // Find contours
    findContours(canny_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE);

    // Draw contours based on the requested shape
    vector<int> contours_to_draw = get_contours_to_draw(contours, shape);
    Mat output_img = img.clone();
    for (unsigned int i = 0; i < contours_to_draw.size(); i++)
    {
        drawContours(output_img, contours, contours_to_draw[i], contour_color, 2, 8, hierarchy, 0, Point());
    }

    // Write output to image
    imwrite("myimage.png", output_img);
}

vector<int> get_contours_to_draw(vector<vector<Point>> contours, string shape)
{
    vector<int> contoursToDraw;

    for (unsigned int i = 0; i < contours.size(); i++)
    {
        // Approximate contour as a polygon
        vector<Point> contour = contours[i];
        vector<Point> approx;
        float epsilon = 0.01 * arcLength(contour, true); // 1% of contour perimeter
        approxPolyDP(contour, approx, epsilon, true);
        int numberOfCorners = approx.size();

        switch (numberOfCorners)
        {
            case 3:
                if (shape == "triangle")
                {
                    contoursToDraw.push_back(i);
                }
                break;
            case 4:
                if (shape == "square")
                {
                    // Check if height = width (the condition for a square)
                    Rect br = boundingRect(approx);
                    if(br.size().height == br.size().width)
                    {
                        contoursToDraw.push_back(i);
                    }
                }
                else if (shape == "rectangle")
                {
                    contoursToDraw.push_back(i);
                }
                
                break;
            case 5:
                if (shape == "pentagon")
                {
                    contoursToDraw.push_back(i);
                }
                break;
            case 6:
                if (shape == "hexagon")
                {
                    contoursToDraw.push_back(i);
                }
                break;
            case 16:
                if (shape == "circle")
                {
                    contoursToDraw.push_back(i);
                }
                break;
            default:
                break;
        }
    }

    return contoursToDraw;
}