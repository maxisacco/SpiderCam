/*
 * stepperMotor.cpp
 *
 *  Created on: 05/11/2013
 *      Author: msacco
 */

#include "stepperMotor.h"

stepperMotor::~stepperMotor() {
	// TODO Auto-generated destructor stub
}

stepperMotor::stepperMotor(int ppv,int TTimer){
  tiempoTimer=TTimer;
  pasosPorVuelta=ppv;
  CorModo=1;
  reset();
}
void stepperMotor::run(void){
	  if (velocidad!=0){
	      if (frecCounter<=0) {
	        frecCounter=frecCounterMAX;
	        hacerPaso();
	      } else frecCounter-=1;
	  }
/*
	  if ((velocidad>0) && (cantidadPasos>0)){
	      if (frecCounter<=0) {
	        frecCounter=frecCounterMAX;
	        hacerPaso();
	        cantidadPasos-=1;
	      } else frecCounter-=1;
	  } else cantidadPasos=0; /// Porque esto??? Ademas habria que hacer algo para que gire constantemente
*/
}
void stepperMotor::hacerPaso(void){
    digitalWrite(PinSI,HIGH);
    delayMicroseconds(50);
    digitalWrite(PinSI,LOW);
}
int stepperMotor::getPasosXVuelta(void){
	return pasosPorVuelta;
}
void stepperMotor::reset(void){
  set_velocidad(0);
  frecCounter=0;
  frecCounterMAX=0;
  }
 void stepperMotor::pinAssign(int Dir, int SI, int OE, int HS, int OP){
   PinDir=Dir;
   PinSI=SI;
   PinOE=OE;
   PinHS=HS;
   PinOP=OP;
   pinMode(PinDir,OUTPUT);
   pinMode(PinSI,OUTPUT);
   pinMode(PinOE,OUTPUT);
   pinMode(PinHS,OUTPUT);
   pinMode(PinOP,OUTPUT);
  }
 void stepperMotor::set_velocidad(float valor){
	 	 velocidad=valor;
	 	 if (valor > 0.0) digitalWrite(PinDir,HIGH);
	 	 else digitalWrite(PinDir,LOW);
	 	 frecCounterMAX=(60000000/abs(velocidad))/(pasosPorVuelta*tiempoTimer*CorModo);} // esto hay que verlo..XXX
 float stepperMotor::get_velocidad(void){return velocidad;}
 void stepperMotor::conectar(void){
	 digitalWrite(PinOE,HIGH);
 }
 void stepperMotor::desconectar(void){
	 digitalWrite(PinOE,LOW);
 }

 void stepperMotor::set_Mode(int modo){
	 if (modo==0){ //Full Step
	 	 digitalWrite(PinHS,LOW);
	 	 digitalWrite(PinOP,LOW);
	 	 CorModo=1;
	 } else if (modo==1){ //Half Step
		 digitalWrite(PinHS,HIGH);
		 digitalWrite(PinOP,LOW);
	 	 CorModo=2;
	 }else { // Wave Mode
	 	 digitalWrite(PinHS,LOW);
	 	 digitalWrite(PinOP,HIGH);
	 	 CorModo=1;
	 }
	// set_velocidad(get_velocidad());
 }
