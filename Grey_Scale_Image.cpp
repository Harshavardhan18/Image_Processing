#include<opencv2\core\core.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<opencv2\imgproc\imgproc.hpp>

using namespace cv;

int main()
{
	//Read Image
	Mat image = imread("C:\\Users\\Harsha527\\Desktop\\IPVP\\Image1.jpg");
	//Display Image
	imshow("Image", image);
	//Matrix for Gray Scale Image
	Mat grey_image(image.rows, image.cols, CV_8UC1);

	for (int i = 0;i < image.rows;i++)
	{
		for (int j = 0;j < image.cols;j++)
		{
			int B = image.at<Vec3b>(i, j)[0];
			int G = image.at<Vec3b>(i, j)[1];
			int R = image.at<Vec3b>(i, j)[2];

			grey_image.at<uchar>(i, j) = (B + G + R) / 3;
		}
	}
	
	imshow("Grey Scale Image", grey_image);
	waitKey(0);
	return 1;
}