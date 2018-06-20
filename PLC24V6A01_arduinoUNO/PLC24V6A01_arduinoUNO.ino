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
#include <string.h>
//#include "PLC24V6A01_arduinoUNO.h"
LiquidCrystal_I2C lcd(0x27,16,2); // set the LCD address to 0x27 for a 16 chars and 2 line display

SoftwareSerial mySerial(2, 3); // RX, TX

//PLC24V6A01_arduinoUNO PLC24;


void setup()
{
  lcd.init(); // initialize the lcd
  lcd.init();
  lcd.backlight();
  mySerial.begin(115200);
  mySerial.println("STE,3040"); //success
  mySerial.println("STO"); //success
//  PLC24.InitRoutine();

}

void loop() // run over and over//
{
  char RST[4]={'R','S','T','\0'};
  char a[16];
  a[16]='\0';
  char RTP[4]={'R','T','P','\0'};
  char* Ans=a;

  int ser;

  int i = 0;
  lcd.clear();
  lcd.setCursor(0,0);
  Read(RTP, &Ans);
  lcd.print(Ans);
  lcd.setCursor(0,1);
//  *Ans = a;
  Read2(RST, &Ans);
  lcd.print(Ans);
  delay(1000);
//  memset(a, '\0',strlen(a));

/*  char* RTP="RTP";
  char* RST="RST";
  char* Ans = "";
  lcd.setCursor(0,0);

  PLC24.Read(RTP, &Ans);

  lcd.clear();
  delay(1000);
  lcd.setCursor(0,0);
  lcd.print(Ans);
  delay(1000);
  
  Ans = RST;
  PLC24.Read(RST, &Ans);
  lcd.setCursor(0,1);
  lcd.print(Ans);

  delay(1000);
*/
}
//void Read(char* Str, char** Ans){
void Read(char Str[3], char** Ans){
  char a[16];
  a[16]='\0';
  int i = 0;
  int ser;
  mySerial.println(Str); //success
  delay(1000);
  while(mySerial.available()){
    ser = mySerial.read();
    if(ser==13){
        a[i]='\0';
        *Ans= a;
        i = 0;
    } else if(i==16){
    } else if(ser==10){
    } else {
      a[i] = char(ser);
      i++;
    }
  }
}
void Read2(char Str[3], char** Ans){
  char a[16];
  a[16]='\0';
  int i = 0;
  int ser;
  mySerial.println(Str); //success
  delay(1000);
  while(mySerial.available()){
    ser = mySerial.read();
    if(ser==13){
        a[i]='\0';
        *Ans= a;
        i = 0;
    } else if(i==16){
    } else if(ser==10){
    } else {
      a[i] = char(ser);
      i++;
    }
  }
}



