#include <opencv2/opencv.hpp>
#include <iostream>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
using namespace cv;
using namespace std;
float normL2(float * Hist1, float * Hist2, int size)
{
	float sum = 0;
	for (int i = 0; i < size; i++) {
		sum += (Hist1[i] - Hist2[i])*(Hist1[i] - Hist2[i]);
	}
	sum = sqrt(sum);
	return sum;
}
int calcHOG(Mat srcMat,float*ref_hist,int nAngle,int blockSize )
{
	int cellSize=16;
	int nX = srcMat.cols / blockSize;
	int nY = srcMat.cols / blockSize;
	int binAngle = 360 / nAngle;
	Mat gx, gy;
	Mat mag, angle;
	Rect roi;
	//cv::Point2i roi;
	Sobel(srcMat, gx, CV_32F, 1, 0, 1);
	Sobel(srcMat, gy, CV_32F, 0, 1, 1);
	cartToPolar(gx, gy, mag, angle, true);
	for (int i = 0; i < nX; i++) {
		for (int j = 0; j < nY; j++) {
			cv::Mat roiMat;
			cv::Mat roiMag;
			cv::Mat roiAgl;
			roi.x = j*cellSize;
			roi.y = i*cellSize;
			roiMat = srcMat(roi);
			roiMag = mag(roi);
			roiAgl = angle(roi);
			int head = (i*nX + j)*nAngle;
			for (int n = 0; n < roiMat.rows; i++) {
				for (int m = 0; m < roiMat.cols; j++) {
					int pos = (int)(roiAgl.at<float>(n, m) / binAngle);
					//以像素点的值为权重
					ref_hist[head + pos] += roiMag.at<float>(n, m);

				}
			}


		}
	}
	return 0;
}
int main()
{

	cv::Mat srcMat = imread("D:/91.jpg", 0);
	cv::Mat testMat1 = imread("D:/92.jpg", 0);
	cv::Mat testMat2 = imread("D:/93.jpg", 0);
	int cellSize = 16;
	int nAngle = 8;
	int nX = srcMat.cols / cellSize;
	int nY = srcMat.cols / cellSize;
	int bins = nX*nY*nAngle;
	float*ref_hist = new float[bins];
	memset(ref_hist, 0, sizeof(float)*bins);
	float*pl_hist = new float[bins];
	memset(pl_hist, 0, sizeof(float)*bins);
	float*bg_hist = new float[bins];
	memset(bg_hist, 0, sizeof(float)*bins);
	int reCode = 0;
	reCode = calcHOG(srcMat, ref_hist, nAngle, cellSize);
	reCode= calcHOG(testMat1, ref_hist, nAngle, cellSize);
	reCode = calcHOG(testMat2, ref_hist, nAngle, cellSize);
	if (reCode != 0) {
		return -1;
	}

	//计算直方图距离
	float dis1 = normL2(ref_hist, pl_hist, bins);
	float dis2 = normL2(ref_hist, bg_hist, bins);

	std::cout << "distance between reference and img1:" << dis1 << std::endl;
	std::cout << "distance between reference and img2:" << dis2 << std::endl;

	(dis1 <= dis2) ? (std::cout << "img1 is similar" << std::endl) : (std::cout << "img2 is similar" << std::endl);


	imshow("ref", srcMat);
	imshow("img1", testMat1);
	imshow("img2", testMat2);

	waitKey(0);

	delete[] ref_hist;
	delete[] pl_hist;
	delete[] bg_hist;
	destroyAllWindows();

	return 0;
}