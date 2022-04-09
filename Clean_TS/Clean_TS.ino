/*          1. Interrupt driver Frequency detection
 *          2. Display key 
 *          3. Print string running every loop
 *          4. Serup and output that reperesents frequency input
 *          5. Serial debug       
 *                                -Raw value
 *                                -frequency conversion
 *                                -                                
 *           Loop
 *                Call String function for display
 *                If condition Call raw frequency function
 *                Frequency math function
 *                Frequency multplier on output
 *                Run debug stream at 1Hz checking for flag which is a counter  
 */

#include <Arduino.h>
#include <SoftwareSerial.h>
#include <stdio.h>
#include <Time.h>
#include <Keyboard.h>
#include <BlockNot.h>  
#include "debug.h"
#include "lcd.h"
#include "tuner.h"


// variables for setup
const int countDown = 5;                 //Setup countdown


// System clock in millisecond
BlockNot debugTimer(500);
BlockNot lcdRefreshTimer(10);
BlockNot tunerTimer(100);


// Setup for our program
void setup() {
  Serial.begin(9600);                                           //Default baud rate of the Nextion TFT is 9600
  Serial1.begin(9600);  

  //IO Setup 
  pinMode(guitar_input,INPUT);                             
  analogReadResolution(12);
  
  // Setup confirmation loop
  Serial.println("");
  Serial.println("");
  for (int i = 0; i < countDown; ++i) {                    
        Serial.println("Press 'M' for main menu");
        delay(1000);      
  }  
  Serial.println("");  
  Serial.println("Setup complete");
 
}


// Loop of program
void loop() {  
    
  // refreshes lcd screen
  if (lcdRefreshTimer.TRIGGERED){
    lcdUpdate(); 
  }
  
  //check for debug initiation
  if (debugTimer.TRIGGERED){
    checkDebug();                          // Debug.checkDebug();
  }
  
  //check for debug initiation
  if (tunerTimer.TRIGGERED){
    //tunerActive();                         // Debug.checkDebug();
  }

}
