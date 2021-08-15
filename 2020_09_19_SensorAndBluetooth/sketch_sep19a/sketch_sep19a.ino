#include <CapacitiveSensor.h>
CapacitiveSensor cs_10_12= CapacitiveSensor(10,12); //10M Resistor between pins 7 and 8, you may also connect an antenna on pin 8
unsigned long csSum;

void setup() {
    Serial.begin(9600);
}

void loop() {
    CSread();
}

void CSread() {
    Serial.println("-"); 
    long cs = cs_10_12.capacitiveSensor(80); //a: Sensor resolution is set to 80
  if (cs > 100) { //b: Arbitrary number
    csSum += cs;
    Serial.println(cs); 
    if (csSum >= 3800) //c: This value is the threshold, a High value means it takes longer to trigger
    {
      Serial.print("Trigger: ");
      Serial.println(csSum);
      if (csSum > 0) { csSum = 0; } //Reset
      cs_10_12.reset_CS_AutoCal(); //Stops readings
    }
  } else {
    csSum = 0; //Timeout caused by bad readings
  }
}
