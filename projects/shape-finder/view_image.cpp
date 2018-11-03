#include <opencv2/opencv.hpp>

#include <iostream>

int main(int argc, char** argv)
{
  using namespace std;
  if (argc != 2) {
    cerr << "Usage: " << argv[0] << " IMAGE" << endl;
    return 1;
  }

  cv::Mat image = cv::imread(argv[1]);
  if (!image.data) {
    cerr << "Could not open or find image: " << argv[1] << endl;
    return 1;
  }
  
  cv::namedWindow(argv[1], cv::WINDOW_AUTOSIZE);
  cv::imshow(argv[1], image);
  cv::waitKey(0);
  return 0;
}