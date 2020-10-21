#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
int main()
{
	cv::Mat srcMat = imread("D:/1.jpg", 0);
	cv::Mat resultzishiying;
	cv::Mat eroMat;
	cv::Mat dilMat;
	cv::Mat moroaMat;
	cv::Mat morobMat;
	Mat kernel=getStructuringElement(MORPH_RECT,Size (3,3));
	adaptiveThreshold(srcMat, resultzishiying, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 13, 10);// THRESH_BINARY_INV
	erode(resultzishiying,eroMat, kernel);
	dilate(resultzishiying, dilMat, kernel);
	morphologyEx(resultzishiying, moroaMat,2, kernel);
	morphologyEx(resultzishiying, morobMat, 3, kernel);
	imshow("src", resultzishiying);
	imshow("∏Ø ¥", eroMat);
	imshow("≈Ú’Õ", dilMat);
	imshow("ø™", moroaMat);
	imshow("πÿ", morobMat);
	waitKey(0);
	return 0;
}