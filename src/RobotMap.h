// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef ROBOTMAP_H
#define ROBOTMAP_H

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "WPILib.h"

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
class RobotMap {
public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	static std::shared_ptr<SpeedController> driveTrainLeftFront;
	static std::shared_ptr<SpeedController> driveTrainLeftRear;
	static std::shared_ptr<SpeedController> driveTrainRightFront;
	static std::shared_ptr<SpeedController> driveTrainRightRear;
	static std::shared_ptr<RobotDrive> driveTrainRobotDrive;
	static std::shared_ptr<Encoder> driveTrainRightEncoder;
	static std::shared_ptr<SpeedController> ballIntakeIntakeMotor;
	static std::shared_ptr<SpeedController> winchWinchMotor;
	static std::shared_ptr<SpeedController> feederShooterFeedingMotor;
	static std::shared_ptr<Encoder> shooterShooterEncoder;
	static std::shared_ptr<SpeedController> shooterShooterMotor;
	static std::shared_ptr<PIDController> shooterShooterPID;
	static std::shared_ptr<DigitalInput> aimerBottomLimit;
	static std::shared_ptr<DigitalInput> aimerTopLimit;
	static std::shared_ptr<Encoder> aimerAimEncoder;
	static std::shared_ptr<SpeedController> aimerAimMotor;
	static std::shared_ptr<PIDController> aimerAimerPID;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	static std::shared_ptr<AnalogInput> driveTrainfirstBit;
	static std::shared_ptr<AnalogInput> driveTrainsecondBit;
	static std::shared_ptr<AnalogInput> driveTrainthirdBit;
	static std::shared_ptr<AnalogInput> driveTrainfourthBit;

	static std::shared_ptr<Relay> visionVisionLight;

	static std::shared_ptr<ADIS16448_IMU> imu;

	static void init();
};
#endif
