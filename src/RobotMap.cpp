// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
std::shared_ptr<SpeedController> RobotMap::driveTrainLeftFront;
std::shared_ptr<SpeedController> RobotMap::driveTrainLeftRear;
std::shared_ptr<SpeedController> RobotMap::driveTrainRightFront;
std::shared_ptr<SpeedController> RobotMap::driveTrainRightRear;
std::shared_ptr<RobotDrive> RobotMap::driveTrainRobotDrive;
std::shared_ptr<Encoder> RobotMap::driveTrainRightEncoder;
std::shared_ptr<SpeedController> RobotMap::ballIntakeIntakeMotor;
std::shared_ptr<SpeedController> RobotMap::winchWinchMotor;
std::shared_ptr<SpeedController> RobotMap::feederShooterFeedingMotor;
std::shared_ptr<Encoder> RobotMap::shooterShooterEncoder;
std::shared_ptr<SpeedController> RobotMap::shooterShooterMotor;
std::shared_ptr<PIDController> RobotMap::shooterShooterPID;
std::shared_ptr<DigitalInput> RobotMap::aimerBottomLimit;
std::shared_ptr<DigitalInput> RobotMap::aimerTopLimit;
std::shared_ptr<Encoder> RobotMap::aimerAimEncoder;
std::shared_ptr<SpeedController> RobotMap::aimerAimMotor;
std::shared_ptr<PIDController> RobotMap::aimerAimerPID;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
std::shared_ptr<AnalogInput> RobotMap::driveTrainfirstBit;
std::shared_ptr<AnalogInput> RobotMap::driveTrainsecondBit;
std::shared_ptr<AnalogInput> RobotMap::driveTrainthirdBit;
std::shared_ptr<AnalogInput> RobotMap::driveTrainfourthBit;

std::shared_ptr<ADIS16448_IMU> RobotMap::imu;


std::shared_ptr<Relay> RobotMap::visionVisionLight;

void RobotMap::init() {

    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    LiveWindow *lw = LiveWindow::GetInstance();

    driveTrainLeftFront.reset(new Talon(6));
    lw->AddActuator("DriveTrain", "LeftFront", std::static_pointer_cast<Talon>(driveTrainLeftFront));
    
    driveTrainLeftRear.reset(new Talon(7));
    lw->AddActuator("DriveTrain", "LeftRear", std::static_pointer_cast<Talon>(driveTrainLeftRear));
    
    driveTrainRightFront.reset(new Talon(9));
    lw->AddActuator("DriveTrain", "RightFront", std::static_pointer_cast<Talon>(driveTrainRightFront));
    
    driveTrainRightRear.reset(new Talon(8));
    lw->AddActuator("DriveTrain", "RightRear", std::static_pointer_cast<Talon>(driveTrainRightRear));
    
    driveTrainRobotDrive.reset(new RobotDrive(driveTrainLeftFront, driveTrainLeftRear,
              driveTrainRightFront, driveTrainRightRear));
    
    driveTrainRobotDrive->SetSafetyEnabled(true);
        driveTrainRobotDrive->SetExpiration(0.1);
        driveTrainRobotDrive->SetSensitivity(0.5);
        driveTrainRobotDrive->SetMaxOutput(1.0);

    driveTrainRightEncoder.reset(new Encoder(0, 1, false, Encoder::k4X));
    lw->AddSensor("DriveTrain", "RightEncoder", driveTrainRightEncoder);
    driveTrainRightEncoder->SetDistancePerPulse(0.005236);
    driveTrainRightEncoder->SetPIDSourceType(PIDSourceType::kRate);
    ballIntakeIntakeMotor.reset(new Spark(3));
    lw->AddActuator("BallIntake", "IntakeMotor", std::static_pointer_cast<Spark>(ballIntakeIntakeMotor));
    
    winchWinchMotor.reset(new Spark(4));
    lw->AddActuator("Winch", "WinchMotor", std::static_pointer_cast<Spark>(winchWinchMotor));
    
    feederShooterFeedingMotor.reset(new Spark(2));
    lw->AddActuator("Feeder", "ShooterFeedingMotor", std::static_pointer_cast<Spark>(feederShooterFeedingMotor));
    
    shooterShooterEncoder.reset(new Encoder(2, 3, false, Encoder::k1X));
    lw->AddSensor("Shooter", "ShooterEncoder", shooterShooterEncoder);
    shooterShooterEncoder->SetDistancePerPulse(1.3020833);
    shooterShooterEncoder->SetPIDSourceType(PIDSourceType::kRate);
    shooterShooterMotor.reset(new TalonSRX(5));
    lw->AddActuator("Shooter", "ShooterMotor", std::static_pointer_cast<TalonSRX>(shooterShooterMotor));
    
    shooterShooterPID.reset(new PIDController(2.4E-5, 4.0E-6, 0.0,/* F: 0.0, */ shooterShooterEncoder.get(), shooterShooterMotor.get(), 0.02));
    lw->AddActuator("Shooter", "ShooterPID", shooterShooterPID);
    shooterShooterPID->SetContinuous(false); shooterShooterPID->SetAbsoluteTolerance(10.0); 
        shooterShooterPID->SetOutputRange(-1.0, 1.0);
    aimerBottomLimit.reset(new DigitalInput(6));
    lw->AddSensor("Aimer", "BottomLimit", aimerBottomLimit);
    
    aimerTopLimit.reset(new DigitalInput(7));
    lw->AddSensor("Aimer", "TopLimit", aimerTopLimit);
    
    aimerAimEncoder.reset(new Encoder(4, 5, false, Encoder::k4X));
    lw->AddSensor("Aimer", "AimEncoder", aimerAimEncoder);
    aimerAimEncoder->SetDistancePerPulse(0.001428);
    aimerAimEncoder->SetPIDSourceType(PIDSourceType::kDisplacement);
    aimerAimMotor.reset(new Spark(0));
    lw->AddActuator("Aimer", "AimMotor", std::static_pointer_cast<Spark>(aimerAimMotor));
    
    aimerAimerPID.reset(new PIDController(0.5, 0.0, 0.0,/* F: 0.0, */ aimerAimEncoder.get(), aimerAimMotor.get(), 0.02));
    lw->AddActuator("Aimer", "AimerPID", aimerAimerPID);
    aimerAimerPID->SetContinuous(false); aimerAimerPID->SetAbsoluteTolerance(0.05); 
        aimerAimerPID->SetOutputRange(-1.0, 1.0);


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	driveTrainfirstBit.reset(new AnalogInput(0));
	lw->AddSensor("DriveTrain", "firstBit", driveTrainfirstBit);

	driveTrainsecondBit.reset(new AnalogInput(1));
	lw->AddSensor("DriveTrain", "secondBit", driveTrainsecondBit);

	driveTrainthirdBit.reset(new AnalogInput(2));
	lw->AddSensor("DriveTrain", "thirdBit", driveTrainthirdBit);

	driveTrainfourthBit.reset(new AnalogInput(3));
	lw->AddSensor("DriveTrain", "fourthBit", driveTrainfourthBit);

    visionVisionLight.reset(new Relay(0, Relay::kForwardOnly));
    lw->AddActuator("Vision", "VisionLight", visionVisionLight);

    imu.reset(new ADIS16448_IMU());
}
