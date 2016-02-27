#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"
#include "Subsystems/SerialCommunication.h"
#include "Commands/GetRobotOverDefenseIntoPosition.h"
#include "Commands/DriveDistance.h"
#include "OI.h"

class Robot: public IterativeRobot
{
private:
	SendableChooser *defenseChooser;
	CommandGroup* autoCommand;
	int defensePosition;
	void RobotInit()
	{
		CommandBase::init();
		defensePosition = Preferences::GetInstance()->GetInt("Defense Position", 1);

		defenseChooser = new SendableChooser();

		defenseChooser->AddDefault("Low Bar", new GetRobotOverDefenseIntoPosition(AnalogSensors::CASE_LOW_BAR, defensePosition));
		defenseChooser->AddObject("Rough Terrain", new GetRobotOverDefenseIntoPosition(AnalogSensors::CASE_ROUGH_TERRAIN, defensePosition));
		defenseChooser->AddObject("Ramparts", new GetRobotOverDefenseIntoPosition(AnalogSensors::CASE_RAMPARTS, defensePosition));
		defenseChooser->AddObject("Moat", new GetRobotOverDefenseIntoPosition(AnalogSensors::CASE_MOAT, defensePosition));
		defenseChooser->AddObject("Rock Wall", new GetRobotOverDefenseIntoPosition(AnalogSensors::CASE_ROCKWALL, defensePosition));

	}
	
	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void AutonomousInit()
	{
		autoCommand = (CommandGroup*) defenseChooser->GetSelected();
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

