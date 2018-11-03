using namespace cv;
using namespace std;

int parse_args(int argc, char** argv, string* shape, string* color, string* output_image);
void print_usage();
Scalar parse_color_string(string color_string);
void identify_and_draw_contours(Mat img, Scalar contour_color, string shape);
vector<int> get_contours_to_draw(vector<vector<Point>> contours, string shape);