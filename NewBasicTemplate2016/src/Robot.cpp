#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"
//#include "Commands/ChangeManipulator.h"
//#include "Commands/ChangeDriver.h"
#include "Commands/AutoCommand.h"

class Robot: public IterativeRobot
{
private:
	//SendableChooser* autoChooser;
	CommandGroup* autoCommand;


	void RobotInit()
	{
		CommandBase::init();

		/*
		autoChooser = new SendableChooser();
		autoChooser->AddDefault("Other Slow", new AutoCommand(Arm::AUTO_NON_LOW_BAR, true));
		autoChooser->AddDefault("Other Fast", new AutoCommand(Arm::AUTO_NON_LOW_BAR, true));
		autoChooser->AddObject("Low Bar", new AutoCommand(Arm::AUTO_LOW_BAR, true));
		autoChooser->AddObject("Only Reach Defense", new AutoCommand(Arm::AUTO_NON_LOW_BAR, false));
		SmartDashboard::PutData("Autonomous Select", autoChooser);
		*/
	}
	
	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void AutonomousInit()
	{
		//autoCommand = (CommandGroup*) autoChooser->GetSelected();

		//  LowBar is automatically calculated if defense position is 1
		//bool lowBar = Preferences::GetInstance()->GetBoolean("Low Bar", true);

		//  Input the defense position 1-5 in which the robot starts in front of before auto begins
		int defensePosition = Preferences::GetInstance()->GetInt("Defense Position: ", 1);

		//  True if robot is to go a faster speed, false if about an average speed
		bool fastDefense = Preferences::GetInstance()->GetBoolean("Fast Defense", false);

		autoCommand = new AutoCommand(defensePosition, fastDefense);
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

