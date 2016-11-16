/**
 * Tests various functionality necessary for finding and tracking retroreflective tape blobs.
 *
 * @author Ryan Tse
 */

#include <opencv2/opencv.hpp>
#include <hsvfilter.h>
#include "../include/main.h"

using namespace cv;

/**
 * Test this library's functionality
 * @param argc number of command line arguments
 * @param argv command line arguments
 * @return exit status
 */
int main(int argc, char *argv[]) {
//    capThreshBin(0, 200);
//    rectDetect(0);
	testFilterHsv();
}
