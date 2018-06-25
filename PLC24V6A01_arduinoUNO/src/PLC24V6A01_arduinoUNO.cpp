/*
ADM3202 1(C1+) <-> 0.1uF <-> ADM3202 3(C1-)
ADM3202 2(V+) <-> 0.1uF <-> ADM3202 16(VCC)
ADM3202 4(C2+) <-> 0.1uF <-> ADM3202 5(C2-)
ADM3202 6(V-) <-> 0.1uF <-> ADM3202 15(GND)
(ADM3202 7(T2OUT) <-> TX2)
(ADM3202 8(R2IN) <-> RX2)
ADM3202 9(R2OUT) <-> Arduino Digital 4(as soft ware RX2)
ADM3202 10(T2IN) <-> Arduino Digital 5(as soft ware TX2)
ADM3202 11(T1IN) <-> Arduino Digital 3(as soft ware TX1)
ADM3202 12(R1OUT) <-> Arduino Digital 2(as soft ware RX1)
ADM3202 13(R1IN) <-> RX1
ADM3202 14(T1OUT) <-> TX1
ADM3202 15(GND) <-> 0.1uF <-> ADM3202 16(VCC)
ADM3202 16(VCC) <-> 3.3V
*/

#include <Arduino.h>
#include "PLC24V6A01_arduinoUNO.h"
#include <SoftwareSerial.h>

SoftwareSerial mySerial_01(2, 3); // RX, TX
SoftwareSerial mySerial_02(4, 5); // RX, TX

String PLC24V6A01_arduinoUNO::Read_01(){
  String a=String("                              ");
  int i = 0; //conter
  int ser;
  String Ans0;
  delay(200);
  while(mySerial_01.available()){
    ser = mySerial_01.read();
    if(ser==13){
    } else if(ser==10){
    } else {
      a.setCharAt(i,char(ser));
      i++;
    }
    delay(50);
  }
  return a;
}

String PLC24V6A01_arduinoUNO::RTP_01(){
  mySerial_01.begin(115200);
  mySerial_01.println("RTP");
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read_01();
  return Ans;
}

String PLC24V6A01_arduinoUNO::RST_01(){
  mySerial_01.begin(115200);
  mySerial_01.println("RST");
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read_01();
  return Ans;
}

String PLC24V6A01_arduinoUNO::RAL_01(){
  mySerial_01.begin(115200);
  mySerial_01.println("RAL");
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read_01();
  return Ans;
}

String PLC24V6A01_arduinoUNO::RTM_01(){
  mySerial_01.begin(115200);
  mySerial_01.println("RTM");
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read_01();
  return Ans;
}

String PLC24V6A01_arduinoUNO::RCO_01(){
  mySerial_01.begin(115200);
  mySerial_01.println("RCO");
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read_01();
  return Ans;
}

String PLC24V6A01_arduinoUNO::RTS_01(){
  mySerial_01.begin(115200);
  mySerial_01.println("RTS");
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read_01();
  return Ans;
}

String PLC24V6A01_arduinoUNO::RLD_01(){
  mySerial_01.begin(115200);
  mySerial_01.println("RLD");
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read_01();
  return Ans;
}

String PLC24V6A01_arduinoUNO::RAS_01(){
  mySerial_01.begin(115200);
  mySerial_01.println("RAS");
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read_01();
  return Ans;
}

String PLC24V6A01_arduinoUNO::RAC_01(){
  mySerial_01.begin(115200);
  mySerial_01.println("RAC");
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read_01();
  return Ans;
}

String PLC24V6A01_arduinoUNO::RAF_01(){
  mySerial_01.begin(115200);
  mySerial_01.println("RAF");
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read_01();
  return Ans;
}

String PLC24V6A01_arduinoUNO::RAV_01(){
  mySerial_01.begin(115200);
  mySerial_01.println("RAV");
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read_01();
  return Ans;
}

