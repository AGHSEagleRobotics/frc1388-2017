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

using namespace std;

//an vector of points defining the points of detected rectangles
vector<vector<Point2f>> points;

Vision::Vision() {

}

Mat Vision::analyzeImage(Mat currentFrame){
	//apply a binary mask to the incoming frame using the threshhold function below
	currentFrame = threshhold(currentFrame);

	//a vector of contours that the edge detection process will store the contours in
	vector<vector<Point>> contours;
	//a vector that defines the relationship between parent and child contours from edge detection
	vector<Vec4i> hierarchy;

	//this function will find the contours of the blurred and threshholded targets
	//RETR_EXTERNAL is a flag that tells our heirachy to ignore any child vectors therefore only taking true contours
	//CV_CHAIN_APPROX_SIMPLE will get rid of small useless vectors and focus on the endpoints of the contours
	findContours(currentFrame, contours, hierarchy, RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);

	//a vector that will store our boudning rectangles. The RotatedRect is used because it finds the smallest bounding rect
	//Regardless of area
	vector<RotatedRect> minimumRects(contours.size());
	//width and height will be used to analyze boundingRects
	float width, height;
	//these points will be the points of the rectangles
	Point2f rectanglePoints[4];

	//these are the values to be erased
	vector<int> erasableValues;

	Scalar color = Scalar(0, 0, 255);

	for(unsigned int i = 0; i < contours.size(); i++){
		//find the bounding rectangle for the current contour
		minimumRects[i] = minAreaRect(Mat(contours[i]));

		//copy the points from the bounding rectangles to the array rectanglePoints
		minimumRects[i].points(rectanglePoints);

		//use the 2D distance formula to calculate the width and heigh of smallest area rect
		width = pointDistance(rectanglePoints[0].x, rectanglePoints[1].x, rectanglePoints[0].y, rectanglePoints[1].y);
		height = pointDistance(rectanglePoints[0].x, rectanglePoints[3].x, rectanglePoints[0].y, rectanglePoints[3].y);

		//get rid of values that are too small
		if(height * width < SIZE_THRESHHOLD){
			erasableValues.push_back(i);
		}else{
			//loop through the points and draw lines between them
			for (int j = 0; j < 4; j++) {
			//the use of modulo will make sure when we get to 4 it loops back to 0
				line(currentFrame, rectanglePoints[j], rectanglePoints[(j + 1) % 4], color, 2, 8);
			}
		}
	}

	return currentFrame;
}

double Vision::pointDistance(int x1, int x2, int y1, int y2){
	double returnValue = pow((x2-x1), 2) + pow((y2-y1), 2);
	returnValue = sqrt(returnValue);
	return returnValue;
}

Mat Vision::threshhold(Mat orig){
	//a matrix to hold the return value
	Mat threshhold;

	//inRange applies a binary mask to all pixels within the specified scalar ranges
	//the values in the scalars use the BGR colorspace instead of RGB out of convention however values still exists from 0-255
	inRange(orig, Scalar(210, 100, 0), Scalar(255, 255, 200), threshhold);

	blur(threshhold, threshhold, Size(3,3));

	return threshhold;
}

Vision::~Vision() {
	// TODO Auto-generated destructor stub
}

