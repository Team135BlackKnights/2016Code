#include <Commands/DriveDistanceAndLowerArm.h>
#include "AutoCommand.h"
#include "DriveDistance.h"
#include "../CommandBase.h"
#include "TurnRobotAngle.h"
#include "AimBot.h"
#include "AutomationOfArm.h"
#include "RaiseAndTurn.h"
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
	for(int i = 0; i < 10;i++)
		std::cout << lowBar << std::endl;
	AddSequential(new DriveDistanceAndLowerArm(DRIVE_DISTANCE_TO_RAMP, lowBar, ZERO_ENCODER), 6.0f);

	if (fastDefense) {
		motorSpeed = .65f;
	}
	else {
		motorSpeed = .55f;
	}
	std::cout << defensePosition << std::endl;
	AddSequential(new DriveDistance(DISTANCE_TO_TRAVEL_OVER_DEFENSE + 30.0f, motorSpeed));

	if (lowBar) {
		AddParallel(new AutomationOfArm(10.0f));
		AddSequential(new DriveDistance(DISTANCE_TO_TRAVEL_AFTER_CROSSING_DEFENSE, .875f));
		AddSequential(new WaitTime(1.0f));
	}
	else {
		std::cout << defensePosition << std::endl;
		std::cout << defensePosition << std::endl;
		//AddSequential(new AutomationOfArm(55.0f));
		//AddSequential(new DriveDistance(DISTANCE_TO_TRAVEL_AFTER_CROSSING_DEFENSE, .50f));
		std::cout << defensePosition << std::endl;
	}

	if (shoot) {
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
			//AddSequential(new TurnRobotAngle(35.0D, TurnRobotAngle::RIGHT_TURN));
			AddSequential(new WaitTime(.25f));
			break;
			//AddSequential(new Move(.3,0), 1.000000f);
			//AddSequential(new AimBot(1));
		case 2:
			AddSequential(new DriveDistance(60, .75f));
			AddSequential(new RaiseAndTurn(55.0D, 50.0D, TurnRobotAngle::RIGHT_TURN));
			break;
		case 3:
			AddSequential(new RaiseAndTurn(55.0D, 1.0D, TurnRobotAngle::RIGHT_TURN));
			//AddSequential(new WaitTime(.5f));
			break;
			//AddSequential(new AimBot(3));
		case 4:
			//AddSequential(new RaiseAndTurn(55.0D, 1.0D, TurnRobotAngle::LEFT_TURN));

			AddSequential(new AutomationOfArm(55.0D));
			//AddSequential(new TurnRobotAngle(8, TurnRobotAngle::RIGHT_TURN));
			//AddSequential(new AimBot(4));
			break;
		case 5:
			AddSequential(new WaitTime(.25D));
			AddSequential(new RaiseAndTurn(55.0D, 3.0D, TurnRobotAngle::LEFT_TURN));
			break;
		default:
			std::cout << "WHAT ARE YOU DOING!!!!!!!\n";
			break;
		}

		AddSequential(new AimBot(defensePosition, shoot));
	}

}
