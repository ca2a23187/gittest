#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main()
{
	cv::Mat srcMat = imread("D:/1.jpg");
	cv::Mat dstMat;
	if (srcMat.empty()) return -1;
	const cv::Point2f pts1[] = {
		cv::Point2f(150,150),
		cv::Point2f(150,300),
		cv::Point2f(350,300),
		cv::Point2f(350,150) };
	const cv::Point2f pts2[] = {
		cv::Point2f(200,150),
		cv::Point2f(200,300),
		cv::Point2f(340,270),
		cv::Point2f(340,180) };
	const cv::Mat perspective_matrix = cv::getPerspectiveTransform(pts1, pts2);
	cv::warpPerspective(srcMat, dstMat, perspective_matrix, srcMat.size());
	cv::imshow("src", srcMat);//等待用户按键
	cv::imshow("dst", dstMat);
	cv::waitKey(0);
	return 0;
}