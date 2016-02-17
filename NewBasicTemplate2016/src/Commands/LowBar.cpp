#include "LowBar.h"
#include "AutonomousDrive.h"

LowBar::LowBar()
{
	AddSequential(new AutonomousDrive(0,0,AutonomousDrive::MODE::TIME,0,0)); //Add Parameters here
	//AddSequential(new CameraTracking());
	//AddSequential(new Shoot());
}
