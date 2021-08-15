
 int buttonCount =11;
 int buttonPin[] = {33,35,37,39,41,43,45,47,49,51,53}   ;

void setup() {
  Serial.begin(9600);
  for(int i=0; i< buttonCount;i++){
      pinMode(buttonPin[i], INPUT_PULLUP);
  }
}

void loop() {
  Serial.println("");
  Serial.print("#"); 
  for(int i=0; i< buttonCount;i++){
    int v= digitalRead(buttonPin[i]);
    Serial.print( v==0?"1":"0");
  }
  Serial.print("|");
  delay(10);
}
