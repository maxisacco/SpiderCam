/*
 * optoWheel.h
 *
 *  Created on: 08/11/2013
 *      Author: msacco
 */

#ifndef OPTOWHEEL_H_
#define OPTOWHEEL_H_
#ifndef ARDUINO_H_
#define ARDUINO_H_
#include "Arduino.h"
#endif //ARDUINO_H_

class optoWheel {
public:
  optoWheel(int dpv, float mmXv);
  virtual ~optoWheel();
  void reset(void);
  void pinAssign(int encA, int encB);
  int get_posAbsPasos(void);
  int get_direccionAct(void);
  int get_dientesPorVuelta(void);
  float get_velocidadInst(void);
 // float get_velocidadPP(void);
  float get_mmPorVuelta(void);
//  int get_PosRelativa(void);
 // void resetPosRelativa(void);
//  void set_posAbsPasos(int valor);
  void set_dirInversion(bool valor);
  void run(void);


private:
  int PinA,PinB,PinALast;
  int dientesPorVuelta;
  long posAbsPasos;
  float milimetrosPorVuelta;
  unsigned long deltaT;
  unsigned long tiempoAnt;
  bool InvDir;
  bool lastDireccion;
  float velocidadInst;
};


#endif /* OPTOWHEEL_H_ */
