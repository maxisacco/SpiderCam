// Do not remove the include below
//#include <arduino.h>
#include "ModuloTractor.h"
#include "stepperMotor.h"
#include "comunicador.h"
#include "traccionador.h"
#include <TimerOne.h>


#define PASOSXVUELTA 42   //Stepper
#define TICSXVUELTA 48    //Opto
#define MMXVUELTA 12.56   //Opto
#define TIEMPOUS  100     //tiempo en us de atencion de iterrupcion

//SoftwareSerial Serial;
//	TimerOne Timer2;
	comunicador enlace;
	stepperMotor motor(PASOSXVUELTA,1);
	optoWheel encoder(TICSXVUELTA,MMXVUELTA);
	traccionador actuador(motor,encoder,TIEMPOUS);

//The setup function is called once at startup of the sketch
void setup()
{

	Timer1.initialize(10);
	Timer1.attachInterrupt(run,TIEMPOUS);
	enlace.conectar(9600);
	motor.pinAssign(2,3,4,5,6);
	motor.reset();
	motor.set_velocidad(0);
	Serial.println("estoy inicializando");
}

// The loop function is called in an endless loop
void loop()
{
	enlace.recibirOrden();
	Serial.print("Velocidad:");
	Serial.println(enlace.velocidad);
	Serial.print("Distancia:");
	Serial.println(enlace.distancia);
//	Serial.println(motor.get_cantidadPasos());
	delay(500);
}

void run(){
	// motor.run();

}
