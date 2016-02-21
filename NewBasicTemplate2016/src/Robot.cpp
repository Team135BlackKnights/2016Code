#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"
#include "Subsystems/SerialCommunication.h"
#include "Commands/GetRobotOverDefenseIntoPosition.h"
#include "Commands/DriveDistance.h"

class Robot: public IterativeRobot
{
private:
	//SendableChooser* sonarAndLightChooser;
	//CommandGroup* sonarAndLightCommand;
	Command* crosssDefenseStrictlyBasedOnARawDistance;

	void RobotInit()
	{
		CommandBase::init();
		double dist = Preferences::GetInstance()->GetFloat((std::string)"dist", 140.0f);
		crosssDefenseStrictlyBasedOnARawDistance = new DriveDistance(dist);
		//sonarAndLightChooser = new SendableChooser();
		//sonarAndLightChooser->AddDefault("Both Sonars and Light", new GetRobotOverDefenseIntoPosition(SerialCommunication::CASE_LEFT_RIGHT_AND_LIGHT));
		//sonarAndLightChooser->AddObject("Right Sonar and Light", new GetRobotOverDefenseIntoPosition(SerialCommunication::CASE_RIGHT_AND_LIGHT));
		//sonarAndLightChooser->AddObject("Left Sonar and Light", new GetRobotOverDefenseIntoPosition(SerialCommunication::CASE_LEFT_AND_LIGHT));
		//sonarAndLightChooser->AddObject("Only Light", new GetRobotOverDefenseIntoPosition(SerialCommunication::CASE_LIGHT));

		//SmartDashboard::PutData("Sonars and Light Chooser", sonarAndLightChooser);
	}
	
	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void AutonomousInit()
	{
		//sonarAndLightCommand = (CommandGroup*) sonarAndLightChooser->GetSelected();
		//sonarAndLightCommand->Start();
		crosssDefenseStrictlyBasedOnARawDistance->Start();
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

