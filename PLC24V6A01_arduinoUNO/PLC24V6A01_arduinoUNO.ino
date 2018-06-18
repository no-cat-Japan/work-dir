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

#include <SoftwareSerial.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "PLC24V6A01_arduinoUNO.h"
LiquidCrystal_I2C lcd(0x27,16,2); // set the LCD address to 0x27 for a 16 chars and 2 line display
PLC24V6A01_arduinoUNO PLC24;
//SoftwareSerial mySerial(2, 3); // RX, TX


void setup()
{
  lcd.init(); // initialize the lcd
  lcd.init();
  lcd.backlight();
  PLC24.InitRoutine();

}

void loop() // run over and over//
{
  int ser;
  char* a = "";
//  char b[16] = "";
  int i = 0;
    lcd.setCursor(0,0);
  char Str[3]="RTP";

  a = PLC24.Read(Str[3]);
//  mySerial.println("RTP"); //success
////  mySerial.println("RTP"); //success
////  mySerial.print("RTP\r"); //success
////  mySerial.print("ARA\r"); // success
//  delay(1000);
//  while(mySerial.available()){
//    ser = mySerial.read();
//    if(ser==13){
//      lcd.clear();
//      lcd.setCursor(0,0);
//      lcd.print(a);
//      i = 0;
////      for(int j=0;j<16;j++){
////        a[j] = b[j];
////      }
//    } else if(i==16){
//    } else if(ser==10){
//    } else {
//      a[i] = char(ser);
//      i++;
//    }
//  }
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(a);
      i = 0;

  
Str[3]="RST";
  a = PLC24.Read(Str[3]);
//mySerial.println("RST"); //success
//  delay(1000);
//  while(mySerial.available()){
//    ser = mySerial.read();
//    if(ser==13){
//    } else if(i==16){
//    } else if(ser==10){
//    } else {
//      a[i] = char(ser);
//      i++;
//    }
//  }
      lcd.setCursor(0,1);
      lcd.print(a);
      i = 0;

}



