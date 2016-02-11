#ifndef Autonomous_H
#define Autonomous_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"

class Autonomous: public CommandGroup
{
	const int NOTHING = 0;
	const int LOW_BAR = 1;
	const int CHEVAL_DE_FRISE = 2;
	const int DRAWBRIDGE = 3;
	const int SALLY_PORT = 4;
	const int PORTCULLIS = 5;

public:
	Autonomous(int);
};

#endif
