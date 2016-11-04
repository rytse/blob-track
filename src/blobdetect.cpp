//
// Created by blairrobot on 10/27/16.
//

#include <opencv2/opencv.hpp>
#include "blobdetect.h"

using namespace cv;

void rectDetect(int capIndex) {
    SimpleBlobDetector detector;
    VideoCapture cap(capIndex);
    std::vector<KeyPoint> keypoints;
    Mat frame, fwk;

    namedWindow("m", 1);

    cap >> frame;
    detector = getDetector(frame.total());

    while (true) {
        cap >> frame;
        //cvtColor(frame, frame, CV_RGB2GRAY);
        detector.detect(frame, keypoints);
        drawKeypoints(frame, keypoints, fwk, Scalar(0, 0, 255), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);

        imshow("m", fwk);

        if (waitKey(30) >= 0) {
            break;
        }
    }
}

SimpleBlobDetector getDetector(int nPixels) {
    SimpleBlobDetector::Params params;

    // Threshold
    params.filterByColor = true;
//    params.minThreshold = 200;
//    params.maxThreshold = 256 * 3;
    params.minThreshold = 0;
    params.maxThreshold = 100;


    // Area
    params.filterByArea = true;
    params.maxArea = nPixels;
    //params.minArea = .08 * nPixels;

    // Circularity
//    params.filterByCircularity = true;
//    params.minCircularity = 0.1;

#if CV_MAJOR_VERSION < 3
    SimpleBlobDetector detector(params);
#else
    Ptr<SimpleBlobDetector> detector = SimpleBlobDetector::create(params);
#endif

    return detector;
}
