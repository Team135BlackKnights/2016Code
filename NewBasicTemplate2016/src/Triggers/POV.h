#ifndef POV_H
#define POV_H

#include "WPILib.h"


//typedef int (*Func)(int);

class POV: public Trigger
{
private:
	int joystick;
	int pov;
public:
	POV(const int&, int);
	bool Get();
};

#endif
