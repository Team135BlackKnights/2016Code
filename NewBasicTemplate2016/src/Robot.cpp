#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"

class Robot: public IterativeRobot
{
private:
	LiveWindow *lw;
	CameraServer* camera;
	CommandGroup *autonomousCommand;
	Command *driverModeCommand;
	SendableChooser *chooser;
	SendableChooser *driverMode;

	//NamedSendable *testChooser;
	void RobotInit()
	{
		CommandBase::init();
	}
	
	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void AutonomousInit()
	{
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

