#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
/*CV_EXPORTS int createTrackbar(const String& trackbarname, const String&winname,
int*value, int const,
TrackbarCallback onChange = 0,
void*userdata = 0);*/
string window_name = "binaryMat";
void threshod_Mat(int th, void*data)
{
	Mat src = *(Mat*)(data);
	Mat dst;
	threshold(src, dst, th, 255, 0);
	imshow(window_name, dst);
}
int main()
{
	cv::Mat srcMat;
	cv::Mat gryMat;
	int lowTh = 30;
	int maxTh = 255;
	srcMat = imread("D:/1.jpg");
	if (!srcMat.data)
	{
		cout << "Í¼ÏñÔØÈëÊ§°Ü" << endl;
		return 0;
	}
	cvtColor(srcMat, gryMat, CV_BGR2GRAY);
	imshow(window_name, gryMat);
	createTrackbar("threshold",
		window_name,
		&lowTh,
		maxTh,
		threshod_Mat,
		&gryMat);
	waitKey(0);
	return 0;
}