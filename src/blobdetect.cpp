//
// Created by blairrobot on 10/27/16.
//

#include <opencv2/opencv.hpp>
#include <hsvfilter.h>
#include "blobdetect.h"

using namespace cv;

void rectDetect(int capIndex) {
	SimpleBlobDetector detector;
	VideoCapture cap(capIndex);
	std::vector<KeyPoint> keypoints;
	Mat frame, fwk;

	cap >> frame;
	filterHsv(frame, frame);
	detector = getDetector((int) frame.total());

	while (true) {
		Mat filtered;
	    cap >> frame;
		filterHsv(frame, filtered);
	    
	    detector.detect(filtered, keypoints);
	    drawKeypoints(filtered, keypoints, fwk, Scalar(0, 0, 255), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
        line(fwk, Point(frame.cols/2, 0), Point(frame.cols/2, frame.rows), Scalar(0, 255,0));
        line(fwk, Point(0, frame.rows/2), Point(frame.cols, frame.rows/2), Scalar(0, 255,0));
        circle(fwk, Point(frame.cols/2, frame.rows/2), 50, Scalar(0,255,0));
		imshow("original", frame);
		imshow("filtered", filtered);
	    imshow("annotated", fwk);

	    if (waitKey(30) >= 0) {
	        break;
	    }
	}
}

SimpleBlobDetector getDetector(int nPixels) {
	SimpleBlobDetector::Params params;

	// Threshold
	params.filterByColor = true;
//	params.minThreshold = 200;
//	params.maxThreshold = 256 * 3;
	params.minThreshold = 0;
	params.maxThreshold = 100;


	// Area
	params.filterByArea = true;
	params.maxArea = nPixels;
	//params.minArea = .08 * nPixels;

	// Circularity
//	params.filterByCircularity = true;
//	double estimateCirc = 7;
//	params.minCircularity = estimateCirc * 0.8;
//	params.maxCircularity = estimateCirc * 1.2;
	params.minCircularity = 0.1;
	params.maxCircularity = 0.9;


#if CV_MAJOR_VERSION < 3
	SimpleBlobDetector detector(params);
#else
	Ptr<SimpleBlobDetector> detector = SimpleBlobDetector::create(params);
#endif

	return detector;
}
