#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

Mat image(512, 512, CV_8UC3, Scalar(255, 255, 255, 1));

int red = 0;
int green = 0;
int blue = 0;

string winName = "New Image";

void mouseCallback(int evt, int x, int y, int flags, void* userdata)
{
	

	if (evt == EVENT_MOUSEMOVE && flags == EVENT_FLAG_LBUTTON)
	{
		if (abs(x + y) < 0)
			return;

		// Change color on LMB click
		image.at<Vec3b>(y, x)[0] = blue;
		image.at<Vec3b>(y, x)[1] = green;
		image.at<Vec3b>(y, x)[2] = red;
	}
}

int main()
{
	// Window
	namedWindow(winName);

	createTrackbar("Red", winName, &red, 255);
	createTrackbar("Green", winName, &green, 255);
	createTrackbar("Blue", winName, &blue, 255);

	while(true)
	{
		setMouseCallback(winName, mouseCallback, NULL);
		imshow(winName, image);

		if (waitKey(10) == 27)
		{
			break;
		}
	}

	return 0;
}