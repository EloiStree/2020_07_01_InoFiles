
#include <CheapStepper.h>

CheapStepper stepper (2,3,4,5); 

const int buttonPin = 12;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin
boolean moveClockwise = true;
int buttonState = 0;
bool isActive=true;         

void setup() {
  buttonState= isActive;
 // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  // let's set a custom speed of 20rpm (the default is ~16.25rpm)
  
  stepper.setRpm(10); 
  /* Note: CheapStepper library assumes you are powering your 28BYJ-48 stepper
   * using an external 5V power supply (>100mA) for RPM calculations
   * -- don't try to power the stepper directly from the Arduino
   * 
   * accepted RPM range: 6RPM (may overheat) - 24RPM (may skip)
   * ideal range: 10RPM (safe, high torque) - 22RPM (fast, low torque)
   */

  // now let's set up a serial connection and print some stepper info to the console
  
  Serial.begin(9600); Serial.println();
  Serial.print(stepper.getRpm()); // get the RPM of the stepper
  Serial.print(" rpm = delay of ");
  Serial.print(stepper.getDelay()); // get delay between steps for set RPM
  Serial.print(" microseconds between steps");
  Serial.println();
  
  // stepper.setTotalSteps(4076);
  /* you can uncomment the above line if you think your motor
   * is geared 63.68395:1 (measured) rather than 64:1 (advertised)
   * which would make the total steps 4076 (rather than default 4096)
   * for more info see: http://forum.arduino.cc/index.php?topic=71964.15
   */
}

void loop() {

bool previousState = buttonState;
 buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH && previousState!= buttonState) {
    // turn LED on:
    isActive=!isActive;
    digitalWrite(ledPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }

  
     moveClockwise = true;
    if(isActive)
       stepper.moveDegrees  (true, 5);
    Serial.print("step position: ");  
    Serial.print(stepper.getStep()); // get the current step position
    Serial.print(" / 4096");
    Serial.println();
    //delay(3000); // wait a sec
   // stepper.moveDegrees  (false, 360);
    
}
