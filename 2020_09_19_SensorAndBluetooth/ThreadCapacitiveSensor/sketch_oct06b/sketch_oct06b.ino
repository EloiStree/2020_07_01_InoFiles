 #include <CapacitiveSensor.h>

/*
 * CapitiveSense Library Demo Sketch
 * Paul Badger 2008
 * Uses a high value resistor e.g. 10M between send pin and receive pin
 * Resistor effects sensitivity, experiment with values, 50K - 50M. Larger resistor values yield larger sensor values.
 * Receive pin is the sensor pin - try different amounts of foil/metal on this pin
 */
class SensorState{
  public:
  float m_returnedValue=-2;
  float m_capacitiveValue=60;
  float m_minResistance=1;
  float m_maxResistanceValue=1;
  float m_maxDirectContactValue=1;
  bool m_listenToIt=false;
  CapacitiveSensor m_sensor= CapacitiveSensor(4,5);
    SensorState(bool listenToIt, float capacitive,float startResistance,float resistance, float contact,  CapacitiveSensor sensor){
    m_capacitiveValue = capacitive;
    m_maxResistanceValue = resistance;
    m_maxDirectContactValue = contact;
    m_listenToIt = listenToIt;
    m_sensor = sensor;
    }
   SensorState( CapacitiveSensor sensor){
    m_sensor = sensor;
    }
  
  void setLastReturnValue(float value){
       m_returnedValue= value;
    }
  float getPourcentResistanceState(){
       return  m_returnedValue/m_maxResistanceValue;
    
   }float getPourcentContactState(){
       return  m_returnedValue/m_maxDirectContactValue;
   }
    short getShortResistanceValue(){
      float v =getPourcentResistanceState();
      if( v>0.99)
         v=0.99;
      return (short)(v*10);}
      
      short getShortContactValue(){
      float v =getPourcentContactState();
      if( v>0.99)
        v=0.99;
      return (short)(v*10);
      }

    bool hasDirectContact(){
      return getPourcentContactState()>0.2;
    }
    bool hasLightResistance(){
      return getPourcentResistanceState()>0.25;
    } 
    bool hasMediumResistance(){
      return getPourcentResistanceState()>0.5;
    } 
    bool hasHardResistance(){
      return getPourcentResistanceState()>0.8;
    }
  
  };

int m_numberOfSensors =7;
SensorState a=SensorState(true,200 ,0 ,100,6000, CapacitiveSensor(4,7));
SensorState b=SensorState(true,20 ,0 ,100,6000, CapacitiveSensor(7,4));


int frame=0;
int frameDelay=1000;

void setup()                    
{
   Serial.begin(9600);
    pinMode(LED_BUILTIN, OUTPUT);
}


void loop()                    
{
  frame++;
  SensorState s = SensorState(true,20 ,0 ,100,6000, CapacitiveSensor(4,7));//frame%2==0?a:b;
  s.setLastReturnValue(0); 

    Serial.print(frame);
    Serial.print("->");
    Serial.println();
  ProcessSensor(s);
    delay(frameDelay);
    s =   SensorState(true,20 ,0 ,100,6000, CapacitiveSensor(7,4));
  ProcessSensor(s);   
    delay(frameDelay);                          
}

void ProcessSensor(SensorState s){
    long start = millis();
    long value =  s.m_sensor.capacitiveSensor(s.m_capacitiveValue);
    s.setLastReturnValue(value); 
     
    Serial.print(" -v ");
    Serial.print(value);
    Serial.print(" -t ");  
    Serial.print((millis() - start));
   DebugSensor(s);
    Serial.println();
  
  }

void  DebugSensor(SensorState sensor){
    Serial.print("\tS");
      Serial.print( sensor.getShortResistanceValue()); 
    Serial.print("\t");
    Serial.print("\tVal");
    Serial.print( sensor.m_returnedValue);  
    Serial.print("\t");
    Serial.print("\tRP");
    Serial.print( sensor.getPourcentResistanceState());    
    Serial.print("\tTP");
    Serial.print( sensor.getPourcentContactState()); 
  }
