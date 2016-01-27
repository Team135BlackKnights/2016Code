#include <RobotMap.h>
#include <math.h>
#include <Subsystems/AxisCamera.h>

AxisCamera::AxisCamera():
		Subsystem("AxisCamera")
{
	//grip.reset(NetworkTable::GetTable("grip").get());
	visionTable = NetworkTable::GetTable("SmartDashboard");
	height = 0;
	width = 0;
	x = 0;
	y = 0;
	yServo = new Servo(SERVO_PORT_Y);
	xServo = new Servo(SERVO_PORT_X);
}

void AxisCamera::InitDefaultCommand()
{
	//set the cam quality of jpeg to be around 50 (out of 100)
	//CameraServer::GetInstance()->SetQuality(50);
	//Start the automatic capture to dashboard
	//CameraServer::GetInstance()->StartAutomaticCapture(CAMERA_NAME);
	SetDefaultCommand(new CameraTracking());
}


void AxisCamera::GetCameraValues()
{
	//visionTable->
	auto xys = visionTable->GetNumberArray("BLOB_XY", llvm::ArrayRef<double>());
	if(xys.size() > 2 || xys.size() == 0)
		return;
	x = xys[0];
	y = xys[1];

	std::cout << "x: " << x << std::endl;
	std::cout << "y: " << y << std::endl;
}

double AxisCamera::xDistanceToCenter()
{
	return x - X_IMAGE_RES /2;
}

double AxisCamera::yDistanceToCenter()
{
	return y - Y_IMAGE_RES/2;
}

double AxisCamera::percentArea(double area)
{
	return area/(X_IMAGE_RES*Y_IMAGE_RES);
}

double AxisCamera::getWidth()
{
	return width;
}

double AxisCamera::getHeight()
{
	return height;
}

double AxisCamera::getX()
{
	return x;
}

double AxisCamera::getY()
{
	return y;
}
double AxisCamera::distanceToBlob(double pixel_width)
{
	return X_WIDTH_GOAL * X_IMAGE_RES / (2*pixel_width * tan(AXIS_VANGLE / 2));
}

void AxisCamera::setServoY()
{
	double offset = yDistanceToCenter();
	if(offset <= -5)
		yServo->Set(yServo->Get() + .005f);
	else if(offset >= 5)
		yServo->Set(yServo->Get() - .005f);
}

void AxisCamera::setServoX()
{
	double offset = xDistanceToCenter();
	if(offset <= -5)
		xServo->Set(xServo->Get() + .005f);
	else if(offset >= 5)
		xServo->Set(xServo->Get() - .005f);
}
