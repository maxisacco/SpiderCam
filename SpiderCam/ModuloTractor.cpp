// Do not remove the include below
//#include <arduino.h>
#include "ModuloTractor.h"
#include "stepperMotor.h"
#include "comunicador.h"
#include "traccionador.h"
#include <TimerOne.h>


#define PASOSXVUELTA 42   //Stepper
#define MAXVELRPM 300     //Stepper
#define TICSXVUELTA 48    //Opto
#define MMXVUELTA 6.28   //Opto
#define TIEMPOUS  100     //tiempo en us de atencion de iterrupcion
#define INVERSORDIR false  //invierte la direccion del valor de velocidad +-
comunicador enlace;
stepperMotor motor(MAXVELRPM,PASOSXVUELTA,TIEMPOUS);
optoWheel encoder(TICSXVUELTA,MMXVUELTA);
traccionador actuador(motor,encoder,TIEMPOUS,false);

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
	actuador.setVelocidad(enlace.velocidad);
	Serial.print("Velocidad:");
	Serial.println(actuador.getVelocidad());
	Serial.print("Distancia:");
	Serial.println(actuador.getDistancia());
//	Serial.println(motor.get_cantidadPasos());
	delay(500);
}

void run(){
	actuador.run();
}
