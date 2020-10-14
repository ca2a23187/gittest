#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
int main()
{
	cv::Mat srcMat = imread("D:/1.jpg",0);
	cv::Mat resultdajin;
	cv::Mat resultzishiying;
	threshold(srcMat,resultdajin,100,255,THRESH_OTSU);
	adaptiveThreshold(srcMat, resultzishiying,255,ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV,13,10);// THRESH_BINARY_INV
	imshow("src", srcMat);
	imshow("¥ÛΩÚ", resultdajin);
	imshow("◊‘  ”¶", resultzishiying);
	waitKey(0);
	return 0;
}