// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include <string>

using namespace std;

class OI {
private:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	std::shared_ptr<Joystick> opStick;
	std::shared_ptr<JoystickButton> aimPresetButton;
	std::shared_ptr<JoystickButton> intakeOn;
	std::shared_ptr<JoystickButton> intakeOff;
	std::shared_ptr<JoystickButton> offPower;
	std::shared_ptr<JoystickButton> presetPower;
	std::shared_ptr<JoystickButton> decreasePower;
	std::shared_ptr<JoystickButton> increasePower;
	std::shared_ptr<Joystick> rightStick;
	std::shared_ptr<JoystickButton> bumpP;
	std::shared_ptr<JoystickButton> lowerI;
	std::shared_ptr<JoystickButton> lowerP;
	std::shared_ptr<JoystickButton> bumpI;
	std::shared_ptr<Joystick> leftStick;
	std::shared_ptr<JoystickButton> toggleButton;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	string ballIntakeMotor1();
	string shooterFeeder();
	string shooterMotor();
	string driveConfig();
public:
	OI();
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PROTOTYPES

	std::shared_ptr<Joystick> getLeftStick();
	std::shared_ptr<Joystick> getRightStick();
	std::shared_ptr<Joystick> getOpStick();

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PROTOTYPES
};

#endif
