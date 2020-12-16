#include <opencv2/opencv.hpp>
#include <iostream>
#include"math.h"
#define flags 10//100֡
using namespace cv;
using namespace std;
int main()
{
	VideoCapture cap;
	cap.open(0);
	cv::Mat averageMat;//����ƽ����
	cv::Mat sigmaMat;//�����׼��
	cv::Mat framebin[flags];
	cv::Mat dstMat;
	cv::Mat frame;
	cv::Mat framecopy;
	int cal = 0;//���浥�����ص�ƽ��ֵ
	double sigma = 0;//���浥�����صı�׼��
	double th = 2.2;
	int cnt = 0;
	int temp;
	int temp1;
	int jingwei = 0;
	if (!cap.isOpened())
	{
		std::cout << "���ܴ���Ƶ�ļ�" << std::endl;
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
					//************��ƽ����������tempMat**********//
					temp = 0;//����0
					cal = 0;
					for (int t = 0; t < flags; t++) {
						temp += framebin[t].at<uchar>(j, i);//�ۼ�
					}
					temp = temp / flags;
					cal = temp;//ƽ��ֵת��Ϊint���ݴ�
					//averageMat.at<uchar>(j, i) = cal;//ƽ��ֵ
					//****************�����׼��***************************//
					sigma = 0;//��0
					for (int t = 0; t < flags; t++) {
						temp = framebin[t].at<uchar>(j, i) - cal;//Ŀ��������ƽ����
						temp = temp*temp;//��ƽ��
						sigma = sigma + temp;//�ۼӵ÷���
					}
					sigma = sigma / flags;
					sigma = sqrt(sigma);//�����ñ�׼��
					//sigmaMat.at<uchar>(j, i) = (int)sigma;//������α���
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