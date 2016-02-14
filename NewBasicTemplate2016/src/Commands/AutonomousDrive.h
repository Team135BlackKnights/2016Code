#ifndef AutonomousDrive_H
#define AutonomousDrive_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutonomousDrive: public CommandBase
{
public:

	enum MODE {
		TIME = 0,
		DISTANCE = 1,
		DEFENSE = 3
	};

	enum DEFAULT {
		D_SPEED = 0f,
		D_TIME = 0,
		D_DISTANCE = 0
	};



	AutonomousDrive(float, float, MODE, int, float);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	Timer* timer;
	float left, right;
	int driveMode, time, crookedDirection;
	bool overDefense;

	static constexpr float CROOKED_ADJUST = .9f;

};

#endif
