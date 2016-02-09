/*
 * ServoPID.cpp
 *
 *  Created on: Feb 9, 2016
 *      Author: ROBOTICS
 */

#include <Subsystems/ServoPID.h>

ServoPID::ServoPID(Servo* servo) {
	// TODO Auto-generated constructor stub
	this->servo = servo;
}

ServoPID::~ServoPID() {
	// TODO Auto-generated de_structor stub
}


double ServoPID::PIDGet()
{
	return (double) servo->Get();
}
void ServoPID::PIDWrite(float output)
{
	/*"*/servo->Set(servo->Get() + output); /*... don't quote me on that" - eddie atkinson*/
}
