/*
 * Name : Mark Song
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>

int RECV_PIN = 6;
int red = 12;    //The red RGB LED is connected pin 9 of the Arduino.
int blue = 13;  //The blue RGB LED is connected pin 11 of the Arduino.
int sw1 = 2;    //The SW1 button is connect to pin 2 of the Arduino.
int sw2 = 3;    //The SW2 button is connect to pin 3 of the Arduino.
int buzzerPin  = 5 ;  //The buzzerPin is connected to pin 5 of the Arduino.


IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  pinMode(sw1, INPUT);  //Setup button1 pin as an input pin.
  pinMode(sw2, INPUT);  //Setup button2 pin as an input pin.
  pinMode(red, OUTPUT);    //Setup red RGB LED pin as an output pin.
  pinMode(blue, OUTPUT);   //Setup blue RGB LED pin as an output pin.
  pinMode(buzzerPin, OUTPUT);  //Setup red LED pin as an output pin.
  // In case the interrupt driver crashes on setup, give a clue
  // to the user what's going on.
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, DEC);
    irrecv.resume(); // Receive the next value
        // level 2 
    // if 551502015  VOL + is pressed RED LED turns on 
    // if 551485695  CHN +  is pressed RED LED turns off 
    // if 551536695 button 3 is pressed Blue LED turns on  
    // if 551495895 button 4 is pressed blue LED turns off 
    // if 551528535 button 5 is pressed buzzer sound turns on 

    if (results.value == 551502015) { 
      digitalWrite(red, HIGH);
    }
    if (results.value == 551485695) { 
      digitalWrite(red, LOW);
    }
    
    if (results.value == 551536695) { 
      digitalWrite(blue, HIGH);
    }
    if (results.value == 551495895) { 
      digitalWrite(blue, LOW);
    }
    if (results.value == 551528535) { 
      tone(buzzerPin, 2000,100);
      tone(buzzerPin, 2000,100);
    }

  }
  delay(100);
}
