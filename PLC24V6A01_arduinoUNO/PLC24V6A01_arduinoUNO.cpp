/*
ADM3202 1(C1+) <-> 0.1uF <-> ADM3202 3(C1-)
ADM3202 2(V+) <-> 0.1uF <-> ADM3202 16(VCC)
ADM3202 4(C2+) <-> 0.1uF <-> ADM3202 5(C2-)
ADM3202 6(V-) <-> 0.1uF <-> ADM3202 15(GND)
(ADM3202 7(T2OUT) <-> TX2)
(ADM3202 8(R2IN) <-> RX2)
ADM3202 9(R2OUT) <-> Arduino Digital #(as soft ware RX2)
ADM3202 10(T2IN) <-> Arduino Digital #(as soft ware TX2)
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

SoftwareSerial mySerial(2, 3); // RX, TX

void PLC24V6A01_arduinoUNO::Init(){
  mySerial.begin(115200);
}

String PLC24V6A01_arduinoUNO::Read(){
  String a=String("                              ");
  int i = 0; //conter
  int ser;
  String Ans0;
  delay(200);
  while(mySerial.available()){
    ser = mySerial.read();
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

String PLC24V6A01_arduinoUNO::RTP(){
  mySerial.println("RTP");
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read();
  return Ans;
}

String PLC24V6A01_arduinoUNO::RST(){
  mySerial.println("RST");
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read();
  return Ans;
}

String PLC24V6A01_arduinoUNO::RAL(){
  mySerial.println("RAL");
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read();
  return Ans;
}

String PLC24V6A01_arduinoUNO::RTM(){
  mySerial.println("RTM");
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read();
  return Ans;
}

String PLC24V6A01_arduinoUNO::RCO(){
  mySerial.println("RCO");
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read();
  return Ans;
}

String PLC24V6A01_arduinoUNO::RTS(){
  mySerial.println("RTS");
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read();
  return Ans;
}

String PLC24V6A01_arduinoUNO::RLD(){
  mySerial.println("RLD");
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read();
  return Ans;
}

String PLC24V6A01_arduinoUNO::RAS(){
  mySerial.println("RAS");
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read();
  return Ans;
}

String PLC24V6A01_arduinoUNO::RAC(){
  mySerial.println("RAC");
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read();
  return Ans;
}

String PLC24V6A01_arduinoUNO::RAF(){
  mySerial.println("RAF");
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read();
  return Ans;
}

String PLC24V6A01_arduinoUNO::RAV(){
  mySerial.println("RAV");
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read();
  return Ans;
}

String PLC24V6A01_arduinoUNO::STE(String tmp){
  String Set=String("STE,");
  Set.concat(tmp);
  mySerial.println(Set);
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read();
  return Ans;
}

String PLC24V6A01_arduinoUNO::STH(String tmp){
  String Set=String("STH,");
  String Cpr=String("7200");
  if (Cpr<tmp){
    Set.concat(Cpr);
  } else {
    Set.concat(tmp);
  }
  mySerial.println(Set);
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read();
  return Ans;
}

String PLC24V6A01_arduinoUNO::STM(String tmp){
  String Set=String("STM,");
  Set.concat(tmp);
  mySerial.println(Set);
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read();
  return Ans;
}

String PLC24V6A01_arduinoUNO::STA(){
  mySerial.println("STA");
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read();
  return Ans;
}

String PLC24V6A01_arduinoUNO::STO(){
  mySerial.println("STO");
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read();
  return Ans;
}

String PLC24V6A01_arduinoUNO::STT(String tmp){
  String Set=String("STT,");
  Set.concat(tmp);
  mySerial.println(Set);
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read();
  return Ans;
}

String PLC24V6A01_arduinoUNO::SPT(String tmp){
  String Set=String("SPT,");
  Set.concat(tmp);
  mySerial.println(Set);
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read();
  return Ans;
}

String PLC24V6A01_arduinoUNO::WAS(String tmp){
  String Set=String("WAS,");
  Set.concat(tmp);
  mySerial.println(Set);
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read();
  return Ans;
}

String PLC24V6A01_arduinoUNO::WAC(String tmp){
  String Set=String("WAC,");
  Set.concat(tmp);
  mySerial.println(Set);
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read();
  return Ans;
}

String PLC24V6A01_arduinoUNO::WAF(String tmp){
  String Set=String("WAF,");
  Set.concat(tmp);
  mySerial.println(Set);
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read();
  return Ans;
}

String PLC24V6A01_arduinoUNO::WAV(String tmp){
  String Set=String("WAV,");
  Set.concat(tmp);
  mySerial.println(Set);
  String Ans;
  Ans = PLC24V6A01_arduinoUNO::Read();
  return Ans;
}

