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
	Defense = new SendableChooser();

	//Adds Live Window Radio Buttons for Defenses
	Defense->AddDefault("Stay Still", new Autonomous(DEFENSE::NOTHING));
	Defense->AddObject("Drive Defense", new Autonomous(DEFENSE::LOWBAR));
	Defense->AddObject("Cheval de Frise", new Autonomous(DEFENSE::CHEVAL_DE_FRISE));
	Defense->AddObject("Drawbridge", new Autonomous(DEFENSE::DRAWBRIDGE));
	Defense->AddObject("Sally Port", new Autonomous(DEFENSE::SALLYPORT));
	Defense->AddObject("Portcullis", new Autonomous(DEFENSE::PORTCULLIS));

	SmartDashboard::PutData("Defenses", Defense);
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

