// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#define DISTALIGN 4

#include "AutonomousCommand.h"
#include "AutonDrive.h"
#include "AutonTurn.h"
#include "ShooterPresetPower.h"
#include "AimInitializer.h"
#include <math.h>
#include "Vision.h"
#define THRESHOLD 0.1
#define BLAST 48

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

AutonomousCommand::AutonomousCommand() {
	int choice = 0;
	bool a = !(Robot::driveTrain->firstBit->GetVoltage() > THRESHOLD);
	bool b = !(Robot::driveTrain->secondBit->GetVoltage()> THRESHOLD);
	bool c = !(Robot::driveTrain->thirdBit->GetVoltage() > THRESHOLD);
	bool d = !(Robot::driveTrain->fourthBit->GetVoltage()> THRESHOLD);
	if(a) choice += 8;
	if(b) choice += 4;
	if(c) choice += 2;
	if(d) choice += 1;

	printf("Choice = %i \n", choice);
	printf("If the choice is incorrect, make sure the wires are plugged in the following manner: \n red, blue, orange, green \n");

	AddParallel(new AimInitializer());
	AddSequential(new AutonDrive(-84));

// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR
	float horizDist;
	int theta;
	double hypVector;

	switch(choice){

	case 0: /*do nothing*/
		//nothing for now
		break;

	case 1: //center pos, center gear
		Vision::toggleVisionThread();
		horizDist = Vision::getHorizontalOffset();
		theta = (int) atan(DISTALIGN / horizDist);
		hypVector = sqrt((pow(DISTALIGN, 2)) / (pow(horizDist, 2)));

		AddSequential(new AutonDrive(4));
		AddSequential(new AutonTurn(theta));
		AddSequential(new AutonDrive(hypVector));
		AddSequential(new AutonTurn(-theta));

		while(medianTenSamples() >= 24){
			//need to account for error somehow
			RobotMap::driveTrainRobotDrive->TankDrive(0.5, 0.5);
		}

		AddSequential(new AutonDrive(24));

		AddSequential(new WaitCommand(3));

		AddSequential(new AutonDrive(-36));
		AddSequential(new AutonTurn(90));
		AddSequential(new AutonDrive(36));
		AddSequential(new AutonTurn(-90));
		AddSequential(new AutonDrive(BLAST));

		Vision::toggleVisionThread();

		break;

	case 2: //right pos, right gear

		Vision::toggleVisionThread();

		AddSequential(new AutonDrive(60));
		AddSequential(new AutonTurn(-30));

		horizDist = Vision::getHorizontalOffset();
		theta = (int) atan(DISTALIGN / horizDist);
		hypVector = sqrt((pow(DISTALIGN, 2)) / (pow(horizDist, 2)));

		AddSequential(new AutonTurn(theta));
		AddSequential(new AutonDrive(hypVector));
		AddSequential(new AutonTurn(-theta));

		while(medianTenSamples() >= 24){
			//need to account for error somehow
			RobotMap::driveTrainRobotDrive->TankDrive(0.5, 0.5);
		}

		AddSequential(new AutonDrive(24));
		AddSequential(new WaitCommand(3));
		AddSequential(new AutonDrive(-36));
		AddSequential(new AutonTurn(30));
		AddSequential(new AutonDrive(BLAST));

		Vision::toggleVisionThread();

		break;

	case 3: //left pos, left gear

		Vision::toggleVisionThread();

		AddSequential(new AutonDrive(60));
		AddSequential(new AutonTurn(30));

		horizDist = Vision::getHorizontalOffset();
		theta = (int) atan(DISTALIGN / horizDist);
		hypVector = sqrt((pow(DISTALIGN, 2)) / (pow(horizDist, 2)));

		AddSequential(new AutonTurn(theta));
		AddSequential(new AutonDrive(hypVector));
		AddSequential(new AutonTurn(-theta));

		while(medianTenSamples() >= 24){
			//need to account for error somehow
			RobotMap::driveTrainRobotDrive->TankDrive(0.5, 0.5);
		}

		AddSequential(new AutonDrive(24));
		AddSequential(new WaitCommand(3));
		AddSequential(new AutonDrive(-36));
		AddSequential(new AutonTurn(-30));
		AddSequential(new AutonDrive(BLAST));

		Vision::toggleVisionThread();

		break;

	case 4: //center pos, shoot

		AddSequential(new AutonDrive(3));
		AddSequential(new AutonTurn(-90));
		AddSequential(new WaitCommand(2));
		AddSequential(new AutonDrive(58));
		AddSequential(new AutonTurn(90));
		AddSequential(new AutonDrive(400));
		AddSequential(new AutonTurn(-45));
		AddSequential(new ShooterPresetPower());
		break;

	case 5: //right pos, shoot

		AddSequential(new AutonDrive(430));
		AddSequential(new AutonTurn(-45));
		AddSequential(new ShooterPresetPower);

		break;

	case 6: //left pos, shoot

		AddSequential(new AutonDrive(3));
		AddSequential(new AutonTurn(-90));
		AddSequential(new AutonDrive(116));
		AddSequential(new AutonTurn(90));
		AddSequential(new AutonDrive(430));
		AddSequential(new AutonTurn(-45));
		AddSequential(new ShooterPresetPower);

		break;
	}
 }

float AutonomousCommand::medianTenSamples(){

	vector<float> lastTen = Vision::getLastTenSamples();
	float median = 0;

	sort(lastTen.begin(), lastTen.end());

	median = (lastTen[4] + lastTen[5]) / 2;

	return median;
}
