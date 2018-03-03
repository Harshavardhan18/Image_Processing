#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\core\core.hpp>
#include<iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
	//Read Image
	Mat img = imread("C:\\Users\\Desktop\\IPVP\\Image1.jpg"); //Path of Image

	if (img.empty()) {
		cout << "counld not find the image" << endl;
		return -1;
	}

	String WinName = "Transpose";
	String Name = "Image";
	//Window Title
	namedWindow(WinName);
	namedWindow(Name);
	//Matrix for Grey Scale Image
	Mat Timg(img.cols,img.rows,CV_8UC1);

	//Transpose of Image
	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {
			/*int B = img.at<Vec3b>(i,j)[0];
			int G = img.at<Vec3b>(i,j)[1];
			int R = img.at<Vec3b>(i,j)[2];*/
			Timg.at<uchar>(j, i) = (img.at<Vec3b>(i, j)[0]+ img.at<Vec3b>(i, j)[1] + img.at<Vec3b>(i, j)[2])/3;
		}
	}

	/*//For color image
	Mat Timg(img.cols, img.rows, CV_8UC3);
	//Transpose 
	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {
			Timg.at<Vec3b>(j, i) = img.at<Vec3b>(i, j);
		}
	}*/

	//Display Image
	imshow(Name, img);
	imshow(WinName, Timg);
	waitKey(0);
	destroyAllWindows();
	return 0;
}
