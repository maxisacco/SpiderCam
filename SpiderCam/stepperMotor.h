/*
 * stepperMotor.h
 *
 *  Created on: 05/11/2013
 *      Author: msacco
 */

#ifndef STEPPERMOTOR_H_
#define STEPPERMOTOR_H_
#ifndef ARDUINO_H_
#define ARDUINO_H_
#include "Arduino.h"
#endif //ARDUINO_H_

class stepperMotor {
public:
  stepperMotor(int ppv, int TTimer);
  virtual ~stepperMotor();
  void reset(void);
  void pinAssign(int Dir, int SI, int OE, int HS, int OP);
  float get_velocidad(void);
  void set_velocidad(float valor);
  void run(void);
  void set_Mode(int);
  int getPasosXVuelta(void);
  void conectar(void);
  void desconectar(void);

private:
  int PinDir,PinSI,PinOE,PinHS,PinOP;
  int tiempoTimer; //tiempo en microsegundos de atencion interrupcion del timer
  int pasosPorVuelta;
  float velocidad; // en RPMs
  int frecCounter; // divisor del Timer para activar el paso.
  int frecCounterMAX; // divisor del Timer para activar el paso.
  int CorModo; // variavle de correccion de pasos por vuelta para fullsetp y halfstep
  void hacerPaso(void);

};

#endif /* STEPPERMOTOR_H_ */
