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

PLC24V6A01_arduinoUNO::InitRoutine(){
  mySerial.begin(115200);
  mySerial.println("STE,3040"); //success
  mySerial.println("STO"); //success
}

String PLC24V6A01_arduinoUNO::ReadBase(String Ans0){
  char a[16];
  int i = 0;
  int ser;
  delay(1000);
  while(mySerial.available()){
    ser = mySerial.read();
    if(ser==13){
        a[13]='\0';
        Ans0= a;
        i = 0;
    } else if(i==16){
    } else if(ser==10){
    } else {
      a[i] = char(ser);
      i++;
    }
    delay(50);
  }
  return Ans0;
}

String PLC24V6A01_arduinoUNO::Read(String Str, String Ans){
  mySerial.println(Str); //success
  Ans = PLC24V6A01_arduinoUNO::ReadBase(Ans);
  return Ans;
}

String PLC24V6A01_arduinoUNO::RST(String Ans){
  mySerial.println("RST"); //success
  Ans = PLC24V6A01_arduinoUNO::ReadBase(Ans);
  return Ans;
}

void PLC24V6A01_arduinoUNO::SetTemp(char Str[2]){
  char STE[8]="STE,2500";
  STE[4]=Str[0];
  STE[5]=Str[1];
  mySerial.println(STE); //success
  delay(500);
}

void PLC24V6A01_arduinoUNO::SetMod(){
  mySerial.println("STT,CONT"); //success
  delay(500);
}

void PLC24V6A01_arduinoUNO::StatCtrl(){
  mySerial.println("STO"); //success
//  PLC24V6A01_arduinoUNO::ReadBase(Ans);
}

