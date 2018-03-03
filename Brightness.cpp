#include<opencv2\core\core.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<opencv2\imgproc\imgproc.hpp>
#include<iostream>
#include<math.h>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {

	Mat img = imread("C:\\Users\\Harsha527\\Desktop\\IPVP\\Image1.jpg");
	if (img.empty()) {
		cout << "Cannot open image" << endl;
		return -1;
	}

	String WinName = "Brightness";
	String Image = "Image";
	
	namedWindow(WinName);
	namedWindow(Image);

	Mat Bimg(img.rows, img.cols, CV_8UC3);

	int bright;
	cout << "Enter a Brightness Level" << endl;
	cin >> bright;

	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {
			int B = img.at<Vec3b>(i, j)[0] + bright;
			int G = img.at<Vec3b>(i, j)[1] + bright;
			int R = img.at<Vec3b>(i, j)[2] + bright;
			
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

			Bimg.at<Vec3b>(i, j)[0] = B;
			Bimg.at<Vec3b>(i, j)[1] = G;
			Bimg.at<Vec3b>(i, j)[2] = R;
		}
	}

	imshow(Image, img);
	imshow(WinName, Bimg);
	waitKey(0);
	destroyAllWindows();
}
