#ifndef Autonomous_H
#define Autonomous_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"

class Autonomous: public CommandGroup
{
	const int NOTHING = 0;
	const int LOWBAR = 1;
	const int CHEVALDEFRISE = 2;
	const int DRAWBRIDGE = 3;
	const int SALLYPORT = 4;
	const int PORTCULLIS = 5;

public:
	Autonomous(int);
};

#endif
