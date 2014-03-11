/*
 * comunicador.cpp
 *
 *  Created on: 11/03/2014
 *      Author: msacco
 */

#include "comunicador.h"

comunicador::comunicador() {
	// TODO Auto-generated constructor stub
	orden='U';
	velocidad=0;
	distancia=0;
}

comunicador::~comunicador() {
	// TODO Auto-generated destructor stub
}

bool comunicador::recibirOrden(void){
	if (Serial.available() > 0) {
		parser();
		return true;
	}
	return false;
}
void comunicador::enviarData(char & buffer )const{
	Serial.write(buffer);
}


bool  comunicador::conectar(int baudios){
	Serial.begin(baudios);
	return Serial;
}
void comunicador::parser(void){
	switch ((char) Serial.read()) {
	case 'V':
		orden='V';
		velocidad=Serial.parseFloat();
		break;
	case 'E':
		orden='E';
		distancia=Serial.parseFloat();
		velocidad=Serial.parseFloat();
		break;
	case 'I':
		orden='I';
		distancia=-1;
		velocidad=-1;
		break;
	case 'S':
		orden='S';
		distancia=-1;
		velocidad=-1;
		break;
	case 'R':
		orden='R';
		distancia=-1;
		velocidad=-1;
		break;
	default:
		orden='U';
		distancia=-1;
		velocidad=-1;
	}
}
void comunicador::loop(void){}
