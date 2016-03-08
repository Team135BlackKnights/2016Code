/*
 * ServoPID.h
 *
 *  Created on: Feb 9, 2016
 *      Author: ROBOTICS
 */

#ifndef SRC_SUBSYSTEMS_SERVOPID_H_
#define SRC_SUBSYSTEMS_SERVOPID_H_

#include "WPILib.h"

class ServoPID : public PIDSource, public PIDOutput {
private:
	Servo* servo;
public:
	ServoPID(Servo* servo);
	virtual ~ServoPID();

	double PIDGet();
	void PIDWrite(float output);
};

#endif /* SRC_SUBSYSTEMS_SERVOPID_H_ */
