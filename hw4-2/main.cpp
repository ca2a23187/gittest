#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main()
{
	cv::Mat srcMat = imread("D:/2.jpg", 0);
	cv::Mat resultzishiying;
	cv::Mat labels;
	cv::Mat states;
	cv::Mat centroids;
	cv::Rect rect;
	int shuliang=0;
	int i;
	int j;
	Mat k;
	threshold(srcMat, resultzishiying, 100, 255, THRESH_BINARY);
	shuliang = connectedComponentsWithStats(resultzishiying, labels, states, centroids);
	for (j = 1; j < shuliang;j++)
	//for (i = 0; i < 4; i++)
	{
		i = 0;
		rect.x = states.at<int>(j,i);
		//rect.x = k;
		i++;
		rect.y = states.at<int>(j,i);
		//rect.y = k;
		i++;
		rect.width = states.at<int>(j,i);
		// rect.width = k;
		 i++;
		 rect.height = states.at<int>(j,i);
		//rect.height = k;
		rectangle(resultzishiying, rect, CV_RGB(255, 255, 255), 1, 8, 0);
	}
	//shuliang -= shuliang;
	cout << shuliang;
	imshow("×ÔÊÊÓ¦", resultzishiying);
	waitKey(0);
	return 0;
}