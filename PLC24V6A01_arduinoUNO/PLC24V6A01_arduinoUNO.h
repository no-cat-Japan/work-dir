/*
 * PLC24V6A01_arduinoUNO.h
 */
#ifndef JPZUKIN_SAMPLE_LIBRARY
#define JPZUKIN_SAMPLE_LIBRARY
#include <Arduino.h>

class PLC24V6A01_arduinoUNO {
public:
  void Init();
  void SetMod();
  String Read();
  String RTP();
  String RST();
  String RAL();
  String RTM();
  String RCO();
  String RTS();
  String RLD();
  String RAS();
  String RAC();
  String RAF();
  String RAV();
  String STE(String tmp);
  String STH(String tmp);
  String STM(String tmp);
  String STA();
  String STO();
  String STT(String tmp);
  String SPT(String tmp);
  String WAS(String tmp);
  String WAC(String tmp);
  String WAF(String tmp);
  String WAV(String tmp);
  
private:

};

#endif

