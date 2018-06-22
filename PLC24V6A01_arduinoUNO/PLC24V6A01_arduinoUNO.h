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
  String RTP();
  String RST();
  String RAL();
  String RTM();
  String RCO();
  String RTS();
  String RLD();
  void SetTemp(char Str[2]);
  void StatCtrl();
  
private:

};

#endif

