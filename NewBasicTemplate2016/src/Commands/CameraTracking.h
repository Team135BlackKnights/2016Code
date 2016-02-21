#ifndef CameraTracking_H
#define CameraTracking_H

#include "../CommandBase.h"
#include "WPILib.h"

class CameraTracking: public CommandBase
{
public:
	CameraTracking();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
