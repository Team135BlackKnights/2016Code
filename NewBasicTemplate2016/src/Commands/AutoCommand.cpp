#include <Commands/DriveDistanceAndLowerArm.h>
#include "AutoCommand.h"
#include "DriveDistance.h"
#include "../CommandBase.h"
#include "TurnRobotAngle.h"
#include "AimBot.h"

AutoCommand::AutoCommand(bool lowBar, int defensePosition, bool fastDefense)
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
	AddSequential(new DriveDistanceAndLowerArm(DRIVE_DISTANCE_TO_RAMP, lowBar, ZERO_ENCODER));

	if (fastDefense) {
		motorSpeed = .625f;
	}
	else {
		motorSpeed = .55f;
	}

	AddSequential(new DriveDistance(DISTANCE_TO_TRAVEL_OVER_DEFENSE, motorSpeed));

	if (lowBar) {
		AddSequential(new DriveDistance(DISTANCE_TO_TRAVEL_AFTER_CROSSING_DEFENSE, .80f));
	}
	else {
		AddSequential(new DriveDistanceAndLowerArm(DISTANCE_TO_TRAVEL_AFTER_CROSSING_DEFENSE, Arm::AUTO_ZERO_DEGREES, NON_ZERO_ENCODER));
	}

	//  Move according to the defense Position the robot is set in front of
	if (defensePosition == 1) {
		AddSequential(new DriveDistance(38, 0.8f));
		AddSequential(new TurnRobotAngle(50, RIGHT_TURN));
	}

	else if (defensePosition == 2) {
		AddSequential(new DriveDistance(40));
		AddSequential(new TurnRobotAngle(35, RIGHT_TURN));
	}

	else if (defensePosition == 3) {
		AddSequential(new TurnRobotAngle(10, RIGHT_TURN));
	}

	else if (defensePosition == 4) {
		AddSequential(new DriveDistance(10, LEFT_TURN));
	}

	else if (defensePosition == 5) {
		AddSequential(new TurnRobotAngle(60, LEFT_TURN));
		AddSequential(new DriveDistance(58));
		AddSequential(new TurnRobotAngle(60, RIGHT_TURN));
	}

	AddSequential(new AimBot());

}
