
#include <CheapStepper.h>

//CheapStepper stepperDigit (2,3,4,5); 
CheapStepper stepperAnalog (A1,A2,A3,A4); 

const int ledPin =  13;      // the number of the LED pin
boolean moveClockwise = true;   


void setup() {

  stepperAnalog.setRpm(10); 
  /* Note: CheapStepper library assumes you are powering your 28BYJ-48 stepper
   * using an external 5V power supply (>100mA) for RPM calculations
   * -- don't try to power the stepper directly from the Arduino
   * 
   * accepted RPM range: 6RPM (may overheat) - 24RPM (may skip)
   * ideal range: 10RPM (safe, high torque) - 22RPM (fast, low torque)
   */
  Serial.begin(9600); 

}

void loop() {
    stepperAnalog.moveDegrees  (moveClockwise, 10);
}
