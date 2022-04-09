#include <Arduino.h>
#include <SoftwareSerial.h>
#include <stdio.h>
#include "lcd.h"
#include "debug.h"


//const int guitar_input = 5;
//int guitar_read = analogRead(guitar_input);

//variables
int guitar_sig = 0;
char lcd_sig = 0;   
char Tosend = 0;
char LcdSend = 0;


// LCD screen refresh
void lcdUpdate(){

  int guitar_sig = map(analogRead(guitar_input),0,1024,-255,255);       //  map(value, fromLow, fromHigh, toLow, toHigh)  toLow handles offset                     
  char LcdSend[13];
  sprintf(LcdSend, "add 1,0,%d", guitar_sig);
  Serial1.print(LcdSend);
  Serial1.write(0xff);
  Serial1.write(0xff);           
  Serial1.write(0xff); 
  return ;
}
