#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"
#include "Commands/ChangeManipulator.h"
#include "Commands/ChangeDriver.h"
#include "Commands/AutoCommand.h"

class Robot: public IterativeRobot
{
private:

	SendableChooser* manipulatorChooser;
	SendableChooser* driverChooser;

	SendableChooser* autoChooser;
	CommandGroup* autoCommand;

	int defensePosition;

	void RobotInit()
	{
		CommandBase::init();

		manipulatorChooser = new SendableChooser();
		manipulatorChooser->AddDefault(CommandBase::oi->chris->NAME, new ChangeManipulator(CommandBase::oi->chris));
		manipulatorChooser->AddObject(CommandBase::oi->sam->NAME, new ChangeManipulator(CommandBase::oi->sam));
		manipulatorChooser->AddObject(CommandBase::oi->brandon->NAME, new ChangeManipulator(CommandBase::oi->brandon));
		SmartDashboard::PutData("Manipulators", manipulatorChooser);

		driverChooser = new SendableChooser();
		driverChooser->AddDefault(CommandBase::oi->lefty->NAME, new ChangeDriver(CommandBase::oi->lefty));
		driverChooser->AddObject(CommandBase::oi->righty->NAME, new ChangeDriver(CommandBase::oi->righty));
		SmartDashboard::PutData("Drivers", driverChooser);

		autoChooser = new SendableChooser();
		defensePosition = Preferences::GetInstance()->GetInt("Defense Position", 1);
		autoChooser->AddDefault("Low Bar", new AutoCommand(DriveTrain::TYPE_OF_DEFENSE::LOW_BAR, defensePosition));
		autoChooser->AddObject("Rock Wall", new AutoCommand(DriveTrain::TYPE_OF_DEFENSE::ROCK_WALL, defensePosition));
		autoChooser->AddObject("Rough Terrain", new AutoCommand(DriveTrain::TYPE_OF_DEFENSE::ROUGH_TERRAIN, defensePosition));
		autoChooser->AddObject("Ramparts", new AutoCommand(DriveTrain::TYPE_OF_DEFENSE::RAMPARTS, defensePosition));
		autoChooser->AddObject("Moat", new AutoCommand(DriveTrain::TYPE_OF_DEFENSE::MOAT, defensePosition));
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
		//((Command*)manipulatorChooser->GetSelected())->Start();
		//((Command*)driverChooser->GetSelected())->Start();
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

