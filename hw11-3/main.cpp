#include <opencv.hpp>
#include <cmath>
#include "function.h"
using namespace cv;
using namespace std;
int main()
{
	cv::Mat srcMat = imread("../testimage\\ͼƬ1.jpg");
	cv::Mat dstMat = imread("../testimage\\ͼƬ1.jpg");
	cv::Mat dstMat1;
	float garma = 0.45;
	garmachange(srcMat, dstMat, garma);
	equal(dstMat,dstMat1);
	imshow("src", srcMat);
	imshow("٤��任��", dstMat);
	imshow("ֱ��ͼ�����", dstMat1);
	waitKey(0);
	return 0;
}