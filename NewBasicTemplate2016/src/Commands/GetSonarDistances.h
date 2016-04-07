#ifndef GetSonarDistances_H
#define GetSonarDistances_H

#include "../CommandBase.h"
#include "WPILib.h"

class GetSonarDistances: public CommandBase
{
private:
	float leftSonarDistance = 0.0f,
		  rightSonarDistance = 0.0f;

	std::unique_ptr<Timer> timer;
public:
	GetSonarDistances();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
