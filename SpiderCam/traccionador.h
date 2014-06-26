/*
 * traccionador.h
 *
 *  Created on: 05/12/2013
 *      Author: msacco
 */

#ifndef TRACCIONADOR_H_
#define TRACCIONADOR_H_
#include "stepperMotor.h"
#include "optoWheel.h"

class traccionador {
public:
	traccionador(stepperMotor &M, optoWheel &O, int TTimer, bool invDir);
	~traccionador();
	void run(void);
	void parar(void);
	void reset(void);
//	float getMmXtic() const;
	float getDistancia(void);
	void setDistancia(float dist);
//	void moverMM(float mili,float velocidad);
	void setVelocidad(float velocidad);
	float getVelocidad(void);

private:
	stepperMotor *motor;
	optoWheel *encoder;
	float distancia;
	float mmXtic;
	int tiempoTimer;
	bool inversorDir;

};

#endif /* TRACCIONADOR_H_ */
