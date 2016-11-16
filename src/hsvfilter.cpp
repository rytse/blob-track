//
// Created by blairrobot on 11/14/16.
//

#include <opencv2/opencv.hpp>
#include <cstdio>
#include "hsvfilter.h"

using namespace cv;

Scalar lower(60,245,140);
Scalar upper(75,255,190);

void filterHsv(Mat &in, Mat &out) {
	Mat hsv, mask;
	cvtColor(in, hsv, COLOR_BGR2HSV);
	printf("H: %d S: %d V: %d\n", hsv.at<Vec3b>(0,0).val[0],
	       hsv.at<Vec3b>(0,0).val[1],hsv.at<Vec3b>(0,0).val[2]);
	inRange(hsv, lower, upper, mask);
	bitwise_and(in, in, out, mask);
}

void testFilterHsv() {
	Mat raw;
	VideoCapture cap = VideoCapture(0);
	cap.set(10, 0.05);

	while (true) {
		Mat filtered;
		cap.read(raw);

		filterHsv(raw, filtered);

		imshow("original", raw);
		imshow("filtered", filtered);

		if (waitKey(30) >= 0) {
			break;
		}
	}
}
