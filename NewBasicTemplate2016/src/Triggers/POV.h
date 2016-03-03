#ifndef POV_H
#define POV_H

#include "WPILib.h"

class POV: public Trigger
{
public:
	POV();
	bool Get();
};

#endif
