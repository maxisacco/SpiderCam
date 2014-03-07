// Do not remove the include below
#include "SpiderCam.h"
#include "stepperMotor.h"
#include <TimerOne.h>

stepperMotor motor(100,1);
TimerOne Timer1;


//The setup function is called once at startup of the sketch
void setup()
{

	Serial.begin (9600);
	motor.pinAssign(2,3,4,5,6);
	motor.reset();
	Timer1.initialize(100);
	Timer1.attachInterrupt(run,1000);
	motor.set_velocidad(10);
	Serial.println("estoy inicializando");
}

// The loop function is called in an endless loop
void loop()
{
	Serial.print("esto es el loop --- Pasos=");
//	Serial.println(motor.get_cantidadPasos());
	delay(500);
}

void run(){
	 motor.run();

}
