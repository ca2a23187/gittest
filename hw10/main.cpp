// dip-class-demos.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <opencv.hpp>
#include "funtions.h"

using namespace cv;
using namespace std;

int main()
{
	cv::Mat src1 = imread("../testImages\\11.png", 0);
	cv::Mat src2 = imread("../testImages\\2.jpeg", 0);
	cv::Mat dst1;
	cv::Mat dst2;
	cv::Mat dst3;
	double a = 0.5;
	double b = 0.5;
	//开始计时
	double start = static_cast<double>(cvGetTickCount());

	//dftDemo();
	//mouseROI();
	ifftDemo(src1, 1, dst1);
	ifftDemo(src2, 0, dst2);
	addWeighted(dst1, a, dst2, b, 0.0, dst3);
	imshow("dst1", dst1);
	imshow("dst2", dst2);
	imshow("dst3", dst3);
	waitKey(0);
	//结束计时
	double time = ((double)cvGetTickCount() - start) / cvGetTickFrequency();
	//显示时间
	cout << "processing time:" << time / 1000 << "ms" << endl;

	//等待键盘响应，按任意键结束程序
	system("pause");
	return 0;
}

