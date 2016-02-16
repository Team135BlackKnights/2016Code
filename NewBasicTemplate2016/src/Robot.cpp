#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"
#include "Subsystems/SerialCommunication.h"
#include "Commands/RunningOverDefense.h"

class Robot: public IterativeRobot
{
private:
	SendableChooser* sonarAndLightChooser;
	Command* sonarAndLightCommand;
	void RobotInit()
	{
		CommandBase::init();
		sonarAndLightChooser = new SendableChooser();
		sonarAndLightChooser->AddDefault("Both Sonars and Light", new RunningOverDefense(SerialCommunication::CASE_LEFT_RIGHT_AND_LIGHT));
		sonarAndLightChooser->AddObject("Right Sonar and Light", new RunningOverDefense(SerialCommunication::CASE_RIGHT_AND_LIGHT));
		sonarAndLightChooser->AddObject("Left Sonar and Light", new RunningOverDefense(SerialCommunication::CASE_LEFT_AND_LIGHT));
		sonarAndLightChooser->AddObject("Only Light", new RunningOverDefense(SerialCommunication::CASE_LIGHT));

		SmartDashboard::PutData("Sonars and Light Chooser", sonarAndLightChooser);
	}
	
	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void AutonomousInit()
	{
		sonarAndLightCommand = (Command*) sonarAndLightChooser->GetSelected();
		sonarAndLightCommand->Start();
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