String PLC24V6A01_arduinoUNO::STE_01(String tmp){
  mySerial_01.begin(115200);
  String Set=String("STE,");
  Set.concat(tmp);
  mySerial_01.println(Set);
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read_01();
  return Ans;
}

String PLC24V6A01_arduinoUNO::STH_01(String tmp){
  mySerial_01.begin(115200);
  String Set=String("STH,");
  String Cpr=String("7200");
  if (Cpr<tmp){
    Set.concat(Cpr);
  } else {
    Set.concat(tmp);
  }
  mySerial_01.println(Set);
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read_01();
  return Ans;
}

String PLC24V6A01_arduinoUNO::STM_01(String tmp){
  mySerial_01.begin(115200);
  String Set=String("STM,");
  Set.concat(tmp);
  mySerial_01.println(Set);
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read_01();
  return Ans;
}

String PLC24V6A01_arduinoUNO::STA_01(){
  mySerial_01.begin(115200);
  mySerial_01.println("STA");
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read_01();
  return Ans;
}

String PLC24V6A01_arduinoUNO::STO_01(){
  mySerial_01.begin(115200);
  mySerial_01.println("STO");
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read_01();
  return Ans;
}

String PLC24V6A01_arduinoUNO::STT_01(String tmp){
  mySerial_01.begin(115200);
  String Set=String("STT,");
  Set.concat(tmp);
  mySerial_01.println(Set);
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read_01();
  return Ans;
}

String PLC24V6A01_arduinoUNO::SPT_01(String tmp){
  mySerial_01.begin(115200);
  String Set=String("SPT,");
  Set.concat(tmp);
  mySerial_01.println(Set);
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read_01();
  return Ans;
}

String PLC24V6A01_arduinoUNO::WAS_01(String tmp){
  mySerial_01.begin(115200);
  String Set=String("WAS,");
  Set.concat(tmp);
  mySerial_01.println(Set);
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read_01();
  return Ans;
}

String PLC24V6A01_arduinoUNO::WAC_01(String tmp){
  mySerial_01.begin(115200);
  String Set=String("WAC,");
  Set.concat(tmp);
  mySerial_01.println(Set);
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read_01();
  return Ans;
}

String PLC24V6A01_arduinoUNO::WAF_01(String tmp){
  mySerial_01.begin(115200);
  String Set=String("WAF,");
  Set.concat(tmp);
  mySerial_01.println(Set);
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read_01();
  return Ans;
}

String PLC24V6A01_arduinoUNO::WAV_01(String tmp){
  mySerial_01.begin(115200);
  String Set=String("WAV,");
  Set.concat(tmp);
  mySerial_01.println(Set);
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read_01();
  return Ans;
}

String PLC24V6A01_arduinoUNO::Read_02(){
  String a=String("                              ");
  int i = 0; //conter
  int ser;
  String Ans0;
  delay(200);
  while(mySerial_02.available()){
    ser = mySerial_02.read();
    if(ser==13){
    } else if(ser==10){
    } else {
      a.setCharAt(i,char(ser));
      i++;
    }
    delay(50);
  }
  return a;
}

String PLC24V6A01_arduinoUNO::RTP_02(){
  mySerial_02.begin(115200);
  mySerial_02.println("RTP");
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read_02();
  return Ans;
}

String PLC24V6A01_arduinoUNO::RST_02(){
  mySerial_02.begin(115200);
  mySerial_02.println("RST");
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read_02();
  return Ans;
}

String PLC24V6A01_arduinoUNO::RAL_02(){
  mySerial_02.begin(115200);
  mySerial_02.println("RAL");
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read_02();
  return Ans;
}

String PLC24V6A01_arduinoUNO::RTM_02(){
  mySerial_02.begin(115200);
  mySerial_02.println("RTM");
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read_02();
  return Ans;
}

