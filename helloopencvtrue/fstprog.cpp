#include<iostream>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
using namespace std;
using namespace cv;
Mat image;
int main()
{
	Mat image;
	image =imread("desert.jpg");
	Vector <int> compression_params;
	compression_params.push_back(CV_IMWRITE_JPEG_QUALITY);
	compression_params.push_back(98);
	imwrite("display.jpg", image);
	imshow("display", image);
	waitKey(0);

	/*VideoCapture cap(0);
	while (1)
	{
	
Mat fps;
	fps = cap.get(CV_CAP_PROP_FPS);
	namedWindow("hello", CV_WINDOW_AUTOSIZE);

     
	
		// cap.set(CV_CAP_PROP_POS_MSEC, 300);
		Mat frame;
		cap.read(frame);
		imshow("hello", frame);
		if (waitKey(30) >= 0)
			break;
	}*/
	/*image = imread("desert.jpg");
	if (image.empty())
	{
		cout << "error";
		return -1;
	}

	namedWindow("desert", CV_WINDOW_AUTOSIZE);
	imshow("desert", image);
	waitKey(0);
	destroyWindow("desert");*/
	return 0;
}