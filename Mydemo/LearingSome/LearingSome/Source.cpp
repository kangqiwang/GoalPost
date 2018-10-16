#include <opencv2/opencv.hpp>

#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat img = imread("D:/Git/Leaning_OpenCV/Mydemo/data/lena.png");
	if (img.empty()) {
		cout << "counld not image" << endl;
		return -1;
	}
	namedWindow("image", WINDOW_NORMAL);
	imshow("image", img);
	namedWindow("output_windows", CV_WINDOW_AUTOSIZE);
	Mat output_image;
	cvtColor(img, output_image, CV_BGR2GRAY);
	imshow("out put windows", output_image);
	Mat csrc;
	Mat kernel = (Mat_<float>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
	filter2D(img, csrc, -1, kernel);
	imshow("outpu", csrc);
	waitKey(0);
	return 0;

	
}