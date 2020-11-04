#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main()
{
	cv::Mat srcMat = imread("D:/1.jpg");
	cv::Mat dstMat;
	if (srcMat.empty()) return -1;
	float angle = -10.0, scale = 1;
cv:Point2f center(srcMat.cols*0.5, srcMat.rows*0.5);
	const cv::Mat affine_matrix = cv::getRotationMatrix2D(center, angle, scale);
	cv::warpAffine(srcMat, dstMat, affine_matrix, srcMat.size());
	imshow("src", srcMat);//等待用户按键
	imshow("dst", dstMat);
	waitKey(0);
	return 0;
}