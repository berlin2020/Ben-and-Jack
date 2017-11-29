#pragma config(Sensor, S1,     distance,       sensorEV3_Ultrasonic)
#pragma config(Sensor, S4,     color,          sensorEV3_Color, modeEV3Color_Color)
#pragma config(Motor,  motorA,          left,          tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorD,          right,         tmotorEV3_Large, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

int gState = 1;

void gState0()
{
}

void gState1()
{
	int leftBack;
	int rightBack;
	int goBack = 0;

	while((SensorValue(color) != colorYellow) && (goBack == 0))
	{
		motor(left) = 30;
		motor(right) = 30;
	}
	if((SensorValue(color) = colorYellow) && (goBack == 0))
	{
		goBack = 1;
		motor(left) = 0;
		motor(right) = 0;
		//pick up block
		leftBack = getMotorEncoder(left);
		rightBack = getMotorEncoder(right);
		resetMotorEncoder(left);
		resetMotorEncoder(right);
	}
	while((getMotorEncoder(left) > -leftBack) && (getMotorEncoder(right) > -rightBack))
	{
		motor(left) = -30;
		motor(right) = -30;
	}

	//drop block

	gState = 2;

}

void gState2()
{
	motor(left) = 0;
	motor(right) = 0;
}

void gState3()
{
}

task main()
{

	//use methods for each gState

	while(gState == 0)
	{
		//position robot to travel to block a (assuming extra 4 pts for inital position)
	}

	resetMotorEncoder(left);
	resetMotorEncoder(right);

	while(gState == 1)
	{
		gState1();
		//travel to block a
		//retrieve block a
	}

	while(gState == 2)
	{
		gState2()
		//travel to block f
		//retrieve block f
	}

	while(gState == 3)
	{
		//return blacok f
	}

	while(gState == 4)
	{
		//game end
	}

}
