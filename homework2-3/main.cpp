#include <opencv2/opencv.hpp>
#include <iostream>

#include <opencv2/core/core.hpp>

#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
int main()
{
	cv::Mat dispMat = imread("D:/1.jpg");
	cv::Mat dispMat2 = imread("D:/1.jpg");
	cv::Mat dispMat3 = imread("D:/1.jpg");
	cv::Point pt;
	cv::Point pt1;
	cv::Point pt2;
	pt.x = 100;
	pt.y = 100;
	pt1.x = 100;
	pt1.y = 100;
	pt2.x = 200;
	pt2.y = 200;
	circle(dispMat,pt,50,CV_RGB(255,0,0),1,8,0);
	line(dispMat2,pt1,pt2,CV_RGB(255, 0, 0), 1, 8, 0);
	cv::Rect rect;
	rect.x = 100;
	rect.y = 100;
	rect.width=100;
	rect.height=100;
	rectangle(dispMat3,rect, CV_RGB(255, 0, 0), -1, 8, 0);
	cv::imshow("dispMat", dispMat);
	cv::imshow("dispMat2", dispMat2);
	cv::imshow("dispMat3", dispMat3);
	waitKey(0);
	return 0;
}