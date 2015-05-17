/*#include "cv.h"      // include it to used Main OpenCV functions.
#include "highgui.h" //include it to use GUI functions.

int main(int argc, char** argv)
{
	IplImage* img = cvLoadImage("desert.jpg"); //change the name (image.jpg) according to your Image filename.
	cvNamedWindow("Example1", CV_WINDOW_AUTOSIZE);
	cvShowImage("Example1",img);
	cvWaitKey(0);
	cvReleaseImage(&img);
	cvDestroyWindow("Example1");
	return 0;
}
*/

#include<iostream>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;
int imgcol=0;
int imgrow=0;
int* w;
Mat grayscale;
int i, j;
int pix;

void filterdesign()
{
	w = (int*)malloc(9 * sizeof(int));
	for (int k = 0; k < 3; k++)
	{
		for (int l = 0; l < 3; l++)
		{
			w[l * 3 + k] = 1;
		}
	}
}


int filter(int x, int y)
{ 
	filterdesign();
	int sum = 0;
	for (int s = -1; s < 2; s++)
	{
		for (int t = -1; t < 2; t++)
		{
//			sum = sum + w[(t + 1) * 3 + (s + 1)] * grayscale.at<uchar>((x+s),(y+t));
			sum = sum + grayscale.at<uchar>((x + s), (y + t));

		}
	}
	sum = sum / 9;
	return sum;
}

int main()
{
	
	
	namedWindow("window1", CV_WINDOW_AUTOSIZE);
	namedWindow("window2",CV_WINDOW_AUTOSIZE);
	namedWindow("window3", CV_WINDOW_AUTOSIZE);
	//Mat img = cvLoadImage("desert.jpg");
	Mat img = imread("Desert.jpg", CV_LOAD_IMAGE_ANYCOLOR|CV_LOAD_IMAGE_ANYDEPTH);
	
	imshow("window1", img);
	cvtColor(img, grayscale, CV_BGR2GRAY);
	imshow("window2",grayscale);
	imgcol = grayscale.cols;
	imgrow = grayscale.rows;
	cout << imgcol<< "x" << imgrow;
	for (i = 1; i < imgrow; i++)
	{
		for (j = 1; j < imgcol; j++)
		{
			//pix = grayscale.at<uchar>(i, j);
				//pix=filter(i,j);
				grayscale.at<uchar>(i, j) = filter(i,j);
		}
	}

	imshow("window3", grayscale);

	waitKey(0);
	destroyWindow("Window1");
	destroyWindow("Window2");
	destroyWindow("window3");
	return 0;

}
