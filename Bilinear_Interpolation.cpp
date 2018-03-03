#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\core\core.hpp>
#include <iostream>>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
	Mat img = imread("C:\\Users\\Harsha527\\Desktop\\IPVP\\Image1.jpg");
	
	if (img.empty()) {
		cout << "Could not find the image" << endl;
		return -1;
	}

	String WinName = "Bi-linear Interpolation";
	String Name = "Image";
	namedWindow(Name);
	namedWindow(WinName);
	imshow(Name, img);

	Mat Bimg(img.rows*2 ,img.cols*2 ,CV_8UC3);
	/*
		//For Grey Scale Image
		Mat Bimg(img.rows*2 ,img.cols*2 ,CV_8UC1);
		for (int i = 0; i < img.rows; i++) {
			for (int j = 0; j < img.cols; j++) {
				img.at<uchar>(i, j) = (img.at<Vec3b>(i, j)[0] + img.at<Vec3b>(i, j)[1] + img.at<Vec3b>(i, j)[2]) / 3;
			}
		}
		// CHANGE <Vec3b> to <uchar>
	*/
	

	for (int i = 0,m = 0; i < img.rows && m < img.rows*2; i++, m = m+2) {
		for (int j = 0, n = 0; j < img.cols && n < img.cols * 2; j++, n = n + 2) {
			Bimg.at<Vec3b>(m, n) = img.at<Vec3b>(i, j);
		}
	}

	for (int i = 0; i < Bimg.rows-1; i = i+2) {
		for (int j = 0; j < Bimg.cols-1; j = j+2) {
			Bimg.at<Vec3b>(i, j + 1)     = (Bimg.at<Vec3b>(i, j) + Bimg.at<Vec3b>(i, j + 2)) / 2;
			Bimg.at<Vec3b>(i + 2, j + 1) = (Bimg.at<Vec3b>(i + 2, j) + Bimg.at<Vec3b>(i + 2, j + 2)) / 2;
			Bimg.at<Vec3b>(i + 1, j)     = (Bimg.at<Vec3b>(i, j) + Bimg.at<Vec3b>(i + 2, j)) / 2;
			Bimg.at<Vec3b>(i + 1, j + 2) = (Bimg.at<Vec3b>(i, j + 2) + Bimg.at<Vec3b>(i + 2, j + 2)) / 2;
			Bimg.at<Vec3b>(i + 1, j + 1) = (Bimg.at<Vec3b>(i, j + 1) + Bimg.at<Vec3b>(i + 2, j + 1)) / 2;
		}
	}

	imshow(WinName, Bimg);
	waitKey(0);
	destroyAllWindows();
	return 0;
}