using namespace cv;
using namespace std;

/* 
    Parse command line arguments 
*/
int parse_args(int argc, char** argv, string* shape, string* color, string* output_image);

/* 
    Print the usage of the command
*/
void print_usage();

/* 
    Parse either a color out of a set of values or a hex representation of a (0, 256) RGB
    color into an RGB color Scalar
*/
Scalar parse_color_string(string color_string);

/* 
    From an image, identify the specified shape and draw contours around it
*/
void identify_and_draw_contours(Mat img, Scalar contour_color, string shape);

/* 
    Find the contours that match the description of the shape
*/
vector<int> get_contours_to_draw(vector<vector<Point>> contours, string shape);