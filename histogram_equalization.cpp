#include<opencv2\core\core.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<opencv2\imgproc\imgproc.hpp>
#include<iostream>
#include<math.h>
#include<iomanip>

#define size 256

using namespace cv;
using namespace std;

//Calculate Propability Distribution Function
void PDF(int histogram[], double pdf[], int img_size) {
	for (int i = 0; i < size; i++) {
		pdf[i] = (double)histogram[i] / img_size;
	}
}

//Calculate Cumulative Distribution Function
void CDF(double pdf[], double cdf[]) {
	cdf[0] = pdf[0];
	for (int i = 1; i < size; i++) {
		cdf[i] = pdf[i] + cdf[i - 1];
	}
}

//Scale the histogram
void Hv(double cdf[], int hv[], int img_size) {
	double alpha = (size - 1) ;
	for (int i = 0; i < size; i++) {
		hv[i] = round(alpha * cdf[i]);
	}
}

//Plot and Display Histogram
void Histogram(int h[],const char* title) {
	int hist[size];
	
	for (int i = 0; i < size; i++) {
		hist[i] = h[i];
	}
	
	int hist_w = 512, hist_h = 600;
	int space = round((double)hist_w / size);
	
	//Find Maximum Intensity
	int max = 0;
	for (int i = 0; i < size; i++) {
		if (hist[i] > max)
			max = hist[i];
	}
	
	Mat HistImg(hist_h, hist_w, CV_8UC1, Scalar(255, 255, 255));
	
	//Normalize the histogram between 0 and HistImg.rows
	for (int i = 0;i < size; i++) {
		hist[i] = ((double)hist[i] / max) * hist_h;
	}

	//Plot Histogram
	for (int i = 0; i < size; i++) {
		line(HistImg, Point(space * i, hist_h), Point(space * i, hist_h - hist[i]), Scalar(0, 0, 0), 1, 8, 0);
	}

	//Display Histogram
	namedWindow(title, CV_WINDOW_AUTOSIZE);
	imshow(title, HistImg);
}

int main(int argc, char** argv) {
	//Read Image
	Mat img = imread("C:\\Users\\Harsha527\\Desktop\\IPVP\\Image1.jpg");
	if (img.empty()) {
		cout << "Cannot open image" << endl;
		return -1;
	}

	String WinName = "Black and White";
	String Image = "Original Image";
	String WinImage = "Histogram Equalization";
	//Window Title
	namedWindow(WinName);
	namedWindow(Image);
	namedWindow(WinImage);
	//Display Image
	imshow(Image, img);

	int histogram[size], hv[size], hr[size], new_histogram[size];
	double pdf[size], cdf[size];
	//Initialize to 0
	for (int i = 0; i < size; i++) {
		histogram[i] = 0;
		pdf[i] = 0.0;
		cdf[i] = 0.0;
		hv[i] = 0.0;
		new_histogram[i] = 0;
		hr[i] = 0;
	}
	//Grey Scale of Colored Image
	Mat grey_img(img.rows, img.cols, CV_8UC1);
	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {
			grey_img.at<uchar>(i, j) = (img.at<Vec3b>(i, j)[0] + img.at<Vec3b>(i, j)[1] + img.at<Vec3b>(i, j)[2]) / 3;
			// calculate the no of pixels for each intensity values
			histogram[(int)grey_img.at<uchar>(i, j)]++;
		}
	}

	//Plot and Display Histogram
	Histogram(histogram, "Original Histogram");
	imshow(WinName, grey_img);

	int img_size = img.rows * img.cols;

	//Calculate Parameters for Histogram Equalization
	PDF(histogram, pdf, img_size);
	CDF(pdf, cdf);
	Hv(cdf, hv, img_size);

	cout << "level(k)" << "\t" << "nk" << "\t\t" << "PDF" << "\t\t" << "CDF" << "\t\t\t" << "T(k)" << endl;
	for (int i = 0; i < size; i++) {
		cout << i << "\t\t" << right << histogram[i] << right << "\t\t" << pdf[i] << "\t" << setw(10) << right << cdf[i] ;
		cout << right << "\t\t" << hv[i] << endl;
	}
	//Equalized Image
	Mat hist_equ(grey_img.rows, grey_img.cols, CV_8UC1);
	for (int i = 0; i < grey_img.rows; i++) {
		for (int j = 0; j < grey_img.cols; j++) {
			hist_equ.at<uchar>(i, j) = saturate_cast<uchar>(hv[grey_img.at<uchar>(i, j)]);
		}
	}

	imshow(WinImage, hist_equ);

	for (int i = 0; i < size; i++) {
		hr[hv[i]] += histogram[i];
	}

	for (int i = 0; i < size; i++) {
		new_histogram[i] = round(hr[i] * (size - 1));
	}

	//Plot and Display Histogram
	Histogram(new_histogram, "Equalized Histogram");

	waitKey(0);
	destroyAllWindows();
}