#include "function.h"
#include <opencv.hpp>
#include <cmath>
using namespace cv;
using namespace std;
double x;
double y;
int t;
void garmachange(Mat srcMat, Mat& dstMat, float garma)
{
	int height = srcMat.rows;
	int width = srcMat.cols;
	for (int j = 0; j < height; j++) {
		for (int i = 0; i < width; i++) {
			x = srcMat.at<Vec3b>(j, i)[0] / 255.0;
			y = pow(x, garma);
			y = y * 255;
			t = (int)y;
			dstMat.at<Vec3b>(j, i)[0] = t;
			x = srcMat.at<Vec3b>(j, i)[1] / 255.0;
			y = pow(x, garma);
			y = y * 255;
			t = (int)y;
			dstMat.at<Vec3b>(j, i)[1] = t;
			x = srcMat.at<Vec3b>(j, i)[2] / 255.0;
			y = pow(x, garma);
			y = y * 255;
			t = (int)y;
			dstMat.at<Vec3b>(j, i)[2] = t;
		}
	}
	//cout << srcMat;
	
	// build look up table  
	/*unsigned char lut[256];
	for (int i = 0; i < 256; i++)
	{
		lut[i] = saturate_cast<uchar>(pow((float)(i / 255.0), fGamma) * 255.0f);
	}

	dst = src.clone();
	const int channels = dst.channels();
	switch (channels)
	{
	case 1:   //灰度图的情况
	{

		MatIterator_<uchar> it, end;
		for (it = dst.begin<uchar>(), end = dst.end<uchar>(); it != end; it++)
			//*it = pow((float)(((*it))/255.0), fGamma) * 255.0;  
			*it = lut[(*it)];

		break;
	}
	case 3:  //彩色图的情况
	{

		MatIterator_<Vec3b> it, end;
		for (it = dst.begin<Vec3b>(), end = dst.end<Vec3b>(); it != end; it++)
		{
			//(*it)[0] = pow((float)(((*it)[0])/255.0), fGamma) * 255.0;  
			//(*it)[1] = pow((float)(((*it)[1])/255.0), fGamma) * 255.0;  
			//(*it)[2] = pow((float)(((*it)[2])/255.0), fGamma) * 255.0;  
			(*it)[0] = lut[((*it)[0])];
			(*it)[1] = lut[((*it)[1])];
			(*it)[2] = lut[((*it)[2])];
		}

		break;

	}
	}*/
}