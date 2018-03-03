#include<opencv2\core\core.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<opencv2\imgproc\imgproc.hpp>
#include<iostream>
#include<math.h>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {

	Mat img = imread("C:\\Users\\Desktop\\IPVP\\Image1.jpg"); //Path of Image
	if (img.empty()) {
		cout << "Cannot open image" << endl;
		return -1;
	}

	String WinName = "Contrast";
	String Image = "Image";

	namedWindow(WinName);
	namedWindow(Image);

	Mat Cimg(img.rows, img.cols, CV_8UC3);

	double contrast;
	cout << "Enter a Brightness Level" << endl;
	cin >> contrast;
	if (contrast <= 0)
		contrast = 0.1;
	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {
			int B = round(img.at<Vec3b>(i, j)[0] * contrast);
			int G = round(img.at<Vec3b>(i, j)[1] * contrast);
			int R = round(img.at<Vec3b>(i, j)[2] * contrast);

			if (R >= 255)
				R = 255;
			else if (R <= 0)
				R = 0;
			if (G >= 255)
				G = 255;
			else if (G <= 0)
				G = 0;
			if (B >= 255)
				B = 255;
			else if (B <= 0)
				B = 0;

			Cimg.at<Vec3b>(i, j)[0] = B;
			Cimg.at<Vec3b>(i, j)[1] = G;
			Cimg.at<Vec3b>(i, j)[2] = R;
		}
	}
	imshow(Image, img);
	imshow(WinName, Cimg);
	waitKey(0);
	destroyAllWindows();
}
