/*
        Name : Mark Song
        Title: 321Maker Experiment #011 - LCD
        Description: This program will display 321Maker on the serial LCD.
        Tutorial:  http://321maker.com/e/011-lcd
        Revision Date: October 12, 2016
        Licence: http://321maker.mit-license.org/
        Requirements:  Arduino with 321Maker Shield, 1602 Serial LCD
        Serial LCD library: https://bitbucket.org/fmalpartida/new-liquidcrystal/downloads/NewliquidCrystal_1.3.4.zip
*/
//Load libraries
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

int button1Pin = 2;    //The SW1 button is connect to pin 2 of the Arduino.
int button2Pin = 3;    //The SW2 button is connect to pin 3 of the Arduino.
int x = 0; //counter
int y = 0; // counter 2


//Define address for the Serial LCD display.
#define I2C_ADDR  0x3f  //If 0x3f doesn't work change this to 0x27
#define BACKLIGHT_PIN  3

//Initialise the Serial LCD.
LiquidCrystal_I2C lcd(I2C_ADDR, 2, 1, 0, 4, 5, 6, 7); //These pin numbers are hard coded in on the serial backpack board.

void setup()
{
  lcd.begin (16, 2);    //Initalize the LCD.
  lcd.setBacklightPin(3, POSITIVE); //Setup the backlight.
  lcd.setBacklight(HIGH); //Switch on the backlight.
  Serial.begin(9600);
  pinMode(button1Pin, INPUT);  //Setup button1 pin as an input pin.
  pinMode(button2Pin, INPUT);  //Setup button2 pin as an input pin.
}

void loop() {


  // if button 2 is pressed counter + 1 ( y + 1 )
  if (digitalRead(button1Pin) == LOW) {
    y ++ ;
  }

  // if y is 0 prints my name,
  if (y == 0 ) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Mark Song");
    delay(500);
  }

  // if y is 1 prints my hobby,
  if (y == 1 ) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("I like Collectin");
    lcd.setCursor(0, 1);
    lcd.print("Sea-Shells");
    delay(500);
  }

  // if y is 2 prints what i had for lunch.
  if (y == 2 ) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("I Had Ramen ");
    lcd.setCursor(0, 1);
    lcd.print("For Lunch");
    delay(500);
  }

  //if y is 3 resets the counter(y) back to 0
  if (y == 3 ) {
    y == 0 ;
  }
}
