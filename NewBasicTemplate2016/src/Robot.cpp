#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"
#include "Commands/ChangeManipulator.h"
#include "Commands/ChangeDriver.h"

class Robot: public IterativeRobot
{
private:

	SendableChooser* manipulatorChooser;
	SendableChooser* driverChooser;

	void RobotInit()
	{
		CommandBase::init();

		manipulatorChooser = new SendableChooser();
		manipulatorChooser->AddDefault(CommandBase::oi->chris->NAME, new ChangeManipulator(CommandBase::oi->chris));
		manipulatorChooser->AddObject(CommandBase::oi->sam->NAME, new ChangeManipulator(CommandBase::oi->sam));
		manipulatorChooser->AddObject(CommandBase::oi->brandon->NAME, new ChangeManipulator(CommandBase::oi->brandon));
		SmartDashboard::PutData("Manipulators", manipulatorChooser);

		driverChooser = new SendableChooser();
		driverChooser->AddDefault(CommandBase::oi->tyler->NAME, new ChangeDriver(CommandBase::oi->tyler));
		driverChooser->AddObject(CommandBase::oi->righty->NAME, new ChangeDriver(CommandBase::oi->righty));
		SmartDashboard::PutData("Drivers", driverChooser);
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
		((Command*)manipulatorChooser->GetSelected())->Start();
		((Command*)driverChooser->GetSelected())->Start();
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

