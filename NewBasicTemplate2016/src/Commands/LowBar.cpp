#include "LowBar.h"
#include "AutonomousDrive.h"

LowBar::LowBar()
{
	AddSequential(new AutonomousDrive(.7f,.7f,AutonomousDrive::MODE::TIME,10,0)); //Add Parameters here
	//AddSequential(new AimBot());
}
