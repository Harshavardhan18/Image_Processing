#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\core\core.hpp>
#include <iostream>>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
	Mat img = imread("C:\\Users\\Desktop\\IPVP\\Image1.jpg"); //Path of Image
	if (img.empty()) {
		cout << "Could not find the image" << endl;
		return -1;
	}

	String WinName = "Shrink";
	String Name = "Image";
	namedWindow(Name);
	namedWindow(WinName);
	imshow(Name, img);

	/*
	//For Grey Scale Image
		Mat Aimg(img.rows/2 ,img.cols/2 ,CV_8UC1);
		for (int i = 0; i < img.rows; i++) {
			for (int j = 0; j < img.cols; j++) {
				img.at<uchar>(i, j) = (img.at<Vec3b>(i, j)[0] + img.at<Vec3b>(i, j)[1] + img.at<Vec3b>(i, j)[2]) / 3;
			}
		}
	// CHANGE <Vec3b> to <uchar>
	*/

	Mat Aimg(img.rows / 2, img.cols / 2, CV_8UC3);

	for (int i = 0, m = 0; i < img.rows - 1 && m < Aimg.rows; i = i + 2, m++) {
		for (int j = 0, n = 0; j < img.cols - 1 && n < Aimg.cols; j = j + 2, n++) {
			Aimg.at<Vec3b>(m, n) = ((img.at<Vec3b>(i, j) + img.at<Vec3b>(i, j + 1))/2
				+ (img.at<Vec3b>(i + 1, j) + img.at<Vec3b>(i + 1, j + 1))/2) / 2;
		}
	}
	imshow(WinName, Aimg);
	waitKey(0);
	destroyAllWindows();
	return 0;
}
