#include <Commands/DriveDistanceAndLowerArm.h>
#include "AutoCommand.h"
#include "DriveDistance.h"
#include "../CommandBase.h"
#include "TurnRobotAngle.h"
#include "AutomationOfArm.h"
#include "ShootBoulder.h"
#include "WaitTime.h"
#include "Move.h"
#include "DriveOverDefenseWithSonars.h"
#include "CenterRobotAfterOverDefense.h"

AutoCommand::AutoCommand(int defensePosition, bool fastDefense, bool shoot)
{
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

	//  True, move arm to bottom limit switch
	//  False, move arm to 25 degrees above bottom limit switch
	std::cout << defensePosition << std::endl;
	bool lowBar = defensePosition == 1 ? Arm::AUTO_ZERO_DEGREES : Arm::AUTO_NON_LOW_BAR;

	AddSequential(new DriveDistanceAndLowerArm(DRIVE_DISTANCE_TO_RAMP, lowBar, NON_ZERO_ENCODER), 6.0f);

	if (fastDefense) {
		motorSpeed = .65f;
	}
	else {
		motorSpeed = .55f;
	}
	AddSequential(new DriveDistance(DISTANCE_TO_TRAVEL_OVER_DEFENSE, motorSpeed));
	//AddSequential(new DriveOverDefenseWithSonars(motorSpeed));
	//AddSequential(new WaitTime(.4f));
	//AddSequential(new CenterRobotAfterOverDefense(.8f));

	if (lowBar) {
		AddParallel(new AutomationOfArm(15.0f));
		AddSequential(new DriveDistance(DISTANCE_TO_TRAVEL_AFTER_CROSSING_DEFENSE, .875f));
		AddSequential(new WaitTime(1.0f));
	}
	else {
		AddSequential(new WaitTime(.5f));
		AddParallel(new AutomationOfArm(15.0f));
		AddSequential(new DriveDistance(DISTANCE_TO_TRAVEL_AFTER_CROSSING_DEFENSE, .50f));
		AddSequential(new WaitTime(1.0f));
	}

	if (shoot) {
		//  Move according to the defense Position the robot is set in front of
		switch (defensePosition) {
		case 0:
			return;

		case 1:
			//  Needs Testing
			AddSequential(new TurnRobotAngle(40.0D, DriveTrain::RIGHT_TURN));
			AddSequential(new WaitTime(.25f));
			AddParallel(new AutomationOfArm(39.0D));
			AddSequential(new ShootBoulder());
			break;

		case 2:
			//  Needs Testing
			AddSequential(new DriveDistance(40));
			AddSequential(new TurnRobotAngle(35, DriveTrain::RIGHT_TURN));
			AddParallel(new AutomationOfArm(39.0D));
			AddSequential(new ShootBoulder());
			break;

		case 3:
			//  Needs Testing
			AddSequential(new TurnRobotAngle(15, DriveTrain::RIGHT_TURN));
			AddParallel(new AutomationOfArm(35.0D));
			AddSequential(new ShootBoulder());
			break;

		case 4:
			//  Needs Testing
			AddSequential(new TurnRobotAngle(8, DriveTrain::LEFT_TURN));
			AddParallel(new AutomationOfArm(35.0D));
			AddSequential(new ShootBoulder());
			break;

		case 5:
			//  Needs Testing
			AddSequential(new TurnRobotAngle(45, DriveTrain::LEFT_TURN));
			AddSequential(new DriveDistance(40));
			AddSequential(new TurnRobotAngle(35, DriveTrain::RIGHT_TURN));
			AddParallel(new AutomationOfArm(35.0D));
			AddSequential(new ShootBoulder());
			break;

		default:
			std::cout << "WHAT ARE YOU DOING!!!!!!!\n";
			break;
		}
	}

}
