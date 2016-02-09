#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"

class Robot: public IterativeRobot
{
private:

	LiveWindow *LiveWin;
	SendableChooser *Defense;

	void RobotInit()
	{
		CommandBase::init();

		LiveWin = LiveWindow::GetInstance();
		Defense = new SendableChooser(); //Creates a chooser instance named 'Defense'

		//Adds Live Window Radio Button Choices for Defenses
		Defense->AddDefault("Stay Still", new Autonomous(0)); //Runs Autonomous with parameter of 0
		Defense->AddObject("Drive Defense", new Autonomous(1)); //Runs Autonomous with parameter of 1
		Defense->AddObject("Cheval de Frise", new Autonomous(2)); //Runs Autonomous with parameter of 2
		Defense->AddObject("Drawbridge", new Autonomous(3)); //Runs Autonomous with parameter of 3
		Defense->AddObject("Sally Port", new Autonomous(4)); //Runs Autonomous with parameter of 4
		Defense->AddObject("Portcullis", new Autonomous(5)); //Runs Autonomous with parameter of 5

		SmartDashboard::PutData("Defenses", Defense); //Displays Defense Choices
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

