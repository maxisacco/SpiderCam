/*
 * traccionador.cpp
 *
 *  Created on: 05/12/2013
 *      Author: msacco
 */

#include "traccionador.h"

traccionador::traccionador(stepperMotor  &M, optoWheel  &O, int TTimer, bool invDir) {
	motor = &M;
	encoder = &O;
	tiempoTimer=TTimer;
	distancia=0;
	mmXtic=encoder->get_mmPorVuelta() /encoder->get_dientesPorVuelta();
	inversorDir=invDir;
}

traccionador::~traccionador() {
	// TODO Auto-generated destructor stub
}


void traccionador::parar(void){
	motor->set_velocidad(0);
}
float traccionador::getDistancia(void){
	return mmXtic*encoder->get_posAbsPasos();
}

void traccionador::setVelocidad(float velocidad){
	if (velocidad == 0.0) {
		motor->set_velocidad(0);
	} else if (velocidad > 0.0) {
			motor->set_velocidad(velocidad);
			motor->set_direccion(!inversorDir);
	} else {
		motor->set_velocidad(abs(velocidad));
		motor->set_direccion(inversorDir);
	}
}
float traccionador::getVelocidad(void){
	float velo= motor->get_velocidad();
	if (motor->get_direccion() xor inversorDir)
		return velo;
	else
		return -velo;
}

void traccionador::run(void){
	motor->run();
	encoder->run();
}
