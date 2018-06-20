/*
 * PLC24V6A01_arduinoUNO.h
 */
#ifndef JPZUKIN_SAMPLE_LIBRARY
#define JPZUKIN_SAMPLE_LIBRARY
#include <Arduino.h>

class PLC24V6A01_arduinoUNO {
public:
  InitRoutine();
  void SetMod();
  void ReadBase(char** Ans0);
  void Read(char Str[3], char** Ans);
  void SetTemp(char Str[2]);
  void StatCtrl();
private:

};

#endif

