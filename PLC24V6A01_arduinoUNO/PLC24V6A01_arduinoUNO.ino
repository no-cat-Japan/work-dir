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

/*
 PLC24.STE("xxxxx") //-9999 < xxxx < 09999  (00001 = 0.01 degrees C)
 PLC24.STH("xxxx") //1 < xxxx < 7200  (0001 = 0.1 hour)
 PLC24.STM("xxxx") //1 < xxxx < 9999  (0001 = 0.1 minit)
 PLC24.STT("xxxx") // xxxx = CONT or TIME
 PLC24.SPT("xxxxx") //-9999 < xxxx < 09999  (00001 = 0.01 degrees C)
 PLC24.WAS("x") // x =1 or 0  (1:ON, 2:OFF)
 PLC24.WAC("x") // x =1 or 0  (1:ON, 2:OFF)
 PLC24.WAF("x") // x =1 or 0  (1:ON, 2:OFF)
 PLC24.WAV("x") // x =1 or 0  (1:ON, 2:OFF)
 */

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "PLC24V6A01_arduinoUNO.h"
LiquidCrystal_I2C lcd(0x27,16,2); // set the LCD address to 0x27 for a 16 chars and 2 line display

PLC24V6A01_arduinoUNO PLC24;

void setup()
{
  lcd.init(); // initialize the lcd
  lcd.init();
  lcd.backlight();
}

void loop() // run over and over//
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(PLC24.STE_01("2000"));
  lcd.setCursor(0,1);
  lcd.print(PLC24.STE_02("3000"));
  lcd.setCursor(0,0);
  lcd.print(PLC24.STA_01()); //Start the temperatur control
  lcd.setCursor(0,1);
  lcd.print(PLC24.STA_02()); //Start the temperatur control
  for (int i=0;i<5;i++){
    lcd.setCursor(0,0);
    lcd.print(PLC24.RTP_01());
    lcd.setCursor(0,1);
    lcd.print(PLC24.RTP_02());
    delay(1000);
  }
  lcd.setCursor(0,0);
  lcd.print(PLC24.STO_01());
  lcd.setCursor(0,1);
  lcd.print(PLC24.STO_02());
  lcd.setCursor(0,0);
  lcd.print(PLC24.RST_01());
  lcd.setCursor(0,1);
  lcd.print(PLC24.RST_02());

  while(1);

}

