
#include <CheapStepper.h>

CheapStepper stepperDigit (2,3,4,5); 
CheapStepper stepperAnalog (A1,A2,A3,A4); 

const int buttonPin = 12;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin
boolean moveClockwise = true;   


void setup() {

  stepperDigit.setRpm(20); 
  stepperAnalog.setRpm(20); 

  Serial.begin(9600); 

}

void loop() {

    stepperDigit.moveDegrees  (moveClockwise, 360);
    delay(10); // wait a sec
    stepperAnalog.moveDegrees  (moveClockwise, 360);
    delay(10); // wait a sec
   // stepperDigit.move  (moveClockwise, 100);
   // delay(10); // wait a sec
    //stepperAnalog.move  (moveClockwise, 100);
   // delay(10); // wait a sec

    
}
