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
SensorState  m_sensors[]= {

   //
   SensorState(true,1 ,0 ,100,6000, CapacitiveSensor(13,12)),//
   //
   SensorState(true,1 ,0 ,100,6000, CapacitiveSensor(A0,9)),//
   //
   SensorState(true,1 ,0 ,100,6000, CapacitiveSensor(8,A1)),//
   //
   SensorState(true,1 ,0 ,100,6000, CapacitiveSensor(A2,7)),//
   //
   SensorState(true,1 ,0 ,100,6000, CapacitiveSensor(6,A3)),//
   //
   SensorState(true,1 ,0 ,100,6000, CapacitiveSensor(A4,5)),//
   //
   SensorState(true,1 ,0 ,100,6000, CapacitiveSensor(A5,4)),//
 
    //deac 
  //SensorState(false,30 ,0 ,200,6000, CapacitiveSensor(3,2)),//10Mo
   
  } ;

const int analogCount=6;
int analog[]= {A0,A1,A2,A3,A4,A5};
int analogValue[analogCount];
bool useDebug=false;
bool useCompressSerial=true;


void setup()                    
{
  // cs_10_12.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
   Serial.begin(9600);

  for (int i =0; i< analogCount; i++){
   // pinMode(analog[i],INPUT_PULLUP);
  }
  for(int i = 0; i<m_numberOfSensors; i++){
   // m_sensors[i].m_sensor.set_CS_AutocaL_Millis(0xFFFFFFFF);; 
 }
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop()                    
{
  /*

if (Serial.available() > 0) {
    // read the incoming byte:
    char c = Serial.read();

    // say what you got:
    Serial.print("I received: ");
    Serial.println(c, DEC);
    if(c=='1') digitalWrite(LED_BUILTIN, HIGH);
    if(c=='0') digitalWrite(LED_BUILTIN, LOW);
    
  }*/
for(int i = 0; i<m_numberOfSensors; i++){
    m_sensors[i].setLastReturnValue(0); 
 }
 
 for(int i = 0; i<m_numberOfSensors; i++){
 if(m_sensors[i].m_listenToIt){
    long start = millis();
    long value =  m_sensors[i].m_sensor.capacitiveSensor(m_sensors[i].m_capacitiveValue);
    m_sensors[i].setLastReturnValue(value); 
     
    //Serial.println("");
    //Serial.print(" -v ");
    //Serial.print(value);
    //Serial.print(" -t ");  
    //Serial.print((millis() - start)); 
    
  }else      m_sensors[i].setLastReturnValue(0); 
 }
   
//*/
 // /*  
 if(useDebug){
  
 for(int i = 0; i<m_numberOfSensors; i++){
    Serial.print("\ni"); 
    Serial.print(i); 
    Serial.print("\t");
    Serial.print("\tVal");
    Serial.print( m_sensors[i].m_returnedValue);  
    Serial.print("\t");
    Serial.print("\tRP");
    Serial.print( m_sensors[i].getPourcentResistanceState());    
    Serial.print("\tTP");
    Serial.print( m_sensors[i].getPourcentContactState());   
  }
  }
  //*/
              // print sensor output 3
   // /*          
    Serial.println("");
    if(useCompressSerial)
    {
      
      Serial.print("#");                
    
    for(int i = 0; i<m_numberOfSensors; i++){
     //   Serial.print( m_sensors[i].getPourcentContactState()>0.5f);   
     }
    Serial.print("|"); 
   for(int i = 0; i<m_numberOfSensors; i++){
      Serial.print( m_sensors[i].getShortResistanceValue());   
    } 
    }// print sensor output 3


/*//


 for (int i =0; i< analogCount; i++){
  
    analogValue[i] = analogRead(analog[i])/104;
    Serial.print((analogValue[i]));
   
  }



  
    //*/
    delay(20);                             // arbitrary delay to limit data to serial port 
}
