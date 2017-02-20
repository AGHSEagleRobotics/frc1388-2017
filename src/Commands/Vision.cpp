/*
 * Vision.cpp
 *
 *  Created on: Jan 14, 2017
 *      Author: Joey
 */

#include "Vision.h"
#include <string>
#include "WPILib.h"
#include <algorithm>

//the threshold of how big our rectangles must be in area to be considered for further testing.
#define SIZE_THRESHHOLD 500

#define VERTICLE_HEIGHT_TO_WIDTH 2.5 //ratio of height to width in vertical targets
//TODO: Refine these constants
#define FOCAL_LENGTH 877.1895 //in px this is a calculated number that represents the equivalent "distance" to the target
#define VERTICAL_TAPE_WIDTH 2 //in inches this is the physical width of the retroreflective tape

using namespace cs;
using namespace cv;
using namespace std;

//the lastTenSamples vector will become the last ten distance samples, I do this to take a median from the last ten so that
//outliers don't get returned as real time inputs as distance
vector<float> lastTenSamples = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

//an vector of points defining the points of detected rectangles
//most of the points below will become irrelevant
vector<vector<Point2f>> points;

static bool visionFlag = false;
Rect box1, box2;
MjpegServer inputStream("MJPEG Server", 8080);
HttpCamera cam("Main Cam", "http://FRC:FRC@10.13.88.97/mjpg/video.mjpg");

Mat img;

Vision::Vision() {

}

void Vision::VisionThread(){

	CvSink sink("Processing Sink");
	sink.SetSource(cam);

	while(visionFlag){
		sink.GrabFrame(img);

		if(!img.empty()){
			printf("not empty\n");
		}

		analyzeImage(img);
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
	printf("img analyzed\n");
	//threshold the image
	image = threshold(image);

	//contours defines the contours of our rectangle and hierarchy defines the relationships between contours
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;

	findContours(image, contours, hierarchy, RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE, Point(0,0));

	//the vector of rectangles that pass the area test
	vector<Rect> rects;
	//current rect being analyzed in the for loop
	Rect currentRect;

	//test for area, remove all small rectangles
	for(unsigned int i = 0; i < contours.size(); i++){
		currentRect = boundingRect(Mat(contours[i]));
		if(currentRect.width * currentRect.height > 300){
			//if the area is greater than 300 we add it to the vector of rectangles
			rects.push_back(currentRect);
		}
	}

	//find the two our of remaining contours that fit our height x width the best
	float currentMin = 1000, currentSecondMin = 1000; //the minimum offset from the threshold and the second closest
	float currentHWRatio;
	for(unsigned int i = 0; i < rects.size(); i++){
		currentHWRatio = rects[i].height / rects[i].width;
		if(fabs(currentHWRatio - VERTICLE_HEIGHT_TO_WIDTH) < currentSecondMin){
			if(fabs(currentHWRatio - VERTICLE_HEIGHT_TO_WIDTH) < currentMin){
				box2 = box1; //the second closest to the perfect ratio
				box1 = rects[i]; //the closest to the perfect height x width ratio
			}else{
				box2 = rects[i];
			}
		}
	}

	setDistance();
	printf("Distance:%f\n", getDistance());
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

void Vision::setDistance(){
	//uses similar triangles in distance = (width * focal length) / perceived pixels
	float percievedPixels = box1.width;
	float distance = (VERTICAL_TAPE_WIDTH * FOCAL_LENGTH) / percievedPixels;

	lastTenSamples.insert(lastTenSamples.begin(), distance);
	lastTenSamples.pop_back();
	sort(lastTenSamples.begin(), lastTenSamples.end());
}

float Vision::getDistance(){
	return (lastTenSamples.at(4) + lastTenSamples.at(5)) / 2;
}

float Vision::getHorizontalOffset(){
	float center = (box1.x + box2.x) / 2;
	float pixelOffset = center - 320; //320 is half the horizontal resolution of the camera feed
	float inchesPerPixel = (VERTICAL_TAPE_WIDTH / box1.width); //a ratio to multiply by the pixel offset
	return (inchesPerPixel * pixelOffset);
}

Mat Vision::returnImg(){
	return img;
}

Vision::~Vision() {
	// TODO Auto-generated destructor stub
}

