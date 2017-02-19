// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Robot.h"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include "Commands/Vision.h"
using namespace std;
using namespace cv;



// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
std::shared_ptr<DriveTrain> Robot::driveTrain;
std::shared_ptr<BallIntake> Robot::ballIntake;
std::shared_ptr<Winch> Robot::winch;
std::shared_ptr<Feeder> Robot::feeder;
std::shared_ptr<Shooter> Robot::shooter;
std::shared_ptr<Aimer> Robot::aimer;
std::unique_ptr<OI> Robot::oi;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
//This is my code to try to fix the excessive source errors in the vision code

//	cs:: UsbCamera camera = CameraServer::GetInstance()->StartAutomaticCapture();
//	camera.SetResolution(640,480);
//	cs::CvSink cvSink = CameraServer::GetInstance()->GetVideo();
//	cs::CvSource outputStreamStd = CameraServer::GetInstance()->PutVideo("Gray", 640, 480);
//	cv::Mat source;
//	cv::Mat output;
//	while(true){
//		cvSink.GrabFrame(source);
//		cvtColor(source, output, cv::COLOR_BGR2GRAY);
//		outputStreamStd.PutFrame(output);
//	}
//}

void Robot::RobotInit() {
	RobotMap::init();


	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    driveTrain.reset(new DriveTrain());
    ballIntake.reset(new BallIntake());
    winch.reset(new Winch());
    feeder.reset(new Feeder());
    shooter.reset(new Shooter());
    aimer.reset(new Aimer());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	// This MUST be here. If the OI creates Commands (which it very likely
	// will), constructing it during the construction of CommandBase (from
	// which commands extend), subsystems are not guaranteed to be
	// yet. Thus, their requires() statements may grab null pointers. Bad
	// news. Don't move it.
	oi.reset(new OI());

	// instantiate the command used for the autonomous period
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
	autonomousCommand.reset(new AutonomousCommand());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS



  }

/**
 * This function is called when the disabled button is hit.
 * You can use it to reset subsystems before shutting down.
 */
void Robot::DisabledInit(){

}

void Robot::DisabledPeriodic() {

	Scheduler::GetInstance()->Run();
}

void Robot::AutonomousInit() {
	if (autonomousCommand.get() != nullptr)
		autonomousCommand->Start();
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// these lines or comment it out.

	if (autonomousCommand.get() != nullptr)
		autonomousCommand->Cancel();


	RobotMap::visionVisionLight->Set(Relay::kForward);
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(Robot);

