#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main()
{
	cv::Mat srcMat = imread("D:/3.jpg", 0);
	cv::Mat resultzishiying;
	cv::Mat labels;
	cv::Mat states;
	cv::Mat centroids;
	cv::Mat eroMat;
	cv::Mat dilMat;
	Mat kernel = getStructuringElement(MORPH_RECT, Size(25, 25));
	Mat kernel2 = getStructuringElement(MORPH_RECT, Size(25, 25));
	int shuliang = 0;
	threshold(srcMat, resultzishiying, 100, 255, THRESH_OTSU);
	dilate(resultzishiying, eroMat, kernel);
	erode(eroMat, dilMat, kernel2);
	adaptiveThreshold(dilMat, resultzishiying, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV, 13, 10);// THRESH_BINARY_INV
	shuliang = connectedComponentsWithStats(resultzishiying, labels, states, centroids);
	//shuliang -= shuliang;
	cout << shuliang;
	imshow("×ÔÊÊÓ¦", resultzishiying);
	waitKey(0);
	return 0;
}