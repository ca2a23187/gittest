#include "function.h"
#include <opencv.hpp>
#include <cmath>
using namespace cv;
using namespace std;
double x;
double y;
int t;
void garmachange(Mat srcMat, Mat& dstMat, float garma)
{
	int height = srcMat.rows;
	int width = srcMat.cols;
	for (int j = 0; j < height; j++) {
		for (int i = 0; i < width; i++) {
			x = srcMat.at<Vec3b>(j, i)[0] / 255.0;
			y = pow(x, garma);
			y = y * 255;
			t = (int)y;
			dstMat.at<Vec3b>(j, i)[0] = t;
			x = srcMat.at<Vec3b>(j, i)[1] / 255.0;
			y = pow(x, garma);
			y = y * 255;
			t = (int)y;
			dstMat.at<Vec3b>(j, i)[1] = t;
			x = srcMat.at<Vec3b>(j, i)[2] / 255.0;
			y = pow(x, garma);
			y = y * 255;
			t = (int)y;
			dstMat.at<Vec3b>(j, i)[2] = t;
		}
	}
	
}
void equal(Mat srcMat,Mat &newImage)
{
	Mat channels_BGR[3];     
	Mat srcMat_B, srcMat_G, srcMat_R;
	Mat dstMat;
	dstMat = srcMat;
	std::vector<cv::Mat> channels;
	split(srcMat, channels_BGR);
	//0通道为B分量，1通道为G分量，2通道为R分量。因为：RGB色彩空间在opencv中默认通道顺序为BGR！！！
	srcMat_B = channels_BGR[0];
	srcMat_G = channels_BGR[1];
	srcMat_R = channels_BGR[2];

	cv::split(dstMat, channels);
	equalizeHist(srcMat_B, channels.at(0));
	equalizeHist(srcMat_G, channels.at(1));
	equalizeHist(srcMat_R, channels.at(2));
	merge(channels, newImage);
}