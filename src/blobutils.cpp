#include <math.h>

double getRectCircularity(double length) {
	return 2 * M_PI * length / ((length + 2) * (length + 2));
}
