#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
int main()
{
	VideoCapture cap;
	cap.open(0);
	cv::Mat bgMat;
	cv::Mat subMat;
	cv::Mat bny_subMat;
	int cnt = 0;
	if (!cap.isOpened())
	{
		std::cout << "不能打开视频文件" << std::endl;
		return-1;
	}
	double fps = cap.get(CAP_PROP_FPS);
	std::cout << "fps" << fps << std::endl;
	while (1) {
		cv::Mat frame;
		bool rSucess = cap.read(frame);
		//capVideo >> frame;
		cvtColor(frame, frame, COLOR_BGR2GRAY);

		if (cnt == 0) {
			frame.copyTo(bgMat);
		}
		else {
			absdiff(frame, bgMat, subMat);
			threshold(subMat, bny_subMat, 50, 255, CV_THRESH_BINARY);

			imshow("bny_subMat", bny_subMat);
			imshow("subMat", subMat);
			imshow("frame", frame);
			waitKey(30);
		}
		cnt++;
	}

}