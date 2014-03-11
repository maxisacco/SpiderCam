/*
 * comunicador.h
 *
 *  Created on: 11/03/2014
 *      Author: msacco
 */

#ifndef COMUNICADOR_H_
#define COMUNICADOR_H_

class comunicador {
	char orden;
	float velocidad, distancia;
public:
	comunicador();
	~comunicador();
	bool recibirOrden(void);
	void enviarData(char & buffer) const;
	bool conectar(int baudios);
	void parser(void);
	void loop(void);
};

#endif /* COMUNICADOR_H_ */
