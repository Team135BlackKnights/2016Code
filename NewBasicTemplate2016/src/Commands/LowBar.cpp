#include "LowBar.h"
#include "AutonomousDrive.h"

LowBar::LowBar()
{

	AddSequential(new AutonomousDrive()); //Add Parameters here
	//AddSequential(new CameraTracking());
	//AddSequential(new Shoot());
}
