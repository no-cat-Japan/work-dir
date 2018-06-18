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
char* PLC24V6A01_arduinoUNO::Read(char Str[3]){
    char* a = "";
    int i = 0;
    mySerial.println(Str[3]); //success
//  mySerial.println("RTP"); //success
//  mySerial.print("RTP\r"); //success
//  mySerial.print("ARA\r"); // success
  delay(1000);
  while(mySerial.available()){
    int ser = mySerial.read();
    if(ser==13){
//      lcd.clear();
//      lcd.setCursor(0,0);
//      lcd.print(a);
      i = 0;
//      for(int j=0;j<16;j++){
//        a[j] = b[j];
//      }
    } else if(i==16){
    } else if(ser==10){
    } else {
      a[i] = char(ser);
      i++;
    }
    return a;
  }

}

