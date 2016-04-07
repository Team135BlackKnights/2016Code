#include "SerialCommunication.h"
#include "../RobotMap.h"

SerialCommunication::SerialCommunication() :
		Subsystem("SerialCommunication")
{
	serialPort.reset(new SerialPort(9600, SerialPort::Port::kMXP));
	serialPort->Reset();
	serialPort->SetWriteBufferMode(SerialPort::WriteBufferMode::kFlushWhenFull);
	serialPort->SetWriteBufferSize(10);
	serialPort->SetTimeout(10.0f);

	bytesToWrite = 0;
}

void SerialCommunication::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void SerialCommunication::SendSerialShooterTrackerValue(double shooterTrackerValue) {
	int intShooterTrackerValue = ((int)(round(shooterTrackerValue)));
	bytesToWrite = (intShooterTrackerValue >= 100) ? 3 : 2;
	std::string stringShooterTrackerValue = ((std::string)intShooterTrackerValue);
	serialPort->Write("S", 1);
	serialPort->Write(stringShooterTrackerValue, bytesToWrite);
	serialPort->Write(".", 1);
	serialPort->Flush();
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
