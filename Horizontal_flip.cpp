#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\core\core.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	//Read Image
	Mat img = imread("C:\\Users\\Harsha527\\Desktop\\IPVP\\Image1.jpg");
	
	if (img.empty()) {
		cout << "Could not open the image" << endl;
		return -1;
	}
	String WinName = "Horizontal";
	String Image = "Image";
	//Window Title
	namedWindow(Image);
	namedWindow(WinName);
	//Display Image
	imshow(Image, img);
	//Matrix for Grey Scale Image
	Mat Himg(img.rows,img.cols,CV_8UC1);
	
	//Horizontal Flip
	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j <img.cols; j++) {
			Himg.at<uchar>(i, j) = (img.at<Vec3b>(i, img.cols-j)[0]+ img.at<Vec3b>(i, img.cols - j)[1]+ img.at<Vec3b>(i, img.cols - j)[2])/3;
		}
	}

	/*For color image
	Mat Himg(img.rows, img.cols, CV_8UC3);
	Horizontal Flip
	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {
			Himg.at<Vec3b>(i, j) = img.at<Vec3b>(i, img.cols - j);
		}
	}*/
	
	imshow(WinName, Himg);
	waitKey(0);
	destroyAllWindows();
	return 0;
}