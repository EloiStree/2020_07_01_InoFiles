// defines pins numbers
const int stepPin = 3; 
const int dirPin = 4; 
const int enablePin = 7; 
const int ledPin = 13; 
 
void setup() {


  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  digitalWrite(enablePin,LOW);
  digitalWrite(enablePin,LOW);
  digitalWrite(enablePin,LOW);
  
  // Sets the two pins as Outputs
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  pinMode(ledPin,OUTPUT);
  pinMode(enablePin,OUTPUT);
  //digitalWrite(enablePin,HIGH);
  // digitalWrite(enablePin,LOW);
}
void loop() {
  digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation

    digitalWrite(ledPin,HIGH); 
  
  for(int x = 0; x <200; x++) {
    if(x==0)
    digitalWrite(ledPin,HIGH); 
    if(x==100)
    digitalWrite(ledPin,LOW); 
  //  digitalWrite(ledPin,HIGH); 
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(5000 ); 
   // digitalWrite(ledPin,LOW);
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(5000);
  }
    digitalWrite(ledPin,LOW);
  //delay(1); // One second delay
  
 // digitalWrite(dirPin,LOW); //Changes the rotations direction
  // Makes 400 pulses for making two full cycle rotation
 /*
 for(int j = 0; j < 100; j++) { 
    for(int x = 0; x < 20; x++) {
      digitalWrite(stepPin,HIGH);
      delayMicroseconds(500);
      digitalWrite(stepPin,LOW);
      delayMicroseconds(500);
    }
    delay(1000);
  }
  */
}
