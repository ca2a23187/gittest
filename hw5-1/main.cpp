#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main()
{
	VideoCapture cap;
	cap.open(0);
	if (!cap.isOpened())
	{
		std::cout << "不能打开视频文件" << std::endl;
		return-1;
	}
	double fps = cap.get(CAP_PROP_FPS);
	std::cout << "fps" << fps << std::endl;
	while (1)
	{
		cv::Mat frame;
		cv::Mat frame51;
		cv::Mat frame52;
		cv::Mat frame53;
		cv::Mat frame541;
		cv::Mat frame542;
		
		bool rSucess = cap.read(frame);
		medianBlur(frame, frame51, 15);
		blur(frame, frame52, Size(15,15));
		GaussianBlur(frame, frame53, Size(15, 15),3,0);
		Sobel(frame, frame541,CV_16SC1,1,0,7 );
		Sobel(frame, frame542, CV_16SC1, 0, 1, 7);
		
		if (!rSucess)
		{
			std::cout << "不能从视频文件中读取帧" << std::endl;
			break;
		}
		else
		{
			cv::imshow("第四题y", frame542);
			cv::imshow("第四题x", frame541);
			cv::imshow("第三题", frame53);
			cv::imshow("第二题", frame52);
			cv::imshow("第一题", frame51);
			cv::imshow("原图", frame);
		}
		waitKey(30);
	}
}
