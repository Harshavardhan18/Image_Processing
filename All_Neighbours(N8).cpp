#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\core\core.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
	Mat img = imread("C:\\Users\\Harsha527\\Desktop\\IPVP\\Image1.jpg");

	if (img.empty()) {
		cout << "Could not find the image" << endl;
		return -1;
	}

	String WinName = "8 Adjacency";
	String Name = "Image";
	namedWindow(Name);
	namedWindow(WinName);
	imshow(Name, img);

	Mat N8img(img.rows, img.cols, CV_8UC1);

	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {
			N8img.at<uchar>(i, j) = (img.at<Vec3b>(i, j)[0] + img.at<Vec3b>(i, j)[1] + img.at<Vec3b>(i, j)[2]) / 3;
		}
	}

	imshow("Black and White", N8img);

	for (int i = 1; i < img.rows - 1; i++) {
		for (int j = 1; j < img.cols - 1; j++) {
			N8img.at<uchar>(i, j) = (N8img.at<uchar>(i - 1, j) + N8img.at<uchar>(i + 1, j) + N8img.at<uchar>(i, j - 1) + N8img.at<uchar>(i, j + 1) + N8img.at<uchar>(i - 1, j + 1) + N8img.at<uchar>(i + 1, j - 1) + N8img.at<uchar>(i - 1, j - 1) + N8img.at<uchar>(i + 1, j + 1)) / 8;
		}
	}
	imshow(WinName, N8img);
	waitKey(0);
	destroyAllWindows();
}