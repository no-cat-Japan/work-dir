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
  String ReadBase();
  String Read(String Str, String Ans);
  String RST();
  void SetTemp(char Str[2]);
  void StatCtrl();
  
private:

};

#endif

