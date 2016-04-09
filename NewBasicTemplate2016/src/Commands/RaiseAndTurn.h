#ifndef RaiseAndTurn_H
#define RaiseAndTurn_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"

class RaiseAndTurn: public CommandGroup
{
public:
	RaiseAndTurn(double height, double deg, bool dir);
};

#endif
