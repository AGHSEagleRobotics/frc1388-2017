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

using namespace std;

class Vision {
public:
	Vision(string ip);
	virtual ~Vision();
	void SetupCamera();
};

#endif /* SRC_COMMANDS_VISION_H_ */
