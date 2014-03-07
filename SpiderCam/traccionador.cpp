/*
 * traccionador.cpp
 *
 *  Created on: 05/12/2013
 *      Author: msacco
 */

#include "traccionador.h"

traccionador::traccionador(stepperMotor *M, optoWheel *O, int TTimer) {
	motor = M;
	encoder= O;
	tiempoTimer=TTimer;
	distancia=0;
	mmXtic=encoder.get_mmPorVuelta() /encoder.get_dientesPorVuelta();
}

traccionador::~traccionador() {
	// TODO Auto-generated destructor stub
}


float traccionador::getMmXtic() const {
	return mmXtic;
}

void traccionador::parar(void){
	motor.set_velocidad(0);
}
float traccionador::getDistancia(void){
	return mmXtic*encoder.get_posAbsPasos();
}
void traccionador::setDistancia(float dist,float velocidad){
	moverMM(dist-distancia,velocidad);
}
void traccionador::moverMM(float mili,float velocidad){

	int tics = mili / mmXtic;
	if (tics<0) motor.set_velocidad(velocidad*-1);
	else motor.set_velocidad(velocidad);
// Calcular la nueva poscicion del enconder.

}
void traccionador::mover(float velocidad){
	motor.set_velocidad(velocidad);
}

void traccionador::run(void){
	motor.run();
	encoder.run();
	if ((wishPos!=0 ) and (wishPos==encoder.get_posAbsPasos())){
		motor.set_velocidad(0);
		wishPos=0;
	}
}
