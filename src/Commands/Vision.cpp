/*
 * Vision.cpp
 *
 *  Created on: Jan 14, 2017
 *      Author: Joey
 */

#include "Vision.h"
#include <string>
#include "WPILib.h"
#define SIZE_THRESHHOLD 500
#define VERTICLE_HEIGHT_TO_WIDTH 2.5 //ratio of height to width in verticle targets
#define HEIGHT_WIDTH_VERT_THRESHHOLD 0.5
//TODO: Refine these constants
#define FOCAL_LENGTH 877.1895 //in px
#define VERTICAL_TAPE_WIDTH 2 //in inches

using namespace cv;
using namespace std;

//an vector of points defining the points of detected rectangles
vector<vector<Point2f>> points;

static bool visionFlag = false;
RotatedRect box1, box2;

Vision::Vision() {

}

void Vision::VisionThread(){
	Mat image;
	VideoCapture cap("http://10.13.88.98/mjpg/video.mjpg");

	while(visionFlag){
		if(!cap.isOpened()){
			printf("Camera not opened\n\n\n");
			break;
		}
		printf("\n\n\n\n\nVision Thread\n\n\n\n\n");
		cap >> image;
		analyzeImage(image);
	}
}

bool Vision::toggleVisionThread(){
	visionFlag = !visionFlag;
	thread visionThread(VisionThread);
	if(visionFlag){
		visionThread.detach();
	}else{
		visionThread.join();
	}

	return visionFlag;
}

void Vision::analyzeImage(Mat image){
	//threshold the image
	image = threshold(image);

	//contours defines the contours of our rectangle and hierarchy defines the relationships between contours
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;

	findContours(image, contours, hierarchy, RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE, Point(0,0));

	//the vector of rectangles that pass the area test
	vector<RotatedRect> rects;
	//current rect being analyzed in the for loop
	RotatedRect currentRect;

	//test for area, remove all small rectangles
	for(unsigned int i = 0; i < contours.size(); i++){
		currentRect = minAreaRect(Mat(contours[i]));
		if(currentRect.size.width * currentRect.size.height > 300){
			//if the area is greater than 300 we add it to the vector of rectangles
			rects.push_back(currentRect);
		}
	}

	//find the two our of remaining contours that fit our height x width the best
	float currentMin = 1000, currentSecondMin = 1000; //the minimum offset from the threshold and the second closest
	float currentHWRatio;
	for(unsigned int i = 0; i < rects.size(); i++){
		currentHWRatio = rects[i].size.height / rects[i].size.width;
		if(fabs(currentHWRatio - VERTICLE_HEIGHT_TO_WIDTH) < currentSecondMin){
			if(fabs(currentHWRatio - VERTICLE_HEIGHT_TO_WIDTH) < currentMin){
				box2 = box1; //the second closest to the perfect ratio
				box1 = rects[i]; //the closest to the perfect height x width ratio
			}else{
				box2 = rects[i];
			}
		}
	}
}


Mat Vision::threshold(Mat orig){
	//a matrix to hold the return value
	Mat threshhold;

	//inRange applies a binary mask to all pixels within the specified scalar ranges
	//the values in the scalars use the BGR colorspace instead of RGB out of convention however values still exists from 0-255
	inRange(orig, Scalar(210, 200, 0), Scalar(255, 255, 100), threshhold);

	blur(threshhold, threshhold, Size(3,3));

	return threshhold;
}

float Vision::getDistance(){
	//uses similar triangles in distance = (width * focal length) / perceived pixels
	float percievedPixels = box1.size.width;
	float distance = (VERTICAL_TAPE_WIDTH * FOCAL_LENGTH) / percievedPixels;
	return distance;
}

float Vision::getHorizontalOffset(){
	float center = (box1.center.x + box2.center.x) / 2;
	float pixelOffset = center - 320; //320 is half the horizontal resolution of the camera feed
	float inchesPerPixel = (VERTICAL_TAPE_WIDTH / box1.size.width); //a ratio to multiply by the pixel offset
	return (inchesPerPixel * pixelOffset);
}

Vision::~Vision() {
	// TODO Auto-generated destructor stub
}

