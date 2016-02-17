#ifndef Collection_H
#define Collection_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Collection: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std::unique_ptr<VictorSP> collectionMotor;
public:
	Collection();
	void InitDefaultCommand();
	void PowerCollection(double);

	static const int IN = 1;
	static const int OUT = -IN;
};

#endif
