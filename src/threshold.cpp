/**
 * Thresholding operations on the video capture.
 *
 * @author Ryan Tse
 */

#include <opencv2/opencv.hpp>
#include <stdio.h>

using namespace cv;

/**
 * Opens a video capture and thresholds the resulting image before displaying it in a new window
 *
 * @param capIndex hardware index of the video capture device (0-8)
 * @param thresh threshold value (0-255)
 */
void capThreshBin(int capIndex, int thresh) {
    VideoCapture cap(capIndex);

    if(!cap.isOpened()) {
        printf("VideoCapture failed");
    }

    namedWindow("m", 1);

    for(;;) {
        Mat frame;
        cap >> frame;

        cvtColor(frame, frame, CV_RGB2GRAY);
        threshold(frame, frame, thresh, 255, THRESH_BINARY);

        imshow("m", frame);
        if (waitKey(30) >= 0) {
            break;
        }
    }
}
