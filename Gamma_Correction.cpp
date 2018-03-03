#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\core\core.hpp>
#include <iostream>
#include <math.h>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
	Mat img = imread("C:\\Users\\Desktop\\IPVP\\Image1.jpg"); //Path of Image
	
	if (img.empty()) {
		cout << "Could not find the image" << endl;
		return -1;
	}

	String WinName = "Gamma Correction";
	String Name = "Image";
	namedWindow(Name);
	namedWindow(WinName);
	imshow(Name, img);

	Mat Gimg(img.rows, img.cols, CV_8UC1);

	int Const,val;
	float gamma;
	cout << "Enter the Constant Value" << endl;
	cin >> Const;
	cout << "Enter the Gamma Correction Value" << endl;
	cin >> gamma;

	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {
			Gimg.at<uchar>(i, j) = (img.at<Vec3b>(i, j)[0] + img.at<Vec3b>(i, j)[1] + img.at<Vec3b>(i, j)[2]) / 3;
			val =  Const * (round(pow(Gimg.at<uchar>(i, j), gamma)));
			if (val >= 255)
				val = 255;
			Gimg.at<uchar>(i, j) = val;
		}
	}

	imshow(WinName, Gimg);
	waitKey(0);
	destroyAllWindows();
}
