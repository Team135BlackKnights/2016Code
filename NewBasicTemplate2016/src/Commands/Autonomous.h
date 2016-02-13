#ifndef Autonomous_H
#define Autonomous_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"

class Autonomous: public CommandGroup
{
	enum DEFENSE {
		NOTHING = 0,
		LOW_BAR = 1,
		CHEVAL_DE_FRISE = 2,
		DRAWBRIDGE = 3,
		SALLY_PORT = 4,
		PORTCULLIS = 5
	};

public:
	Autonomous(int);
};

#endif
