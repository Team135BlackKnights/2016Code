#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"
#include "Commands/Autonomous.h"

class Robot: public IterativeRobot
{
private:

	CommandGroup *autonomousToRun;
	LiveWindow *LiveWin;
	SendableChooser *Defense;

	enum DEFENSE {
		NOTHING = 0,
		LOWBAR = 1,
		CHEVAL_DE_FRISE = 2,
		DRAWBRIDGE = 3,
		SALLYPORT = 4,
		PORTCULLIS = 5,
		};


	void RobotInit()
	{
		CommandBase::init();

		LiveWin = LiveWindow::GetInstance();
		Defense = new SendableChooser(); //Creates a chooser instance named 'Defense'

		//Adds Live Window Radio Button Choices for Defenses
	Defense->AddDefault("Stay Still", new Autonomous(DEFENSE::NOTHING)); //Runs Autonomous with parameter of 0
		Defense->AddObject("Drive Defense", new Autonomous(DEFENSE::LOWBAR)); //Runs Autonomous with parameter of 1
		Defense->AddObject("Cheval de Frise", new Autonomous(DEFENSE::CHEVAL_DE_FRISE)); //Runs Autonomous with parameter of 2
		Defense->AddObject("Drawbridge", new Autonomous(DEFENSE::DRAWBRIDGE)); //Runs Autonomous with parameter of 3
		Defense->AddObject("Sally Port", new Autonomous(DEFENSE::SALLYPORT)); //Runs Autonomous with parameter of 4
		Defense->AddObject("Portcullis", new Autonomous(DEFENSE::PORTCULLIS)); //Runs Autonomous with parameter of 5

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

