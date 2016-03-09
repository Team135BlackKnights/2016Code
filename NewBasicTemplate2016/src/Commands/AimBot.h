#ifndef AimBot_H
#define AimBot_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"

class AimBot: public CommandGroup
{
public:
	AimBot(double angle=-1.0D);
};

#endif
