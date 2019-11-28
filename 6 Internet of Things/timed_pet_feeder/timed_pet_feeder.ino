/*      Name: Mark Song
 *      Date: Dec 1, 2018 Version 1 
        Title: Timed Pet Feeder
        Description: This program is a simple pet feeder that uses a servo motor to control a cap
*/
// inmporting servo library.
#include <Servo.h>
Servo servo;

// define timePassed , timeToFeed
int timePassed = 0;  // expressed in seconds, starts counter at 0,
int timeToFeed = 10; // expressed in seconds,  seconds to wait to feed the pet.

// Function to open cap
void openCap() {
  servo.write(0); // turns to 100 degree, which is dead center to close the cap.
  delay(500);
}

// function : closes cap
void closeCap() {
  servo.write(100); // turns to 45 degree, allowing the cap to be fully off and for food to flow out coompetely.
  delay(500);
}

void setup() {
  Serial.begin(9600);
  servo.attach(9); // attched servo 9 pin to servo.
  Serial.println("Feeding the pet in"); // announces to when the pet is being to be feeded in seconds. 
  Serial.print(timeToFeed);
  Serial.print("seconds");
}

void loop() {
  timePassed ++ ;  // using delay 1000 to make each second = 1 timer *(ON AVERGE)*
  delay(1000);
  Serial.println("Time Passed (Seconds):");
  Serial.println(timePassed);
  if (timePassed >= timeToFeed) {  // if time passed is over timeToFeed ... feed the pet.
    Serial.println("Is time to feed the pet: ") ;
    Serial.println("Opening....") ;
    openCap();                         //calls open function
    delay(500);
    Serial.println("Closing....") ;
    closeCap();                 // calls close function
    timePassed = 0;  // resets timePassed back to 0
  }
}
