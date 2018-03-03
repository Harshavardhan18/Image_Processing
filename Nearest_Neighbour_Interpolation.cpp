#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\core\core.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc,char** argv) {
	Mat img = imread("C:\\Users\\Harsha527\\Desktop\\IPVP\\Image1.jpg");

	if (img.empty()) {
		cout << "Could not open image" << endl;
		return -1;
	}

	String WinName = "Nearest Neighbor";
	String Image = "Image";
	namedWindow(WinName);
	namedWindow(Image);
	imshow(Image, img);

	/*
		//For Grey Scale Image
		Mat Nimg(img.rows*2 ,img.cols*2 ,CV_8UC1);
		for (int i = 0; i < img.rows; i++) {
			for (int j = 0; j < img.cols; j++) {
				img.at<uchar>(i, j) = (img.at<Vec3b>(i, j)[0] + img.at<Vec3b>(i, j)[1] + img.at<Vec3b>(i, j)[2]) / 3;
			}
		}
	// CHANGE <Vec3b> to <uchar>
	*/

	Mat Nimg(img.rows * 2, img.cols * 2,CV_8UC3);
	int m, n;
	for (int i = 0,m = 0; i < img.rows && m < img.rows*2; i++, m = m+2) {
		for (int j = 0, n = 0; j < img.cols && n < img.cols*2; j++, n = n+2) {
			Nimg.at<Vec3b>(m, n) = img.at<Vec3b>(i, j);
			Nimg.at<Vec3b>(m+1, n) = img.at<Vec3b>(i, j);
			Nimg.at<Vec3b>(m, n+1) = img.at<Vec3b>(i, j);
			Nimg.at<Vec3b>(m+1, n+1) = img.at<Vec3b>(i, j);
			
		}
	}
	imshow(WinName, Nimg);
	waitKey(0);
	destroyAllWindows();
	return 0;


}