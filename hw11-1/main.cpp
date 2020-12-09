#include <opencv.hpp>
#include <cmath>
#include "function.h"
using namespace cv;
using namespace std;
int main()
{
	cv::Mat srcMat = imread("../testimage\\chap11_直方图增强.jpg");
	cv::Mat dstMat = imread("../testimage\\chap11_直方图增强.jpg");
	cv::Mat dstMat1 = imread("../testimage\\chap11_直方图增强.jpg");
	float garma = 0.5;
	float garma1 = 1.5;
	garmachange(srcMat, dstMat, garma);
	garmachange(srcMat, dstMat1, garma1);
	imshow("src", srcMat);
	imshow("dst", dstMat);
	imshow("dst1", dstMat1);
	waitKey(0);
	return 0;
}