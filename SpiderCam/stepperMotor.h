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
  //stepperMotor();
  stepperMotor(int maxvel, int ppv, int TTimer);
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
  void set_direccion(bool dir);
  bool get_direccion(void);

private:
  int PinDir,PinSI,PinOE,PinHS,PinOP;
  int entrepaso;
  int tiempoTimer; //tiempo en microsegundos de atencion interrupcion del timer
  int pasosPorVuelta;
  int velocidadMaxima;
  float velocidad; // en RPMs
  float coefVelocidad;
  bool direccion;
  int frecCounter; // divisor del Timer para activar el paso.
  int frecCounterMAX; // divisor del Timer para activar el paso.
  int CorModo; // variavle de correccion de pasos por vuelta para fullsetp y halfstep
  void hacerPaso(void);

};

#endif /* STEPPERMOTOR_H_ */
