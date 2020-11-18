#include <opencv2/opencv.hpp>
#include <iostream>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
using namespace cv;
using namespace std;
int main()
{
	cv::Mat srcMat = imread("D:/7.jpg", 0);
	cv::Mat src;
	cv::Mat src1;
	int i, j, t, k = 0, kk = 0, k1 = 0;
	cv::Mat dst = imread("D:/7.jpg");
	int height = dst.rows ;
	int width = dst.cols;
	int height1 = height / 4;
	int height2 = height / 4*3;
	int width1 = width/4;
	int width2 = width / 4*3;
	vector<vector<Point>>contours;
	threshold(srcMat, src, 100, 255, THRESH_BINARY_INV);
	/*****************腐蚀消除噪点*****************/
	/*Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));

	dilate(src, src1, kernel);
	erode(src1, src, kernel);*/
	Mat kernel1 = getStructuringElement(MORPH_CROSS, Size(7, 7));
	dilate(src, src1, kernel1);
	Mat kernel2 = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(src1, src, kernel2);
	erode(src, src1, kernel1);
	/********************提取轮廓**********************/


	findContours(src1, contours, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);

	for (i = 0; i < contours.size(); i++) {
		k = 0;

		for (j = 0; j < contours[i].size(); j++) {
			if (contours[i][j].x>width1&&contours[i][j].x<width2&&contours[i][j].y>height1&&contours[i][j].y < height2)//初步限定范围
				k++;
		}

		if (k > 150 && k < 500){//若总像素在符合中间方框的个数范围内
		/***************画外接四边形*************************/
		RotatedRect rbox = minAreaRect(contours[i]);
		drawContours(dst, contours, i, Scalar(0, 0, 255), 1, 8);
		cv::Point2f vtx[4];
		rbox.points(vtx);
		for (int i = 0; i < 4; i++) {
			cv::line(dst, vtx[i], vtx[i < 3 ? i + 1 : 0], cv::Scalar(0, 0, 255), 2, CV_AA);
		}
	}
	}
	imshow("src", src);
	imshow("src1", src1);
	imshow("draw", srcMat);
	imshow("dst", dst);
	waitKey(0);
}