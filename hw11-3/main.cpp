#include <opencv.hpp>
#include <cmath>
#include "function.h"
using namespace cv;
using namespace std;
int main()
{
	cv::Mat srcMat = imread("../testimage\\图片1.jpg");
	cv::Mat dstMat = imread("../testimage\\图片1.jpg");
	cv::Mat dstMat1;
	float garma = 0.45;
	garmachange(srcMat, dstMat, garma);
	equal(dstMat,dstMat1);
	imshow("src", srcMat);
	imshow("伽马变换后", dstMat);
	imshow("直方图均衡后", dstMat1);
	waitKey(0);
	return 0;
}