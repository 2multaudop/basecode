
#include <Arduino.h>
#include <SoftwareSerial.h>
#include <stdio.h>
#include "debug.h"
#include "lcd.h"
#include "tuner.h"

const int potentiometer_pin = 5;
int guitar = analogRead(potentiometer_pin); 
unsigned int i = 0;
const int numReadings = 100;               //Input averaging variables


// Serial Debug Average of Analog input
void inputAverage(){
    
    int inputArray[i];
    int guitarInputraw;    
    int guitarAverage = 0;
    
      
    Serial.println(">> 10 samples:");
    Serial.println("");   
    for (int i = 0; i < numReadings; ++i) {     
        guitarInputraw = (analogRead(potentiometer_pin)) ;         
        Serial.println(guitarInputraw);
        guitarAverage = guitarAverage + guitarInputraw ; 
    }
    
    Serial.println("");   
    Serial.println(">> Total of 10 samples:");
    Serial.println(guitarAverage);
    
    Serial.println("");   
    Serial.println(">> 10 sample Average equals:");
    guitarAverage = guitarAverage/numReadings;
    Serial.println(guitarAverage);
  
}

// LCD payload serial debug
void lcdPrint(){
    int guitar_sig = map(analogRead(potentiometer_pin),0,1024,-255,255);    //  map(value, fromLow, fromHigh, toLow, toHigh)  toLow handles offset                     
    char LcdSend[13];
    sprintf(LcdSend, "add 1,0,%d", guitar_sig);
    Serial.println(LcdSend);   
    return ;
}

// Serial Debug print analog pin value
void printInput(){
      Serial.println(analogRead(potentiometer_pin));
}

// Serial debug control
void  serialDebug(){
   switch (Serial.read()) {
    case 'm':
      Serial.println("");
      Serial.println(">> ****Main menu press 'M' to return****");  
      Serial.println(" 1. Press'I'for guitar input value");
      Serial.println(" 2. Press'A'for 10 sample average");
      Serial.println(" 3. Press'L' for LCD print value");
      Serial.println(" 4. Press'C' to call hello world class ");
      Serial.println(" 5. Press'l' ");
      Serial.println(" 6. Press'T' for the test terminal ");
      Serial.println(">> ****End of menu****");  
      Serial.println("");
    break;

    case 'i':
      printInput(); 
    break;
    
    case 'l':
      lcdPrint();
    break;

    case 'a':
      inputAverage(); 
    break;

     case 't':
      Serial.println("test");
      tunerCall();
      //callHello(); 
      //lcdTestInput();
      
    break;
   
   }  
}

// Check for keyboard debug activity
void checkDebug(){
  if (Serial.available() > 0){                            
      serialDebug();
  }
}
