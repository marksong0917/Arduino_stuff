/*
        Name: Mark Song
        Title: 321Maker Experiment #008 - Buzzer
        Description: This program turns on random color of RGB light when each tone is played
        Date: Thursday, October 11,18
        Requirements:  Arduino with 321Maker Shield
*/

int red = 9;    //The red RGB LED is connected pin 9 of the Arduino.
int green = 10; //The green RGB LED is connected pin 10 of the Arduino.
int blue = 11;  //The blue RGB LED is connected pin 11 of the Arduino.
#include "pitches.h";
int buzzerPin  = 5 ;  //The buzzerPin is connected to pin 5 of the Arduino.
int button1Pin = 2;   //The SW1 button is connect to pin 2 of the Arduino.
int rNumR ;
int rNumG ; 
int rNumB ; 


void setup() { //The Setup function runs once.
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);  //Setup red LED pin as an output pin.
  pinMode(button1Pin, INPUT);  //Setup button1 pin as an input pin.
  pinMode(red, OUTPUT);    //Setup red RGB LED pin as an output pin.
  pinMode(green, OUTPUT);  //Setup green RGB LED pin as an output pin.
  pinMode(blue, OUTPUT);   //Setup blue RGB LED pin as an output pin.
}

void loop() { //The loop function runs forever.

  // Using 3 random numbers to change colors of LED each time a note is played 
  // starts when you press button 1 
  if (digitalRead(button1Pin) == LOW) { //Check to see if button1 is pressed.
    
    rNumR = random(1,100);
    rNumG = random(1,100);
    rNumB = random(1,100);
    tone(buzzerPin, NOTE_B4, 400);
    Serial.print("Red: ");
    Serial.println(rNumR); 
    Serial.print("Green: ");
    Serial.println(rNumG) ;
    Serial.print("Blue: ");
    Serial.println(rNumB) ;
    analogWrite(red, rNumR);
    analogWrite(green, rNumG);
    analogWrite(blue, rNumB); 
    delay(500);
    
    rNumR = random(1,100);
    rNumG = random(1,100);
    rNumB = random(1,100);
    tone(buzzerPin, NOTE_B4, 400);
    Serial.print("Red: ");
    Serial.println(rNumR); 
    Serial.print("Green: ");
    Serial.println(rNumG) ;
    Serial.print("Blue: ");
    Serial.println(rNumB) ;
    analogWrite(red, rNumR);
    analogWrite(green, rNumG);
    analogWrite(blue, rNumB); 
    delay(500);
    
    rNumR = random(1,100);
    rNumG = random(1,100);
    rNumB = random(1,100);
    tone(buzzerPin, NOTE_B4, 400);
    Serial.print("Red: ");
    Serial.println(rNumR); 
    Serial.print("Green: ");
    Serial.println(rNumG) ;
    Serial.print("Blue: ");
    Serial.println(rNumB) ;
    analogWrite(red, rNumR);
    analogWrite(green, rNumG);
    analogWrite(blue, rNumB); 
    delay(500);
    
    rNumR = random(1,100);
    rNumG = random(1,100);
    rNumB = random(1,100);
    tone(buzzerPin, NOTE_E4, 400);  
    Serial.print("Red: ");
    Serial.println(rNumR); 
    Serial.print("Green: ");
    Serial.println(rNumG) ;
    Serial.print("Blue: ");
    Serial.println(rNumB) ;
    analogWrite(red, rNumR);
    analogWrite(green, rNumG);
    analogWrite(blue, rNumB);
    delay(500);
   
    rNumR = random(1,100);
    rNumG = random(1,100);
    rNumB = random(1,100);
    tone(buzzerPin, NOTE_E4, 400);
    Serial.print("Red: ");
    Serial.println(rNumR); 
    Serial.print("Green: ");
    Serial.println(rNumG) ;
    Serial.print("Blue: ");
    Serial.println(rNumB) ;
    analogWrite(red, rNumR);
    analogWrite(green, rNumG);
    analogWrite(blue, rNumB);
    delay(500);

    rNumR = random(1,100);
    rNumG = random(1,100);
    rNumB = random(1,100);
    tone(buzzerPin, NOTE_E4, 400);
    Serial.print("Red: ");
    Serial.println(rNumR); 
    Serial.print("Green: ");
    Serial.println(rNumG) ;
    Serial.print("Blue: ");
    Serial.println(rNumB) ;
    analogWrite(red, rNumR);
    analogWrite(green, rNumG);
    analogWrite(blue, rNumB);
    delay(500);

    rNumR = random(1,100);
    rNumG = random(1,100);
    rNumB = random(1,100);
    tone(buzzerPin, NOTE_G4, 400);
    Serial.print("Red: ");
    Serial.println(rNumR); 
    Serial.print("Green: ");
    Serial.println(rNumG) ;
    Serial.print("Blue: ");
    Serial.println(rNumB) ;
    analogWrite(red, rNumR);
    analogWrite(green, rNumG);
    analogWrite(blue, rNumB);
    delay(500);

    rNumR = random(1,100);
    rNumG = random(1,100);
    rNumB = random(1,100);
    tone(buzzerPin, NOTE_G4, 400);
    Serial.print("Red: ");
    Serial.println(rNumR); 
    Serial.print("Green: ");
    Serial.println(rNumG) ;
    Serial.print("Blue: ");
    Serial.println(rNumB) ;
    analogWrite(red, rNumR);
    analogWrite(green, rNumG);
    analogWrite(blue, rNumB);
    delay(500);

    rNumR = random(1,100);
    rNumG = random(1,100);
    rNumB = random(1,100);
    tone(buzzerPin, NOTE_G4, 400);
    Serial.print("Red: ");
    Serial.println(rNumR); 
    Serial.print("Green: ");
    Serial.println(rNumG) ;
    Serial.print("Blue: ");
    Serial.println(rNumB) ;
    analogWrite(red, rNumR);
    analogWrite(green, rNumG);
    analogWrite(blue, rNumB);
    delay(500);
    

    rNumR = random(1,100);
    rNumG = random(1,100);
    rNumB = random(1,100);
    tone(buzzerPin, NOTE_A4, 400); 
    Serial.print("Red: ");
    Serial.println(rNumR); 
    Serial.print("Green: ");
    Serial.println(rNumG) ;
    Serial.print("Blue: ");
    Serial.println(rNumB) ;
    analogWrite(red, rNumR);
    analogWrite(green, rNumG);
    analogWrite(blue, rNumB);
    delay(500);

    rNumR = random(1,100);
    rNumG = random(1,100);
    rNumB = random(1,100);
    tone(buzzerPin, NOTE_A4, 400); 
    Serial.print("Red: ");
    Serial.println(rNumR); 
    Serial.print("Green: ");
    Serial.println(rNumG) ;
    Serial.print("Blue: ");
    Serial.println(rNumB) ;
    analogWrite(red, rNumR);
    analogWrite(green, rNumG);
    analogWrite(blue, rNumB);
    delay(500);

    rNumR = random(1,100);
    rNumG = random(1,100);
    rNumB = random(1,100);
    tone(buzzerPin, NOTE_A4, 400); 
    Serial.print("Red: ");
    Serial.println(rNumR); 
    Serial.print("Green: ");
    Serial.println(rNumG) ;
    Serial.print("Blue: ");
    Serial.println(rNumB) ;
    analogWrite(red, rNumR);
    analogWrite(green, rNumG);
    analogWrite(blue, rNumB);
    delay(500);

    //6 SEC

    rNumR = random(1,100);
    rNumG = random(1,100);
    rNumB = random(1,100);
    tone(buzzerPin, NOTE_F4, 400); 
    Serial.print("Red: ");
    Serial.println(rNumR); 
    Serial.print("Green: ");
    Serial.println(rNumG) ;
    Serial.print("Blue: ");
    Serial.println(rNumB) ;
    analogWrite(red, rNumR);
    analogWrite(green, rNumG);
    analogWrite(blue, rNumB);
    delay(500);

    rNumR = random(1,100);
    rNumG = random(1,100);
    rNumB = random(1,100);
    tone(buzzerPin, NOTE_F4, 400); 
    Serial.print("Red: ");
    Serial.println(rNumR); 
    Serial.print("Green: ");
    Serial.println(rNumG) ;
    Serial.print("Blue: ");
    Serial.println(rNumB) ;
    analogWrite(red, rNumR);
    analogWrite(green, rNumG);
    analogWrite(blue, rNumB);
    delay(500);

    //7 sec

    rNumR = random(1,100);
    rNumG = random(1,100);
    rNumB = random(1,100);
    tone(buzzerPin, NOTE_F4, 400); 
    Serial.print("Red: ");
    Serial.println(rNumR); 
    Serial.print("Green: ");
    Serial.println(rNumG) ;
    Serial.print("Blue: ");
    Serial.println(rNumB) ;
    analogWrite(red, rNumR);
    analogWrite(green, rNumG);
    analogWrite(blue, rNumB);
    delay(500);

    rNumR = random(1,100);
    rNumG = random(1,100);
    rNumB = random(1,100);
    tone(buzzerPin, NOTE_C5, 400); 
    Serial.print("Red: ");
    Serial.println(rNumR); 
    Serial.print("Green: ");
    Serial.println(rNumG) ;
    Serial.print("Blue: ");
    Serial.println(rNumB) ;
    analogWrite(red, rNumR);
    analogWrite(green, rNumG);
    analogWrite(blue, rNumB);
    delay(500);
    //8 

    rNumR = random(1,100);
    rNumG = random(1,100);
    rNumB = random(1,100);
    tone(buzzerPin, NOTE_A2, 400); 
    Serial.print("Red: ");
    Serial.println(rNumR); 
    Serial.print("Green: ");
    Serial.println(rNumG) ;
    Serial.print("Blue: ");
    Serial.println(rNumB) ;
    analogWrite(red, rNumR);
    analogWrite(green, rNumG);
    analogWrite(blue, rNumB);
    delay(500);

    rNumR = random(1,100);
    rNumG = random(1,100);
    rNumB = random(1,100);
    tone(buzzerPin, NOTE_A2, 400); 
    Serial.print("Red: ");
    Serial.println(rNumR); 
    Serial.print("Green: ");
    Serial.println(rNumG) ;
    Serial.print("Blue: ");
    Serial.println(rNumB) ;
    analogWrite(red, rNumR);
    analogWrite(green, rNumG);
    analogWrite(blue, rNumB);
    delay(500);

    //9

    rNumR = random(1,100);
    rNumG = random(1,100);
    rNumB = random(1,100);
    tone(buzzerPin, NOTE_B2, 400); 
    Serial.print("Red: ");
    Serial.println(rNumR); 
    Serial.print("Green: ");
    Serial.println(rNumG) ;
    Serial.print("Blue: ");
    Serial.println(rNumB) ;
    analogWrite(red, rNumR);
    analogWrite(green, rNumG);
    analogWrite(blue, rNumB);
    delay(500);

    rNumR = random(1,100);
    rNumG = random(1,100);
    rNumB = random(1,100);
    tone(buzzerPin, NOTE_B2, 400); 
    Serial.print("Red: ");
    Serial.println(rNumR); 
    Serial.print("Green: ");
    Serial.println(rNumG) ;
    Serial.print("Blue: ");
    Serial.println(rNumB) ;
    analogWrite(red, rNumR);
    analogWrite(green, rNumG);
    analogWrite(blue, rNumB);
    delay(500);

    // 10 

    rNumR = random(1,100);
    rNumG = random(1,100);
    rNumB = random(1,100);
    tone(buzzerPin, NOTE_G5, 400); 
    Serial.print("Red: ");
    Serial.println(rNumR); 
    Serial.print("Green: ");
    Serial.println(rNumG) ;
    Serial.print("Blue: ");
    Serial.println(rNumB) ;
    analogWrite(red, rNumR);
    analogWrite(green, rNumG);
    analogWrite(blue, rNumB);
    delay(500);

    rNumR = random(1,100);
    rNumG = random(1,100);
    rNumB = random(1,100);
    tone(buzzerPin, NOTE_G5, 400); 
    Serial.print("Red: ");
    Serial.println(rNumR); 
    Serial.print("Green: ");
    Serial.println(rNumG) ;
    Serial.print("Blue: ");
    Serial.println(rNumB) ;
    analogWrite(red, rNumR);
    analogWrite(green, rNumG);
    analogWrite(blue, rNumB);
    delay(500);

    //11
    
    rNumR = random(1,100);
    rNumG = random(1,100);
    rNumB = random(1,100);
    tone(buzzerPin, NOTE_F5, 400); 
    Serial.print("Red: ");
    Serial.println(rNumR); 
    Serial.print("Green: ");
    Serial.println(rNumG) ;
    Serial.print("Blue: ");
    Serial.println(rNumB) ;
    analogWrite(red, rNumR);
    analogWrite(green, rNumG);
    analogWrite(blue, rNumB);
    delay(500);

    rNumR = random(1,100);
    rNumG = random(1,100);
    rNumB = random(1,100);
    tone(buzzerPin, NOTE_F5, 400); 
    Serial.print("Red: ");
    Serial.println(rNumR); 
    Serial.print("Green: ");
    Serial.println(rNumG) ;
    Serial.print("Blue: ");
    Serial.println(rNumB) ;
    analogWrite(red, rNumR);
    analogWrite(green, rNumG);
    analogWrite(blue, rNumB);
    delay(500);

    //12

    rNumR = random(1,100);
    rNumG = random(1,100);
    rNumB = random(1,100);
    tone(buzzerPin, NOTE_E5, 400); 
    Serial.print("Red: ");
    Serial.println(rNumR); 
    Serial.print("Green: ");
    Serial.println(rNumG) ;
    Serial.print("Blue: ");
    Serial.println(rNumB) ;
    analogWrite(red, rNumR);
    analogWrite(green, rNumG);
    analogWrite(blue, rNumB);
    delay(500);

    rNumR = random(1,100);
    rNumG = random(1,100);
    rNumB = random(1,100);
    tone(buzzerPin, NOTE_E5, 400); 
    Serial.print("Red: ");
    Serial.println(rNumR); 
    Serial.print("Green: ");
    Serial.println(rNumG) ;
    Serial.print("Blue: ");
    Serial.println(rNumB) ;
    analogWrite(red, rNumR);
    analogWrite(green, rNumG);
    analogWrite(blue, rNumB);
    delay(500);

    //13 

    rNumR = random(1,100);
    rNumG = random(1,100);
    rNumB = random(1,100);
    tone(buzzerPin, NOTE_DS8, 400); 
    Serial.print("Red: ");
    Serial.println(rNumR); 
    Serial.print("Green: ");
    Serial.println(rNumG) ;
    Serial.print("Blue: ");
    Serial.println(rNumB) ;
    analogWrite(red, rNumR);
    analogWrite(green, rNumG);
    analogWrite(blue, rNumB);
    delay(500);

    rNumR = random(1,100);
    rNumG = random(1,100);
    rNumB = random(1,100);
    tone(buzzerPin, NOTE_DS8, 400); 
    Serial.print("Red: ");
    Serial.println(rNumR); 
    Serial.print("Green: ");
    Serial.println(rNumG) ;
    Serial.print("Blue: ");
    Serial.println(rNumB) ;
    analogWrite(red, rNumR);
    analogWrite(green, rNumG);
    analogWrite(blue, rNumB);
    delay(500);

    rNumR = random(1,100);
    rNumG = random(1,100);
    rNumB = random(1,100);
    tone(buzzerPin, NOTE_D5, 400); 
    Serial.print("Red: ");
    Serial.println(rNumR); 
    Serial.print("Green: ");
    Serial.println(rNumG) ;
    Serial.print("Blue: ");
    Serial.println(rNumB) ;
    analogWrite(red, rNumR);
    analogWrite(green, rNumG);
    analogWrite(blue, rNumB);
    delay(500);

    rNumR = random(1,100);
    rNumG = random(1,100);
    rNumB = random(1,100);
    tone(buzzerPin, NOTE_D5, 400); 
    Serial.print("Red: ");
    Serial.println(rNumR); 
    Serial.print("Green: ");
    Serial.println(rNumG) ;
    Serial.print("Blue: ");
    Serial.println(rNumB) ;
    analogWrite(red, rNumR);
    analogWrite(green, rNumG);
    analogWrite(blue, rNumB);
    delay(500);

    //15
  }
}
    
    
