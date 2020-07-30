#include <Keyboard.h>
void setup() {
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  
  Keyboard.begin();
}

void loop() {
  int rebond = 50;
  //if the button is pressed

  while(digitalRead(2)==HIGH)
  {
    Keyboard.write(41);
    delay(rebond);
  }
 
 
   while(digitalRead(3)==HIGH)
  {
    Keyboard.write(33); //000112226666666677770002222111100001111111222222226666666662222222
    delay(rebond);
  }
    while(digitalRead(4)==HIGH)
  {
    Keyboard.write(64);
    delay(rebond);
  }
    while(digitalRead(6)==HIGH)
  {
    Keyboard.write(35);//33333333333333333333333333333333333333333333333333333333333333333333333300001111122222333333333333333333333333333333333333333334444333333333333
    delay(rebond);
  }
    while(digitalRead(7)==HIGH)
  {
    Keyboard.write(36);
    delay(rebond);
  }
    while(digitalRead(8)==HIGH)
  {
    Keyboard.write(37);
    delay(rebond);
  }
   while(digitalRead(9)==HIGH)
  {
    Keyboard.write(94);
    delay(rebond);
  }
    while(digitalRead(10)==HIGH)
  {
    Keyboard.write(38);
    delay(rebond);
  }
    while(digitalRead(11)==HIGH)
  {
    Keyboard.write(42);
    delay(rebond);
  }
    while(digitalRead(12)==HIGH)
  {
    Keyboard.write(40);
    delay(rebond);
  }
 
}
/*
 * 
 */
