#pragma once
#include <opencv.hpp>

using namespace cv;
using namespace std;

int removeFrequnce(int x, cv::Mat srcMat);
int dftDemo(cv::Mat srcMat);
int ifftDemo(cv::Mat src, int x, cv::Mat &dspMat);
int mouseROI(int x, cv::Mat srcMat);


void on_mouse(int EVENT, int x, int y, int flags, void* userdata);
int selectPolygon1(cv::Mat srcMat, cv::Mat &dstMat, int x);
int calcVisibalMag(cv::Mat srcMat, cv::Mat & dstMat);
int calcVisbalDft(cv::Mat srcMat, cv::Mat & magMat, cv::Mat & ph, double & normVal, cv::Mat src);
int calcDft2Image(cv::Mat magMat, cv::Mat ph, double normVal, cv::Mat &dstMat);