String PLC24V6A01_arduinoUNO::RCO_02(){
  mySerial_02.begin(115200);
  mySerial_02.println("RCO");
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read_02();
  return Ans;
}

String PLC24V6A01_arduinoUNO::RTS_02(){
  mySerial_02.begin(115200);
  mySerial_02.println("RTS");
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read_02();
  return Ans;
}

String PLC24V6A01_arduinoUNO::RLD_02(){
  mySerial_02.begin(115200);
  mySerial_02.println("RLD");
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read_02();
  return Ans;
}

String PLC24V6A01_arduinoUNO::RAS_02(){
  mySerial_02.begin(115200);
  mySerial_02.println("RAS");
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read_02();
  return Ans;
}

String PLC24V6A01_arduinoUNO::RAC_02(){
  mySerial_02.begin(115200);
  mySerial_02.println("RAC");
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read_02();
  return Ans;
}

String PLC24V6A01_arduinoUNO::RAF_02(){
  mySerial_02.begin(115200);
  mySerial_02.println("RAF");
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read_02();
  return Ans;
}

String PLC24V6A01_arduinoUNO::RAV_02(){
  mySerial_02.begin(115200);
  mySerial_02.println("RAV");
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read_02();
  return Ans;
}

String PLC24V6A01_arduinoUNO::STE_02(String tmp){
  mySerial_02.begin(115200);
  String Set=String("STE,");
  Set.concat(tmp);
  mySerial_02.println(Set);
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read_02();
  return Ans;
}

String PLC24V6A01_arduinoUNO::STH_02(String tmp){
  mySerial_02.begin(115200);
  String Set=String("STH,");
  String Cpr=String("7200");
  if (Cpr<tmp){
    Set.concat(Cpr);
  } else {
    Set.concat(tmp);
  }
  mySerial_02.println(Set);
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read_02();
  return Ans;
}

String PLC24V6A01_arduinoUNO::STM_02(String tmp){
  mySerial_02.begin(115200);
  String Set=String("STM,");
  Set.concat(tmp);
  mySerial_02.println(Set);
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read_02();
  return Ans;
}

String PLC24V6A01_arduinoUNO::STA_02(){
  mySerial_02.begin(115200);
  mySerial_02.println("STA");
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read_02();
  return Ans;
}

String PLC24V6A01_arduinoUNO::STO_02(){
  mySerial_02.begin(115200);
  mySerial_02.println("STO");
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read_02();
  return Ans;
}

String PLC24V6A01_arduinoUNO::STT_02(String tmp){
  mySerial_02.begin(115200);
  String Set=String("STT,");
  Set.concat(tmp);
  mySerial_02.println(Set);
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read_02();
  return Ans;
}

String PLC24V6A01_arduinoUNO::SPT_02(String tmp){
  mySerial_02.begin(115200);
  String Set=String("SPT,");
  Set.concat(tmp);
  mySerial_02.println(Set);
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read_02();
  return Ans;
}

String PLC24V6A01_arduinoUNO::WAS_02(String tmp){
  mySerial_02.begin(115200);
  String Set=String("WAS,");
  Set.concat(tmp);
  mySerial_02.println(Set);
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read_02();
  return Ans;
}

String PLC24V6A01_arduinoUNO::WAC_02(String tmp){
  mySerial_02.begin(115200);
  String Set=String("WAC,");
  Set.concat(tmp);
  mySerial_02.println(Set);
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read_02();
  return Ans;
}

String PLC24V6A01_arduinoUNO::WAF_02(String tmp){
  mySerial_02.begin(115200);
  String Set=String("WAF,");
  Set.concat(tmp);
  mySerial_02.println(Set);
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read_02();
  return Ans;
}

String PLC24V6A01_arduinoUNO::WAV_02(String tmp){
  mySerial_02.begin(115200);
  String Set=String("WAV,");
  Set.concat(tmp);
  mySerial_02.println(Set);
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read_02();
  return Ans;
}

