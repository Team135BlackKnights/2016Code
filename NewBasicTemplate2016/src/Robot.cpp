#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"
#include "Commands/DriveJ.h"
#include "Commands/CameraTracking.h"
#include "Commands/MoveFromCameraValue.h"
class Robot: public IterativeRobot
{
public:

private:
	void RobotInit()
	{
		SmartDashboard::PutData("DriveJ", new DriveJ());
		SmartDashboard::PutData("Camera Trucking", new CameraTracking());
		SmartDashboard::PutData((std::string)"MoveFromCameraValue", new MoveFromCameraValue());
		CommandBase::init();
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

