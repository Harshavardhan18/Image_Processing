#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\core\core.hpp>
#include <iostream>
#include<math.h>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
	Mat img = imread("C:\\Users\\Harsha527\\Desktop\\IPVP\\Image1.jpg");

	if (img.empty()) {
		cout << "Could not find the image" << endl;
		return -1;
	}

	String WinName = "Quantization Image";
	String Name = "Image";
	namedWindow(Name);
	namedWindow(WinName);

	int n;
	cout << "Enter the quantization level" << endl;
	cin >> n;
	int div = (int)pow(2, (8 - n));

	//Grey Scale Image
	Mat Cimg(img.rows, img.cols, CV_8UC1);
	
	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {
			Cimg.at<uchar>(i, j) = (img.at<Vec3b>(i, j)[0] + img.at<Vec3b>(i, j)[1] + img.at<Vec3b>(i, j)[2]) / 3;
			Cimg.at<uchar>(i, j) = Cimg.at<uchar>(i, j) / div;
		}
	}

	/*
	// Quantization of Colour Image
	Mat Cimg(img.rows, img.cols, CV_8UC3);
	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {
			int B = img.at<Vec3b>(i, j)[0];
			int G = img.at<Vec3b>(i, j)[1];
			int R = img.at<Vec3b>(i, j)[2];
			Cimg.at<Vec3b>(i, j)[0] = B / div;
			Cimg.at<Vec3b>(i, j)[1] = G / div;
			Cimg.at<Vec3b>(i, j)[2] = R / div;
		}
	}*/

	imshow(Name, img);
	imshow(WinName, Cimg);
	waitKey(0);
	destroyAllWindows();
	return 0;
}