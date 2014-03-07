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
	traccionador(stepperMotor *m1, optoWheel *w1, int TTimer);
	~traccionador();
	void run(void);
	void parar(void);
	void reset(void);
	float getMmXtic() const;
	float getDistancia(void);
	void setDistancia(float dist,float velocidad);
	void moverMM(float mili,float velocidad);
	void mover(float velocidad);


private:
	stepperMotor motor;
	optoWheel encoder;
	float distancia;
	float mmXtic;
	int tiempoTimer;
	long wishPos;

};

#endif /* TRACCIONADOR_H_ */
