#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/utility.hpp>

using namespace std;
using namespace cv;

int main() {
	Mat logo = imread("logo.png", IMREAD_COLOR);
	vector<string> fn; // std::string in opencv2.4, but cv::String in 3.0
	string path = "Picture/*.jpg";
	glob(path, fn, true);
	cout << fn.size() << endl;
	int count_img = 0;
	for (size_t i = 0; i < fn.size(); i++) {
		Mat img = imread(fn[i], IMREAD_COLOR);
		if (img.empty())
			continue;
		Mat imgROI;
		String window_name = "Image " + to_string(count_img);
		imgROI = img(Rect(100, 100, logo.cols, logo.rows));
		addWeighted(imgROI, 0.5, logo, 0.5, 0, imgROI);
		cout << window_name <<" Completed!" << endl;
		namedWindow(window_name, WINDOW_AUTOSIZE);
		imshow(window_name, img);
		imwrite("AfterImg/"+window_name+".jpg", img);
		count_img++;
	}
	waitKey(0);
	system("pause");
	return 0;
}