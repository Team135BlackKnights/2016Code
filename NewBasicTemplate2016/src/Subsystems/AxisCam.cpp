#include <Commands/CameraTracking.h>
#include <llvm/ArrayRef.h>
#include <math.h>
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
	yServo.reset(new Servo(SERVO_PORT_Y));
	xServo.reset(new Servo(SERVO_PORT_X));
	//InitGimbals();
}

void AxisCam::InitDefaultCommand()
{
	//set the cam quality of jpeg to be around 50 (out of 100)
	//CameraServer::GetInstance()->SetQuality(50);
	//Start the automatic capture to dashboard
	//CameraServer::GetInstance()->StartAutomaticCapture(CAMERA_NAME);
	xServo->Set(.5f);
	yServo->Set(.1f);
	SetDefaultCommand(new CameraTracking());
}

void AxisCam::InitGimbals()
{

	pan.position = CAMERA_CENTER_X;
	pan.proportional_gain = PAN_PROPORTIONAL_GAIN;
	pan.previous_error = 0x80000000L;
	pan.derivative_gain = PAN_DERIVATIVE_GAIN;

	tilt.position = CAMERA_CENTER_Y;
	tilt.derivative_gain = TILT_DERIVATIVE_GAIN;
	tilt.previous_error = 0x80000000L;
	tilt.proportional_gain = TILT_PROPORTIONAL_GAIN;
}

void AxisCam::UpdateGimbal(struct Gimbal * gimbal, int32_t error)
{
	long int velocity;
	int32_t error_delta;
	int32_t P_gain;
	int32_t D_gain;
	int32_t newPosMax =  CAMERA_CENTER_X + Preferences::GetInstance()->GetInt("WiggleRoom", 5);
	int32_t newPosMin =  CAMERA_CENTER_X - Preferences::GetInstance()->GetInt("WiggleRoom", 5);
	if(gimbal->previous_error != 0x80000000L) {
		error_delta = error - gimbal->previous_error;
		P_gain = gimbal->proportional_gain;
		D_gain = gimbal->derivative_gain;

		velocity = (error * P_gain + error_delta * D_gain) >> 10;

		gimbal->position += velocity;

		if(gimbal->position > newPosMax)
			gimbal->position = newPosMax;//could be error
		else if(gimbal->position < newPosMin)
			gimbal->position = newPosMin;
	}
	gimbal->previous_error = error;
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
		return;
	}

	width = shapes[4] - shapes[3];
	height = shapes[6] - shapes[5];
	x = width / 2 + shapes[3];
	y = height / 2 + shapes[5];
	std::cout << "x: " << x << std::endl;
	std::cout << "y: " << y << std::endl;
	std::cout << "Width: " << width << std::endl;
	std::cout << "Height: " << height << std::endl;
}

float AxisCam::xDistanceToCenter()
{
	if(x == 666)
		return 666;
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

void AxisCam::setServoY()
{
	float offset = yDistanceToCenter();
	float value = yServo->Get();
	if (offset == 666)
		return;
	if(offset <= -Preferences::GetInstance()->GetInt("WiggleRoom", 5))
		value -= .001f + GetYMultiplier(offset);
	else if(offset >= Preferences::GetInstance()->GetInt("WiggleRoom", 5))
		value += .001f + GetYMultiplier(offset);
	//value = fmin(fmax(value,.99f),.01f);
	yServo->Set(value);
}

void AxisCam::setServoX()
{
	float offset = xDistanceToCenter();
	float value = xServo->Get();
	if (offset == 666)
		return;
	if(offset <= -Preferences::GetInstance()->GetInt("WiggleRoom", 5))
		value -= .001f + GetXMultiplier(offset);
	else if(offset >= Preferences::GetInstance()->GetInt("WiggleRoom", 5))
		value += .001f + GetXMultiplier(offset);
	//value = fmin(fmax(value,.01f),.99f);
	std::cout << "SETTING VALUE TO " << value << std::endl;
	xServo->Set(value);
}

void AxisCam::SetServoY(int32_t value)
{
	SetServo(yServo.get(), value);
}

void AxisCam::setServoX(int32_t value) {
	this->SetServo(xServo.get(), value);
}

void AxisCam::SetServo(Servo* servo, float value)
{
	servo->Set(value);
}

float AxisCam::angleToBlob(double dist){
	return atan((X_WIDTH_GOAL / 2) / dist) * 180 / M_PI;
}

void AxisCam::Update()
{
	int pan_error;
	int tilt_error;

	pan_error = X_IMAGE_RES /2 - x;
	tilt_error = y - Y_IMAGE_RES / 2;

	UpdateGimbal(&pan, pan_error);
	UpdateGimbal(&tilt, tilt_error);

	setServoX(pan.position);
	SetServoY(tilt.position);

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
	return offset * .2;
}

float AxisCam::GetYMultiplier(float offset)
{
	return offset * .2;
}
