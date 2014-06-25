/*
 * comunicador.h
 *
 *  Created on: 11/03/2014
 *      Author: msacco
 */

#ifndef COMUNICADOR_H_
#define COMUNICADOR_H_
#include <HardwareSerial.h>


class comunicador {


public:
	char orden;
	float velocidad, distancia;
	comunicador();
	~comunicador();
	bool recibirOrden(void);
	void enviarData(char & buffer) const;
	bool conectar(int baudios);
	float parser(void);
	void loop(void);
};

#endif /* COMUNICADOR_H_ */
