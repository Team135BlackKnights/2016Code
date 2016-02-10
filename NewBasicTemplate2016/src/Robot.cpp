#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"

class Robot: public IterativeRobot
{
private:

	CommandGroup *autonomousToRun;
	LiveWindow *LiveWin;
	SendableChooser *Defense;

		const int NOTHING = 0;
		const int LOWBAR = 1;
		const int CHEVALDEFRISE = 2;
		const int DRAWBRIDGE = 3;
		const int SALLYPORT = 4;
		const int PORTCULLIS = 5;

	void RobotInit()
	{
		CommandBase::init();

		LiveWin = LiveWindow::GetInstance();
		Defense = new SendableChooser(); //Creates a chooser instance named 'Defense'

		//Adds Live Window Radio Button Choices for Defenses
		Defense->AddDefault("Stay Still", new Autonomous(NOTHING)); //Runs Autonomous with parameter of 0
		Defense->AddObject("Drive Defense", new Autonomous(LOWBAR)); //Runs Autonomous with parameter of 1
		Defense->AddObject("Cheval de Frise", new Autonomous(CHEVALDEFRISE)); //Runs Autonomous with parameter of 2
		Defense->AddObject("Drawbridge", new Autonomous(DRAWBRIDGE)); //Runs Autonomous with parameter of 3
		Defense->AddObject("Sally Port", new Autonomous(SALLYPORT)); //Runs Autonomous with parameter of 4
		Defense->AddObject("Portcullis", new Autonomous(PORTCULLIS)); //Runs Autonomous with parameter of 5

		SmartDashboard::PutData("Defenses", Defense); //Displays Defense Choices



	}
	
	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void AutonomousInit()
	{
		autonomousToRun = (CommandGroup*) Defense->GetSelected();
		autonomousToRun->Start();
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

