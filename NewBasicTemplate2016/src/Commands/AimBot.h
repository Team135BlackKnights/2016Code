#ifndef AimBot_H
#define AimBot_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"

class AimBot: public CommandGroup
{
public:
	AimBot(int = 1.0D, bool = true);
};

#endif
