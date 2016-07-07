//
// Created by 鲁蕴铖 on 16/7/7.
//

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

void solve(Mat &final_img) {
	int y,x;
	int x1, x2, y1, y2;
	float temp1, temp2;
	for(y = 0; y < final_img_height; y ++) {
		for(x = 0; x < final_img_width; x ++) {
			x1 = (x / Sx);
			x2 = x1 + 1;
			y1 = (y / Sy);
			y2 = y1 + 1;

			//边界
			if(y2 >= image_height || x2 >= image_width) {
				final_img.at<uchar>(y, x) = image.at<uchar>(y1, x1);
				continue;
			}

			temp1 = (x2 - x/Sx) * image.at<uchar>(y1, x1) + (x/Sx - x1) * image.at<uchar>(y1, x2);
			temp2 = (x2 - x/Sx) * image.at<uchar>(y2, x1) + (x/Sx - x1) * image.at<uchar>(y2, x2);
			final_img.at<uchar>(y,x) = (uchar)((y2 - y/Sy) * temp1 + (y/Sy - y1) * temp2);
		}
	}


	imshow("original", image);
	cout << "height:" << final_img.size().height << "  width:" << final_img.size().width << endl;
	imshow("new", final_img);

}

int main()
{
	Mat image = imread("car_1.jpg",0);
	if(!image.data) {
		cout << "image read error! please check!" << endl;
		return 0;
	}

	int image_height = image.size().height;
	int image_width = image.size().width;
	cout << "Image Info: height:" << image_height << "  width:" << image_width << endl;

//	cout << "cin the Sx and Sy:" << endl;
	double Sx, Sy;
	cin >> Sx >> Sy;
	cout << "Sx = " << Sx << "; Sy = " << Sy << ";" << endl;

	Mat final_img;
	int final_img_height, final_img_width;
	final_img_height = image.size().height * Sx;
	final_img_width  = image.size().width * Sy;
	final_img.create(final_img_height, final_img_width, CV_8UC1);
	solve(final_img);

	waitKey(0);

	return 0;
}
