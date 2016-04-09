#include "TeleOpAimBot.h"
#include "AutomationOfArm.h"
#include "MoveFromCameraValue.h"
TeleOpAimBot::TeleOpAimBot()
{
	//AddSequential(new CheckSideSide());
	//std::cout << "lined up";
	//AddSequential(new KickKicker());
	AddSequential(new MoveFromCameraValue(Preferences::GetInstance()->GetInt("Defense Position: ", 3)));
	AddSequential(new AutomationOfArm());
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
