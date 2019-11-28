/************************************************************************************************************************
* Program Name: Thing Speak Read and Write - Proof of Concept                                                           *
* Description: Using the ESP8266, connect to ThingSpeak.com, read the latest value from field 1, turn the red LED on or *    
*              off based on value found, then write back to Thing Speak the opposite value.                             *
* Instructions: Enter your wifi credentials into the space below. Then enter your Thing Speak channel and API keys into *
*               the following spaces. Make sure your Thing Speak channel has field 1 available and that it's most       *
*               recent entry is either a 0 or a 1.                                                                      *
* Author: Mark Song                                                                                                *
* Last Edit: 11/15/18                                                                                                   *
************************************************************************************************************************/

/************************************************
      ENTER WIFI ACCESS POINT CREDENTIALS
*************************************************/
String wifiUser = "iPhone";
String wifiPass = "ms0917abc";
/************************************************
      ENTER WIFI ACCESS POINT CREDENTIALS
*************************************************/

/************************************************
         ENTER THING SPEAK CREDENTIALS
*************************************************/
String writeAPIKey = "P97PYD0LVSKDG1TT";
String readAPIKey = "0IT0WJCAI1UI1O2V";
String channel = "628705";
/************************************************
         ENTER THING SPEAK CREDENTIALS
*************************************************/




/************************************************
*************************************************
*********DO NOT EDIT PAST THIS POINT*************
*************************************************
*************************************************/

//////////////VARIABLES//////////////

char readData[10] = "0000000000";   //Used to store data read from Thing Speak.
int RGBRedPin = 9;    //Stores value of red LED Pin number.
bool waiting = false;   //Used to check if a function is currently executing.

#define TIMER   1000    //Global value for milliseconds to wait between actions.
#define DST_IP    "api.thingspeak.com"    //Address to connect to.

//////////////FUNCTIONS//////////////

//Used to connect to your entered wifi credentials.
bool wifiConnect(String user, String pass){
  String cmd = "AT+CWJAP=\""; cmd += user; cmd += "\",\""; cmd += pass; cmd += "\"";    //Builds serial command for wifi connection.
  cmdExecute(cmd, 4);   //Send built command to the command executor function. Integer value is a multiplier for the global wait time.
  delay(500);   //Wait briefly before continuing.
  while(waiting);   //Make sure any previous functions have finished executing before continuing. (Maybe not necessary. Was having issues with serial commands getting mixed up so it stays for now)
}

//Used to connect to Thing Speak.
void connectTCP(){
  String cmd = "AT+CIPSTART=\"TCP\",\""; cmd += DST_IP; cmd += "\",80";   //Builds serial command for TCP connection to Thing Speak.
  cmdExecute(cmd, 1);
  delay(500);
  while(waiting);
}

//Pre request send. Sends how large the following request will be.
void startRequest(int data){
  String cmd = "AT+CIPSEND="; cmd += data;
  cmdExecute(cmd, 1);
  delay(500);
  while(waiting);
}

//Builds and sends a request to write the specified value to the specified field.
void sendWriteRequest(byte field, int value){
  connectTCP();   //Connection to Thing Speak is established first.
  delay(500);
  while(waiting);
  //Build the request
  String cmd = "GET /update?api_key="; cmd += writeAPIKey+"&field1="; cmd += value; cmd += " HTTP/1.1\r\n"; cmd += "Host: api.thingspeak.com\n"; cmd += "Connection: closed\r\n\r\n";
  startRequest(cmd.length());   //Start the request using the size of the request to be sent.
  delay(500);
  while(waiting);
  cmdExecute(cmd, 1);   //Send the request.
  delay(500);
  while(waiting);
}

//Builds and sends a request to read the most recent value from a specified field.
void sendReadRequest(byte field){
  connectTCP();   //Connection to Thing Speak is established first.
  delay(500);
  while(waiting);
  //Build the request
  String cmd = "GET /channels/"; cmd+= channel; cmd += "/fields/"; cmd += field; cmd += "/last.json?api_key="; cmd += readAPIKey; cmd += " HTTP/1.1\r\n"; cmd += "Host: api.thingspeak.com\n"; cmd += "Connection: closed\r\n\r\n";
  startRequest(cmd.length());   //Start the request using the size of the request to be sent.
  delay(500);
  while(waiting);
  pullData(cmd, 1, 1);    //Send the request and pull out the value of the field.
  delay(500);
  while(waiting);
}

