
#include <CheapStepper.h>

CheapStepper stepperDigit (2,3,4,5); 
CheapStepper stepperAnalog (A1,A2,A3,A4); 

const int buttonPin = 12;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin
boolean moveClockwise = true;   

bool aMoveClockwise = true;
unsigned long aMoveStartTime = 0; // this will save the time (millis()) when we started each new move
bool dMoveClockwise = true;
unsigned long dMoveStartTime = 0; // this will save the time (millis()) when we started each new move


void setup() {

  stepperDigit.setRpm(10); 
  stepperAnalog.setRpm(10); 
  /* Note: CheapStepper library assumes you are powering your 28BYJ-48 stepper
   * using an external 5V power supply (>100mA) for RPM calculations
   * -- don't try to power the stepper directly from the Arduino
   * 
   * accepted RPM range: 6RPM (may overheat) - 24RPM (may skip)
   * ideal range: 10RPM (safe, high torque) - 22RPM (fast, low torque)
   */

  Serial.begin(9600); 
  Serial.println("Test");

  // stepperDigit.setTotalSteps(4076);
  /* you can uncomment the above line if you think your motor
   * is geared 63.68395:1 (measured) rather than 64:1 (advertised)
   * which would make the total steps 4076 (rather than default 4096)
   * for more info see: http://forum.arduino.cc/index.php?topic=71964.15
   */
  stepperDigit.newMoveTo(moveClockwise, 2048);
  stepperAnalog.newMoveTo(moveClockwise, 2048);
}

void loop() {

    //stepperDigit.moveDegrees  (moveClockwise, 10);
    //stepperAnalog.moveDegrees  (moveClockwise, 10);
    //stepperDigit.move  (moveClockwise, 100);
    //stepperAnalog.move  (moveClockwise, 100);
  
    delay(10); // wait a sec



stepperDigit.run();
stepperAnalog.run();

  ////////////////////////////////
  // now the stepper is moving, //
  // let's do some other stuff! //
  ////////////////////////////////

  
  int stepsLeft = stepperDigit.getStepsLeft();
  
  if (stepsLeft == 0){
    unsigned long timeTook = millis() - dMoveStartTime; 
    dMoveClockwise = !dMoveClockwise; 
    stepperDigit.newMoveDegrees (dMoveClockwise, 180); // move 180 degrees from current position
    dMoveStartTime = millis(); // reset move start time

  }

   stepsLeft = stepperAnalog.getStepsLeft();

  if (stepsLeft == 0){

    unsigned long timeTook = millis() - aMoveStartTime; 
    aMoveClockwise = !aMoveClockwise; // reverse direction
    stepperAnalog.newMoveDegrees (aMoveClockwise, 180); // move 180 degrees from current position
    aMoveStartTime = millis(); // reset move start time

  }

    
}
