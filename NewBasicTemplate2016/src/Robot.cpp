#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"
//#include "Commands/GetRobotOverDefenseIntoPosition.h"
#include "OI.h"
#include "Commands/ChangeManipulator.h"
#include "Commands/ChangeDriver.h"

class Robot: public IterativeRobot
{
private:
	//SendableChooser *defenseChooser;
	//CommandGroup* autoCommand;
	//int defensePosition;

	SendableChooser* manipulatorChooser;
	SendableChooser* driverChooser;

	void RobotInit()
	{
		CommandBase::init();

		/*defensePosition = Preferences::GetInstance()->GetInt("Defense Position", 1);

		defenseChooser = new SendableChooser();

		defenseChooser->AddDefault("Low Bar", new GetRobotOverDefenseIntoPosition(AnalogSensors::CASE_LOW_BAR, defensePosition));
		defenseChooser->AddObject("Rough Terrain", new GetRobotOverDefenseIntoPosition(AnalogSensors::CASE_ROUGH_TERRAIN, defensePosition));
		defenseChooser->AddObject("Ramparts", new GetRobotOverDefenseIntoPosition(AnalogSensors::CASE_RAMPARTS, defensePosition));
		defenseChooser->AddObject("Moat", new GetRobotOverDefenseIntoPosition(AnalogSensors::CASE_MOAT, defensePosition));
		defenseChooser->AddObject("Rock Wall", new GetRobotOverDefenseIntoPosition(AnalogSensors::CASE_ROCKWALL, defensePosition));
		defenseChooser->AddObject("Cheval De Frise", new GetRobotOverDefenseIntoPosition(AnalogSensors::CASE_CHEVAL_DE_FRISE, defensePosition));
		*/

		manipulatorChooser = new SendableChooser();
		manipulatorChooser->AddDefault(CommandBase::oi->chris->NAME, new ChangeManipulator(CommandBase::oi->chris));
		manipulatorChooser->AddObject(CommandBase::oi->sam->NAME, new ChangeManipulator(CommandBase::oi->sam));
		manipulatorChooser->AddObject(CommandBase::oi->brandon->NAME, new ChangeManipulator(CommandBase::oi->brandon));
		SmartDashboard::PutData("Manipulators", manipulatorChooser);

		driverChooser = new SendableChooser();
		driverChooser->AddDefault(CommandBase::oi->lefty->NAME, new ChangeDriver(CommandBase::oi->lefty));
		driverChooser->AddObject(CommandBase::oi->righty->NAME, new ChangeDriver(CommandBase::oi->righty));
		SmartDashboard::PutData("Drivers", driverChooser);
	}
	
	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void AutonomousInit()
	{
		//autoCommand = (CommandGroup*) defenseChooser->GetSelected();
		//autoCommand->Start();
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

