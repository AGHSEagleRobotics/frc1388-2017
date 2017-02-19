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
#include "CANTalon.h"
#include "Gyro/src/ADIS16448_IMU.h"

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

//ADIS16448_IMU imu;

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
std::shared_ptr<SpeedController> RobotMap::driveTrainLeftFront;
std::shared_ptr<SpeedController> RobotMap::driveTrainLeftRear;
std::shared_ptr<SpeedController> RobotMap::driveTrainRightRear;
std::shared_ptr<SpeedController> RobotMap::driveTrainRightFront;
std::shared_ptr<RobotDrive> RobotMap::driveTrainRobotDrive;
std::shared_ptr<Encoder> RobotMap::driveTrainRightEncoder;
std::shared_ptr<Encoder> RobotMap::driveTrainLeftEncoder;
std::shared_ptr<SpeedController> RobotMap::ballIntakeIntakeMotor;
std::shared_ptr<SpeedController> RobotMap::winchWinchMotor;
std::shared_ptr<SpeedController> RobotMap::feederShooterFeedingMotor;
std::shared_ptr<Encoder> RobotMap::shooterShootEncoder;
std::shared_ptr<CANTalon> RobotMap::shooterShootMotor;
std::shared_ptr<DigitalInput> RobotMap::aimerBottomLimit;
std::shared_ptr<Encoder> RobotMap::aimerAimEncoder;
std::shared_ptr<SpeedController> RobotMap::aimerAimMotor;
std::shared_ptr<DigitalInput> RobotMap::aimerTopLimit;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION

std::shared_ptr<Relay> RobotMap::visionVisionLight;


void RobotMap::init() {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    LiveWindow *lw = LiveWindow::GetInstance();

    driveTrainLeftFront.reset(new Talon(2));
    lw->AddActuator("DriveTrain", "LeftFront", std::static_pointer_cast<Talon>(driveTrainLeftFront));
    
    driveTrainLeftRear.reset(new Talon(3));
    lw->AddActuator("DriveTrain", "LeftRear", std::static_pointer_cast<Talon>(driveTrainLeftRear));
    
    driveTrainRightRear.reset(new Talon(1));
    lw->AddActuator("DriveTrain", "RightRear", std::static_pointer_cast<Talon>(driveTrainRightRear));
    
    driveTrainRightFront.reset(new Talon(0));
    lw->AddActuator("DriveTrain", "RightFront", std::static_pointer_cast<Talon>(driveTrainRightFront));
    
    driveTrainRobotDrive.reset(new RobotDrive(driveTrainLeftFront, driveTrainLeftRear,
              driveTrainRightFront, driveTrainRightRear));
    
    driveTrainRobotDrive->SetSafetyEnabled(false);
        driveTrainRobotDrive->SetExpiration(0.1);
        driveTrainRobotDrive->SetSensitivity(0.5);
        driveTrainRobotDrive->SetMaxOutput(1.0);

    driveTrainRightEncoder.reset(new Encoder(1, 2, false, Encoder::k4X));
    lw->AddSensor("DriveTrain", "RightEncoder", driveTrainRightEncoder);
    driveTrainRightEncoder->SetDistancePerPulse(1.0);
    driveTrainRightEncoder->SetPIDSourceType(PIDSourceType::kDisplacement);
    driveTrainLeftEncoder.reset(new Encoder(8, 9, false, Encoder::k4X));
    lw->AddSensor("DriveTrain", "LeftEncoder", driveTrainLeftEncoder);
    driveTrainLeftEncoder->SetDistancePerPulse(1.0);
    driveTrainLeftEncoder->SetPIDSourceType(PIDSourceType::kDisplacement);
    ballIntakeIntakeMotor.reset(new Talon(6));
    lw->AddActuator("BallIntake", "IntakeMotor", std::static_pointer_cast<Talon>(ballIntakeIntakeMotor));
    
    winchWinchMotor.reset(new TalonSRX(7));
    lw->AddActuator("Winch", "WinchMotor", std::static_pointer_cast<TalonSRX>(winchWinchMotor));
    
    feederShooterFeedingMotor.reset(new Talon(5));
    lw->AddActuator("Feeder", "ShooterFeedingMotor", std::static_pointer_cast<Talon>(feederShooterFeedingMotor));
    
    shooterShootEncoder.reset(new Encoder(4, 5, false, Encoder::k4X));
    lw->AddSensor("Shooter", "ShootEncoder", shooterShootEncoder);
    shooterShootEncoder->SetDistancePerPulse(1.0);
    shooterShootEncoder->SetPIDSourceType(PIDSourceType::kRate);
    shooterShootMotor.reset(new CANTalon(0));
    lw->AddActuator("Shooter", "ShootMotor", shooterShootMotor);
    
    aimerBottomLimit.reset(new DigitalInput(6));
    lw->AddSensor("Aimer", "BottomLimit", aimerBottomLimit);
    
    aimerAimEncoder.reset(new Encoder(14, 15, false, Encoder::k4X));
    lw->AddSensor("Aimer", "AimEncoder", aimerAimEncoder);
    aimerAimEncoder->SetDistancePerPulse(1.0);
    aimerAimEncoder->SetPIDSourceType(PIDSourceType::kDisplacement);
    aimerAimMotor.reset(new Talon(14));
    lw->AddActuator("Aimer", "AimMotor", std::static_pointer_cast<Talon>(aimerAimMotor));
    
    aimerTopLimit.reset(new DigitalInput(7));
    lw->AddSensor("Aimer", "TopLimit", aimerTopLimit);

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS

    visionVisionLight.reset(new Relay(0, Relay::kForwardOnly));
    lw->AddActuator("Vision", "VisionLight", visionVisionLight);
}

