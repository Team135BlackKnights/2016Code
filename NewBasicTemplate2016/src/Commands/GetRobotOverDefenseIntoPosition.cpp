#include "GetRobotOverDefenseIntoPosition.h"
#include "RunningOverDefense.h"
#include "DriveDistance.h"
#include "TurnRobotAngle.h"


//  Input the defense position the robot will go over between 1 and 5
//  Input the type of defense the robot will be going over
GetRobotOverDefenseIntoPosition::GetRobotOverDefenseIntoPosition(AnalogSensors::DEFENSE_METHOD typeOfDefense, int defensePosition)
{
	//  Drive the Robot so it is right in front of the defensive ramp
	AddSequential(new DriveDistance(DISTANCE_NEED_TO_TRAVEL));
	//  Then, go over the defense until the sonars and light detect the robot is over the defense
	AddSequential(new RunningOverDefense(typeOfDefense));

	//  Then execute one of the following commands so the robot will move to its correct position
	//  for camera tracking
	//  Preferable for the robot to be perpendicular to one of the goals for camera tracking

	//  Note: the numbers are in inches
	if (defensePosition == 1) {
		AddSequential(new DriveDistance(120));
	}
	else if (defensePosition == 2) {
		AddSequential(new DriveDistance(145));
	}
	else if (defensePosition == 3) {
		AddSequential(new DriveDistance(80));
		//  Turn the robot 90 degrees to the right
		AddSequential(new TurnRobotAngle(90,DriveTrain::RIGHT));
		AddSequential(new DriveDistance(44));
		//  Turn the robot 90 degrees to the left
		AddSequential(new TurnRobotAngle(90, DriveTrain::LEFT));
	}
	else if (defensePosition == 4) {
		AddSequential(new DriveDistance(85));
	}
	else if (defensePosition == 5) {
		AddSequential(new DriveDistance(140));
	}

	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
}
