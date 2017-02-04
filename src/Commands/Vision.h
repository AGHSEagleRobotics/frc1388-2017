/*
 * Vision.h
 *
 *  Created on: Jan 14, 2017
 *      Author: Joey
 */

#ifndef SRC_COMMANDS_VISION_H_
#define SRC_COMMANDS_VISION_H_
#include <string>
#include "WPILib.h"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <math.h>
using namespace std;
using namespace cv;

class Vision {

private:
	RotatedRect box1, box2;
	Mat threshold(Mat orig);
public:
	void analyzeImage(Mat image);
	Vision();
	virtual ~Vision();
	void SetupCamera();
};

#endif /* SRC_COMMANDS_VISION_H_ */
