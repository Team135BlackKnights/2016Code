#include <Commands/DriveDistanceAndLowerArm.h>
#include "AutoCommand.h"
#include "DriveDistance.h"
#include "../CommandBase.h"
#include "TurnRobotAngle.h"
#include "AimBot.h"
#include "AutomationOfArm.h"
#include "ShootBoulder.h"
#include "WaitTime.h"
#include "Move.h"

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

	AddSequential(new DriveDistanceAndLowerArm(DRIVE_DISTANCE_TO_RAMP, lowBar, ZERO_ENCODER));

	if (fastDefense) {
		motorSpeed = .65f;
	}
	else {
		motorSpeed = .55f;
	}
	std::cout << defensePosition << std::endl;
	AddSequential(new DriveDistance(DISTANCE_TO_TRAVEL_OVER_DEFENSE, motorSpeed));

	if (lowBar) {
		AddParallel(new AutomationOfArm(15.0f));
		AddSequential(new DriveDistance(DISTANCE_TO_TRAVEL_AFTER_CROSSING_DEFENSE, .875f));
		AddSequential(new WaitTime(1.0f));
	}
	else {
		std::cout << defensePosition << std::endl;
		AddSequential(new WaitTime(.5f));
		std::cout << defensePosition << std::endl;
		AddParallel(new AutomationOfArm(15.0f));
		AddSequential(new DriveDistance(DISTANCE_TO_TRAVEL_AFTER_CROSSING_DEFENSE, .50f));
		AddSequential(new WaitTime(1.0f));
		std::cout << defensePosition << std::endl;
	}

	//  Move according to the defense Position the robot is set in front of
	switch (defensePosition) {
	case 0:
		return;

	case 1:
		//AddParallel(new DriveDistance(48, 0.875f));
		//AddSequential(new AutomationOfArm(15.0f));
		//AddSequential(new TurnRobotAngle(62.5D, TurnRobotAngle::RIGHT_TURN));
		//AddSequential(new AutomationOfArm(40.0D));
		///AddSequential(new ShootBoulder());
		//AddSequential(new TurnRobotAngle(52.5D, TurnRobotAngle::RIGHT_TURN));
		AddSequential(new TurnRobotAngle(35.0D, TurnRobotAngle::RIGHT_TURN));
		AddSequential(new WaitTime(.25f));
		//AddSequential(new Move(.3,0), 1.000000f);
		//AddSequential(new AimBot(1));
	case 2:
		AddSequential(new DriveDistance(40));
		AddSequential(new TurnRobotAngle(35, TurnRobotAngle::RIGHT_TURN));
	case 3:
		AddSequential(new TurnRobotAngle(20, TurnRobotAngle::RIGHT_TURN));
		//AddSequential(new AimBot(3));
	case 4:
		//AddSequential(new TurnRobotAngle(8, TurnRobotAngle::RIGHT_TURN));
		//AddSequential(new AimBot(4));
	case 5:
		AddSequential(new TurnRobotAngle(60, TurnRobotAngle::LEFT_TURN));
		AddSequential(new DriveDistance(58));
		AddSequential(new TurnRobotAngle(60, TurnRobotAngle::RIGHT_TURN));
	default:
		std::cout << "WHAT ARE YOU DOING!!!!!!!\n";
	}

	AddSequential(new AimBot(defensePosition, shoot));

}
