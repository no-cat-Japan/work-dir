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

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "PLC24V6A01_arduinoUNO.h"
LiquidCrystal_I2C lcd(0x27,16,2); // set the LCD address to 0x27 for a 16 chars and 2 line display

PLC24V6A01_arduinoUNO PLC24;

  char RST[4]="RST";
  char RTP[4]="RTP";
  char* Ans;
  char Temp[2]="25";
void setup()
{
  lcd.init(); // initialize the lcd
  lcd.init();
  lcd.backlight();

  PLC24.InitRoutine();

}

void loop() // run over and over//
{

  lcd.clear();
  lcd.setCursor(0,0);
  PLC24.SetTemp(Temp);
  PLC24.SetMod();   //Set the drive mode
  PLC24.StatCtrl(); //Start the temperatur control
  delay(1000);

  while(1){
  lcd.setCursor(0,1);
    PLC24.Read(RTP, &Ans);
    lcd.print(Ans);
    delay(1000);
  }

}

