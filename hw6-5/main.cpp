#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main()
{
	cv::Mat srcMat = imread("D:/5.jpg");
	cv::Mat dstMat;
	int height = srcMat.rows;
	int width = srcMat.cols;
	int pointrightuop;
	int pointleftdown;
	int pointrightup;
	for (int i = 0; i < width; i++)
		if (srcMat.at<Vec3b>(0, i)[0] < 230)
		{
			pointrightup = i;
			break;
		}
	for (int i = 0; i < height; i++)
		if (srcMat.at<Vec3b>(i, 0)[0] < 230)
		{
			pointleftdown = i;
			break;
		}
	for (int i = 0; i < height; i++)
		if (srcMat.at<Vec3b>(i, width-1)[0] < 230)
		{
			pointrightup = i;
			break;
		}
	if (srcMat.empty()) return -1;
	const cv::Point2f src_pt[] = {
		cv::Point2f(pointrightup,0),
		cv::Point2f(0,pointleftdown),
		cv::Point2f(width-1,pointrightup) };
	const cv::Point2f dst_pt[] = {
		cv::Point2f(0,0),
		cv::Point2f(0,height-1),
		cv::Point2f(width-1,0) };
	const cv::Mat affine_matrix = cv::getAffineTransform(src_pt, dst_pt);
	cv::warpAffine(srcMat, dstMat, affine_matrix, srcMat.size());
	cv::imshow("src", srcMat);//等待用户按键
	cv::imshow("dst", dstMat);
	cv::waitKey(0);
	return 0;
}