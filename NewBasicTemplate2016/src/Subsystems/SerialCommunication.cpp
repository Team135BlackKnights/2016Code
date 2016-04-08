#include "SerialCommunication.h"
#include "../RobotMap.h"

SerialCommunication::SerialCommunication() :
		Subsystem("SerialCommunication")
{
	serialPort.reset(new SerialPort(9600, SerialPort::Port::kUSB));
	// Idea: Comment out serialPort->Reset()
	serialPort->Reset();
	serialPort->SetWriteBufferMode(SerialPort::WriteBufferMode::kFlushOnAccess);
	serialPort->SetWriteBufferSize(16);
	serialPort->SetTimeout(10);

	bytesToWrite = 0;
	//buffer = new char('\a');
}

void SerialCommunication::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void SerialCommunication::SendSerialShooterTrackerValue(double shooterTrackerValue) {
	int intShooterTrackerValue = ((int)(round(shooterTrackerValue)));
	bytesToWrite = (intShooterTrackerValue >= 100) ? 3 : 2;
	std::string stringShooterTrackerValue = std::to_string(intShooterTrackerValue);
	serialPort->Write("S", 1);
	serialPort->Write(stringShooterTrackerValue, 8);
	serialPort->Write(".", 1);
	serialPort->Flush();
}

void SerialCommunication::SendSonarDistanceValue(float sonarDistanceValue) {
	int intSonarDistanceValue = ((int)(round(sonarDistanceValue)));
	bytesToWrite = (intSonarDistanceValue >= 100) ? 3 : 2;
	std::string stringSonarDistanceValue = std::to_string(intSonarDistanceValue);
	//serialPort->Write("A", 1);
	//serialPort->Write(stringSonarDistanceValue, bytesToWrite);
	//serialPort->Write(".", 1);
	serialPort->Write("hello", 10);
	//serialPort->Flush();
	//std::cout << "Workinggggggggggggggggggg" << std::endl;
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
