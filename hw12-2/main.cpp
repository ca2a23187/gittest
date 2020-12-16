#include <opencv2/opencv.hpp>
#include <iostream>
#include"math.h"
#define flags 10//100帧
using namespace cv;
using namespace std;
int main()
{
	VideoCapture cap;
	cap.open(0);
	cv::Mat averageMat;//保存平均数
	cv::Mat sigmaMat;//保存标准差
	cv::Mat framebin[flags];
	cv::Mat dstMat;
	cv::Mat frame;
	cv::Mat framecopy;
	int cal = 0;//保存单个像素的平均值
	double sigma = 0;//保存单个像素的标准差
	double th = 2.2;
	int cnt = 0;
	int temp;
	int temp1;
	int jingwei = 0;
	if (!cap.isOpened())
	{
		std::cout << "不能打开视频文件" << std::endl;
		return-1;
	}
	double fps = cap.get(CAP_PROP_FPS);
	std::cout << "fps" << fps << std::endl;
	cap.read(frame);
	int height = frame.rows;
	int width = frame.cols;
	cvtColor(frame, frame, COLOR_BGR2GRAY);
	dstMat = frame;
	threshold(dstMat, frame, 50, 255, CV_THRESH_BINARY);
	while (1) {
		cap.read(frame);
		framecopy = frame;
		//capVideo >> frame;
		cvtColor(frame, frame, COLOR_BGR2GRAY);
		if (cnt >= flags) {
			jingwei = 1;
			cnt = 0;
			
		}
		else
			cnt++;
		if (cnt != flags) {
			framebin[cnt] = frame;
			//threshold(framebin[cnt], frame, 50, 255, CV_THRESH_BINARY);
		}
		averageMat = frame;
		sigmaMat = frame;
		if (jingwei == 1) {
			for (int i = 0; i < width; i++) {
				for (int j = 0; j < height; j++) {
					//************求平均数保存在tempMat**********//
					temp = 0;//先清0
					cal = 0;
					for (int t = 0; t < flags; t++) {
						temp += framebin[t].at<uchar>(j, i);//累加
					}
					temp = temp / flags;
					cal = temp;//平均值转化为int型暂存
					//averageMat.at<uchar>(j, i) = cal;//平均值
					//****************计算标准差***************************//
					sigma = 0;//清0
					for (int t = 0; t < flags; t++) {
						temp = framebin[t].at<uchar>(j, i) - cal;//目标像素与平均差
						temp = temp*temp;//差平方
						sigma = sigma + temp;//累加得方差
					}
					sigma = sigma / flags;
					sigma = sqrt(sigma);//开方得标准差
					//sigmaMat.at<uchar>(j, i) = (int)sigma;//变成整形保存
					temp = frame.at<uchar>(j, i);
					temp1 = cal;
					temp = temp - cal;
					if (temp < 0)
						temp = -temp;
					if (temp >(th * sigma))
						dstMat.at<uchar>(j, i) = 255;
					else
						dstMat.at<uchar>(j, i) = 0;
				}
			}

			//cout << dstMat << endl;
		}
		imshow("frame", framecopy);
		imshow("dst", dstMat);
		
		waitKey(30);

	}
}