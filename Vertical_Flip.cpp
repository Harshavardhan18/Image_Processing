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
	String WinName = "Vertical Flip";
	String Image = "Image";
	//Window Title
	namedWindow(Image);
	namedWindow(WinName);
	//Display Window
	imshow(Image, img);
	
	//Color Image to Grey Scale Image 
	Mat Vimg(img.rows, img.cols, CV_8UC1);

	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j <img.cols; j++) {
			Vimg.at<uchar>(i, j) = (img.at<Vec3b>(img.rows - i, j)[0] + img.at<Vec3b>(img.rows - i, j)[1] + img.at<Vec3b>(img.rows - i, j)[2]) / 3;
		}
	}

	/*For color image
	Mat Vimg(img.rows, img.cols, CV_8UC3);

	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {
			Vimg.at<Vec3b>(i, j) = img.at<Vec3b>(img.rows - i, j);
		}
	}*/

	imshow(WinName, Vimg);
	waitKey(0);
	destroyAllWindows();
	return 0;
}