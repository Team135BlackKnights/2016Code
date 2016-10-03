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
	CameraServer* cameraServer;

	void RobotInit()
	{
		cameraServer = CameraServer::GetInstance();
		cameraServer->SetQuality(50);
				//the camera name (ex "cam0") can be found through the roborio web interface
		cameraServer->StartAutomaticCapture("cam3");


		Preferences::GetInstance()->PutBoolean("UNWINCH", false);
		Preferences::GetInstance()->PutBoolean("PREMATCH CAN RAISE ARM", false);
		CommandBase::init();
		//yeet
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
		int defensePosition = Preferences::GetInstance()->GetInt("AUTO Defense Position: ", 1);

		//  True if robot is to go a faster speed, false if about an average speed
		bool fastDefense = Preferences::GetInstance()->GetBoolean("AUTO Fast Defense", false);

		bool shoot = Preferences::GetInstance()->GetBoolean("AUTO Shoot", false);

		int dir = Preferences::GetInstance()->GetInt("AUTO dir", 0);

		autoCommand = new AutoCommand(defensePosition, fastDefense, shoot, dir);
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

