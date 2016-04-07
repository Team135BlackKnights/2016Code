#include "SerialCommunication.h"
#include "../RobotMap.h"

SerialCommunication::SerialCommunication() :
		Subsystem("SerialCommunication")
{
	serialPort.reset(new SerialPort(9600, SerialPort::Port::kMXP));
	serialPort->Reset();
	serialPort->SetWriteBufferMode(SerialPort::WriteBufferMode::kFlushOnAccess);
	serialPort->SetWriteBufferSize(4);
}

void SerialCommunication::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void SerialCommunication::SendSerialShooterTrackerValue(double shooterTrackerValue) {
	int intShooterTrackerValue = ((int)(round(shooterTrackerValue)));
	std::string stringShooterTrackerValue = ((std::string)intShooterTrackerValue);
	serialPort->Write(stringShooterTrackerValue, BYTES_TO_WRITE);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
