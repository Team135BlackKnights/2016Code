#include <Commands/CameraTracking.h>
#include <llvm/ArrayRef.h>
#include <math.h>
#include <Preferences.h>
#include <Servo.h>
#include <Subsystems/AxisCam.h>
#include <iostream>
#include <vector>

AxisCam::AxisCam():
		Subsystem("AxisCam")
{
	//grip.reset(NetworkTable::GetTable("grip").get());
	visionTable = NetworkTable::GetTable("SmartDashboard");
	height = 0;
	width = 0;
	x = 0;
	y = 0;
	//yServo.reset(new Servo(SERVO_PORT_Y));
	xServo.reset(new Servo(SERVO_PORT_X));
	pidServoX = new ServoPID(xServo.get());
	pidX = new PIDController(Preferences::GetInstance()->GetFloat("P", .01), 0.0f, 0.0f,
		   pidServoX, pidServoX);
	pidX->SetSetpoint(.5);
	//pidX->SetInputRange(0,1);
	//pidX->SetOutputRange(-1,1);
}

void AxisCam::InitDefaultCommand()
{
	//set the cam quality of jpeg to be around 50 (out of 100)
	//CameraServer::GetInstance()->SetQuality(50);
	//Start the automatic capture to dashboard
	//CameraServer::GetInstance()->StartAutomaticCapture(CAMERA_NAME);
	pidX->SetContinuous(true);
	pidX->Enable();
	//yServo->Set(.2f);
	SetDefaultCommand(new CameraTracking());
}


void AxisCam::GetCameraValues()
{
	//visionTable->
	auto shapes = visionTable->GetNumberArray("SHAPES", llvm::ArrayRef<double>());

	if(shapes.size() == 0)
	{
		x = 666;
		y = 666;
		width = 666;
		height = 666;
		pidX->Disable();
		return;
	}

	width = shapes[4] - shapes[3];
	height = shapes[6] - shapes[5];
	x = width / 2 + shapes[3];
	y = height / 2 + shapes[5];
	pidX->Enable();
	/*std::cout << "x: " << x << std::endl;
	std::cout << "y: " << y << std::endl;
	std::cout << "Width: " << width << std::endl;
	std::cout << "Height: " << height << std::endl;*/
}

float AxisCam::xDistanceToCenter()
{
	if(x == 666)
		return 0;
	//return Preferences::GetInstance()->GetFloat("Offset", 0);
	return x - X_IMAGE_RES /2;
}

float AxisCam::yDistanceToCenter()
{
	if(y == 666)
			return 666;
	return y - Y_IMAGE_RES/2;
}

float AxisCam::percentArea(double area)
{
	return area/(X_IMAGE_RES*Y_IMAGE_RES);
}

float AxisCam::getWidth()
{
	return width;
}

float AxisCam::getHeight()
{
	return height;
}
float AxisCam::getX()
{
	return x;
}

float AxisCam::getY()
{
	return y;
}
float AxisCam::distanceToBlob(double pixel_width)
{
	return (X_WIDTH_GOAL * X_IMAGE_RES) / ((2*pixel_width * (tan((AXIS_VANGLE / 2.0)/ 180.0 * M_PI))));
}

/*void AxisCam::setServoY()
{
	float offset = yDistanceToCenter();
	float value = yServo->Get();
	if (offset == 666)
		return;
	if(offset <= -Preferences::GetInstance()->GetInt("WiggleRoom", 5))
		value -= .001f;// + GetYMultiplier(offset);
	else if(offset >= Preferences::GetInstance()->GetInt("WiggleRoom", 5))
		value += .001f;// + GetYMultiplier(offset);
	//value = fmin(fmax(value,.99f),.01f);
	yServo->Set(value);
}*/

void AxisCam::setServoX()
{
	float offset = xDistanceToCenter();
	float value = xServo->Get();
	if (offset == 666)
		return;
	if(offset <= -Preferences::GetInstance()->GetInt("WiggleRoom", 5))
		value += (GetXMultiplier(offset));
	else if(offset >= Preferences::GetInstance()->GetInt("WiggleRoom", 5))
		value += (GetXMultiplier(offset));
	//value = fmin(fmax(value,.01f),.99f);
	std::cout << "SETTING VALUE TO " << value << std::endl;
	xServo->Set(value);
}

/*void AxisCam::SetServoY(float value)
{
	SetServo(yServo.get(), value);
}*/

void AxisCam::setServoX(float value) {
	this->SetServo(xServo.get(), value);
}

void AxisCam::SetServo(Servo* servo, float value)
{
	servo->Set(value);
}

float AxisCam::angleToBlob(double dist){
	return atan((X_WIDTH_GOAL / 2) / dist) * 180 / M_PI;
}

float AxisCam::GetMotorValues()
{
	float MAX = 1;
	float MIN = 0;
	float MIDDLE = .5;
	float angle = xServo->Get();
	return  (MIDDLE - angle);

}

float AxisCam::GetXMultiplier(float offset)
{
	return (offset / (X_IMAGE_RES / 2.0f))/Preferences::GetInstance()->GetFloat("P", 100.0f);
}

float AxisCam::GetYMultiplier(float offset)
{
	return (offset / ( Y_IMAGE_RES / 2.0f))/Preferences::GetInstance()->GetFloat("P", 100.0f);
}

void AxisCam::UpdateServo()
{
	if(pidX->IsEnabled())
	{
		float setpoint = xServo->Get() + (.2 * (xDistanceToCenter() / (X_IMAGE_RES / 2)));
		std::cout << setpoint << std::endl;
		pidX->SetSetpoint(setpoint);
	}
	else
	{
		Scan(xServo.get());
	}
}

void AxisCam::TogglePID(bool toggle) {
	if (toggle)
		pidX->Enable();
	else
		pidX->Disable();
}

void AxisCam::Scan(Servo* servo)
{
	if(servo->Get() <= 0 || servo->Get() >= 1)
		searchSize = -searchSize;
	servo->Set(servo->Get() + searchSize);
}