//Executes commands while displaying all information to the serial monitor.
void cmdExecute(String cmd, int mult){
  clearBuffer();    //Write out any characters left in the buffer.
  waiting = true;   //Command is executing; set waiting to true to prevent early execution of other functions.
  unsigned long deadline = millis() + TIMER * mult;   //Set the deadline for characters to be found.
  Serial1.println(cmd);   //Execute the command.
  while(millis() < deadline){   //Continues to execute as long as the deadline has not been passed.
    if(Serial1.available() > 0){    //Only true if there are characters to be read in the serial monitor.
      Serial.write(Serial1.read());   //Write the available characters to the serial monitor.
      deadline = millis() + TIMER * mult;   //Since a character was found, reset the deadline.
    }
  }
  waiting = false;    //Execution is finished so other functions can proceed.
}

//Executes commands while displaying all information to the serial monitor and saving the relevant values. (Can probably merge with cmdExecute eventually)
void pullData(String cmd, int field, int mult){
  byte matchCount = 0;    //Used to track how many of the key characters have been matched in succession.
  byte dataCount = 0;   //Used to increment the character index of readData to store multiple values.
  char storage = "0";   //Temporary storage for the current character being read.
  String key = "\"field"; key += field; key += "\":\"";   //Field data will always follow this string. Used to isolate the value of the field.
  
  clearBuffer();
  waiting = true;
  unsigned long deadline = millis() + TIMER * mult;
  Serial1.println(cmd);
  while(millis() < deadline){
    if(Serial1.available() > 0){
      storage = Serial1.read();   //Store the current character into storage.
      Serial.write(storage);    //Write the character in storage to the serial monitor.
      //Check if the character in storage is equal to the character in the key at the current number of matches found. If so, increase the number of matches found. If not, reset the matches found.
      if(storage == key[matchCount]){
        matchCount++;
      }
      else{
        matchCount = 0;
      }
      deadline = millis() + TIMER * mult;   //Reset the deadline since a character was found.
      while(matchCount == key.length()){    //Start this execution once we have matched the enitre key.
        if(Serial1.available() > 0){    //Proceed if there are characters available.
          storage = Serial1.read();
          Serial.write(storage);
          if(storage != 34){    //If the value being read isn't 34 (or " in ascii) add the value to the readData and increment the index of readData for any additional values.
            readData[dataCount] = storage;
            dataCount++;
          }
          else{   //If the value is 34 it signifies the end of the field data. Reset the match counter and clean out the buffer.
            matchCount = 0;
            clearBuffer();
          }
        }
      }
    }
  }
  Serial.println("HERE IS THE DATA: ");   //Prints the read value to the serial monitor. (Not necessary, just for your own visuals)
  Serial.println(readData[0]);
  waiting = false;
}

//Used to read and write out any characters that may be left in the buffer.
void clearBuffer(){
  waiting = true;
  unsigned long deadline = millis() + TIMER;
  while(millis() < deadline){
    if(Serial1.available() > 0){
      Serial.write(Serial1.read());
      deadline = millis() + TIMER;
    }
  }
  waiting = false;
}

//Test function to display reading and writing from Thing Speak. Reads the value from field 1 on Thing Speak, then checks if it is 0 or 1. Then turns the LED on or off and sets the value to the opposite it read.
void RTest(){
  sendReadRequest(1);
  int data = 0;
  data = analogRead(A0);  //Read the value from the light sensor and store it in the lightData variable.
  data = data / 4 ;
  data = map(data, 0, 255, 0, 100);
  Serial.println(data);
 
    delay(1000);
    sendWriteRequest(1,data);
  
}


int rotationPin = A0; //The rotation sensor is plugged into pin A0 of the Arduino.
int data = 0;         //Used to store data from sensor.
////////////////SETUP////////////////

void setup() {
  Serial.begin(9600);   //Start the serial for the Arduino.
  Serial1.begin(115200);    //Start the serial for the ESP8266.
  pinMode(RGBRedPin, OUTPUT);   //Setup the red LED pin as an output pin.
  delay(1000);
  clearBuffer();    //Empty the buffer before starting.
  wifiConnect(wifiUser,wifiPass);   //Connect to the wifi.

     
}

//////////////MAIN LOOP//////////////

void loop() {
  RTest(); 
  delay(1000);
}
