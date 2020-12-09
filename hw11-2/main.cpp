#include <opencv.hpp>
#include <cmath>
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;
using namespace std;
int main()
{
	cv::Mat srcMat = imread("../testimage\\1.jpg");
	Mat srcMat_B, srcMat_G, srcMat_R;
	cv::Mat dstMat=imread("../testimage\\1.jpg");
	cv::Mat newImage;
	//Mat image_H, image_S, image_V;          //H��S��V����ͨ��
	Mat channels_BGR[3];     //vector<Mat>�� �������Ϊ���Mat���͵����������飩
	std::vector<cv::Mat> channels;
	split(srcMat, channels_BGR);
	//0ͨ��ΪB������1ͨ��ΪG������2ͨ��ΪR��������Ϊ��RGBɫ�ʿռ���opencv��Ĭ��ͨ��˳��ΪBGR������
	srcMat_B = channels_BGR[0];
	srcMat_G = channels_BGR[1];
	srcMat_R = channels_BGR[2];

	cv::split(dstMat, channels);
	equalizeHist(srcMat_B, channels.at(0));
	equalizeHist(srcMat_G, channels.at(1));
	equalizeHist(srcMat_R, channels.at(2));
	merge(channels, newImage);
	imshow("��H��S��Vͨ���ϲ����ͼ��", newImage);

	/*cv::Mat src_color = imread("D:/1.jpg");
	std::vector<cv::Mat> channels;
	cv::split(src_color, channels);
	cv::Mat B = channels.at(0);
	cv::Mat G = channels.at(1);
	cv::Mat R = channels.at(2);
	cv::imshow("red", R);
	cv::imshow("blue", B);
	cv::imshow("green", G);*/
	waitKey(0);
	return 0;
}