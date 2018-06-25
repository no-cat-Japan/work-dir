/*
 * PLC24V6A01_arduinoUNO.h
 */
#ifndef JPZUKIN_SAMPLE_LIBRARY
#define JPZUKIN_SAMPLE_LIBRARY
#include <Arduino.h>

class PLC24V6A01_arduinoUNO {
public:
  void SetMod();
  String Read_01();
  String RTP_01();
  String RST_01();
  String RAL_01();
  String RTM_01();
  String RCO_01();
  String RTS_01();
  String RLD_01();
  String RAS_01();
  String RAC_01();
  String RAF_01();
  String RAV_01();
  String STE_01(String tmp);
  String STH_01(String tmp);
  String STM_01(String tmp);
  String STA_01();
  String STO_01();
  String STT_01(String tmp);
  String SPT_01(String tmp);
  String WAS_01(String tmp);
  String WAC_01(String tmp);
  String WAF_01(String tmp);
  String WAV_01(String tmp);

  String Read_02();
  String RTP_02();
  String RST_02();
  String RAL_02();
  String RTM_02();
  String RCO_02();
  String RTS_02();
  String RLD_02();
  String RAS_02();
  String RAC_02();
  String RAF_02();
  String RAV_02();
  String STE_02(String tmp);
  String STH_02(String tmp);
  String STM_02(String tmp);
  String STA_02();
  String STO_02();
  String STT_02(String tmp);
  String SPT_02(String tmp);
  String WAS_02(String tmp);
  String WAC_02(String tmp);
  String WAF_02(String tmp);
  String WAV_02(String tmp);

private:

};

#endif

