#include <CapacitiveSensor.h>

/*
 * CapitiveSense Library Demo Sketch
 * Paul Badger 2008
 * Uses a high value resistor e.g. 10M between send pin and receive pin
 * Resistor effects sensitivity, experiment with values, 50K - 50M. Larger resistor values yield larger sensor values.
 * Receive pin is the sensor pin - try different amounts of foil/metal on this pin
 */


CapacitiveSensor   cs_10_12 = CapacitiveSensor(4,8);        // 10M resistor between pins 4 & 8, pin 8 is sensor pin, add a wire and or foil
 float m_capacitiveValue=30;
 float m_maxResistanceTouchValue=40000;
 float m_maxTouchValue=280000;


void setup()                    
{
  // cs_10_12.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
   Serial.begin(9600);
}

void loop()                    
{
    long start = millis();
    long total3 =  cs_10_12.capacitiveSensor(m_capacitiveValue);
bool hasDirectContact;
float resistanceTouchingPourcent;
float touchingPourcent;
    Serial.println("");
    Serial.print("T");
    Serial.print(millis() - start);        // check on performance in milliseconds
    Serial.print("\t");                    // tab character for debug windown spacing

    Serial.print("\tV");
    Serial.print(total3);

    resistanceTouchingPourcent =((float)total3)/m_maxResistanceTouchValue;
    touchingPourcent= ((float)total3)/m_maxTouchValue;
    
    if(resistanceTouchingPourcent>=1)
      resistanceTouchingPourcent=0.99;
    if(touchingPourcent>=1)
      touchingPourcent=0.99;
hasDirectContact = touchingPourcent>0.5f;
      
    Serial.print("\tRP");
    Serial.print(resistanceTouchingPourcent);    
    Serial.print("\tTP");
    Serial.print(touchingPourcent);                // print sensor output 3

    Serial.println("");
    Serial.print("#");                // print sensor output 3
    Serial.print(hasDirectContact);                // print sensor output 3
    Serial.print("|");                // print sensor output 3
    Serial.print((int)(resistanceTouchingPourcent*10));                // print sensor output 3
    delay(10);                             // arbitrary delay to limit data to serial port 
}
