/*
 * optoWheel.h
 *
 *  Created on: 08/11/2013
 *      Author: msacco
 */

#include "optoWheel.h"
#define ULMAX 4294967295

optoWheel::optoWheel(int dpv, float mmXv){
	dientesPorVuelta=dpv;
	milimetrosPorVuelta=mmXv;
	reset();
};
optoWheel::~optoWheel(){};
void optoWheel::reset(void){
//	marcaPosRelativa=0;
	tiempoAnt=0;
	posAbsPasos=0;
	lastDireccion=0;
	deltaT=0;
	velocidadInst=0;
//	velocidadPP=0;
};
void optoWheel::pinAssign(int encA, int encB){
	PinA=encA;
	PinB=encB;
};
int optoWheel::get_posAbsPasos(void){return posAbsPasos;};
int optoWheel::get_direccionAct(void){return lastDireccion;};
//int optoWheel::get_PosRelativa(void){
//	int res=posAbsPasos-marcaPosRelativa; ///esto eventualmente dra negativo por overflow en posAbsPasos
//	marcaPosRelativa=posAbsPasos;
//	return res;
//};
//void optoWheel::resetPosRelativa(void){};
//void optoWheel::set_posAbsPasos(int valor){posAbsPasos=valor;};
void optoWheel::set_dirInversion(bool valor){InvDir=valor;};
int optoWheel::get_dientesPorVuelta(void){return dientesPorVuelta;};
void optoWheel::run(void){
	int n = digitalRead(PinA);
	unsigned long tiempoAct=micros();
	unsigned long dt;
	if (tiempoAnt < tiempoAct) dt=tiempoAct-tiempoAnt;
	else dt=(ULMAX-tiempoAnt)+tiempoAct;

	if ((PinALast == LOW) && (n == HIGH)) {
		if (digitalRead(PinB) == LOW)  {
			posAbsPasos--;
			lastDireccion=(0 xor InvDir);
		} else {
	    	posAbsPasos++;
	    	lastDireccion=(1 xor InvDir);
	    }
		deltaT=dt;
		velocidadInst=60000000.0/(deltaT*dientesPorVuelta);
//		velocidadPP=(velocidadPP+velocidadInst)/2.0;		// esto hay que mirarlo con mas detenimiento. . . .y definir un comportamiento deseado
		tiempoAnt=tiempoAct;
	}
	PinALast = n;
	if (dt>deltaT && deltaT!=0) 	velocidadInst=60000000.0/(dt*dientesPorVuelta);
};

float optoWheel::get_velocidadInst(void){return velocidadInst;};
//float optoWheel::get_velocidadPP(void){return velocidadPP;};
//float optoWheel::get_mmPorVuelta(void){return milimetrosPorVuelta;};
