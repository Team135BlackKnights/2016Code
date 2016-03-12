#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"
//#include "Commands/ChangeManipulator.h"
//#include "Commands/ChangeDriver.h"
#include "Commands/AutoCommand.h"

class Robot: public IterativeRobot
{
private:
	SendableChooser* autoChooser;
	CommandGroup* autoCommand;

	int defensePosition = 1;

	void RobotInit()
	{
		CommandBase::init();

		autoChooser = new SendableChooser();
		autoChooser->AddDefault("Low Bar", new AutoCommand(DriveTrain::LOW_BAR, defensePosition));
		autoChooser->AddObject("Rock Wall", new AutoCommand(DriveTrain::ROCK_WALL, defensePosition));
		autoChooser->AddObject("Rough Terrain", new AutoCommand(DriveTrain::ROUGH_TERRAIN, defensePosition));
		autoChooser->AddObject("Ramparts", new AutoCommand(DriveTrain::RAMPARTS, defensePosition));
		autoChooser->AddObject("Moat", new AutoCommand(DriveTrain::MOAT, defensePosition));
		SmartDashboard::PutData("AUTOs", autoChooser);
	}
	
	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void AutonomousInit()
	{
		autoCommand = (CommandGroup*) autoChooser->GetSelected();
		autoCommand->Start();
	}

	void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TeleopInit()
	{
	}

	void TeleopPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TestPeriodic()
	{
	}
};

START_ROBOT_CLASS(Robot);

