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


	void RobotInit()
	{
		CommandBase::init();

		autoChooser = new SendableChooser();
		autoChooser->AddDefault("No Low Bar And Over Defense", new AutoCommand(Arm::AUTO_NON_LOW_BAR, true));
		autoChooser->AddObject("Low Bar and Over Defense", new AutoCommand(Arm::AUTO_LOW_BAR, true));
		autoChooser->AddObject("Only Reach Defense", new AutoCommand(false, false));
		SmartDashboard::PutData("Autonomous Select", autoChooser);
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

