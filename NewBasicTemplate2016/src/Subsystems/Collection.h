#ifndef Collection_H
#define Collection_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Collection: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Collection();
	void InitDefaultCommand();
};

#endif
