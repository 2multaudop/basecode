



#include <Arduino.h>
#include <SoftwareSerial.h>
#include <stdio.h>
#include "debug.h"

//variables
//int guitar_sig = 0;
const int guitar_input_f = 5;
// int freq = analogRead(guitar_input_f);    why does this not pass into the function below
unsigned int j = 0;
unsigned int k = 0;
const int freqReadings = 1024;               //Input averaging variables
const int SAMPLE_TIME = 100;   

void tunerCall(){ 
}

// starts tuner readings
void tunerActive(){

  int freq = analogRead(guitar_input_f);
  
  if (freq > 515){
    
    //store values in an array
    int freqArray[j];
    int freqInputraw;
    int freqCrossings[k];  
    int numberCrossings;  
    int crossingCount = 0;

    // this period of time 
    for (int j = 0; j < freqReadings; ++j) {              

        // this many times
        if ( 521 < freq < 523 ){                         
          numberCrossings = ++k; 
        }                
        //Serial.println(guitarInputraw);
        crossingCount = numberCrossings / 1024 ; 
    }
    
    Serial.println("");
    Serial.println(">> Number of Crossings equal:"); 
    Serial.println(numberCrossings); 
    Serial.println(">> Crosses in 1024 cycles:");
    Serial.println(crossingCount);  
    //count numbers point crossings
    
    // 

}
}
