/*
 * This is some quick arduino code for a leonardo with a joystick shield
 * Basically allows you to use it as the game controller, either with joystick or with buttons
 */
#include "Keyboard.h"
char arr[]={'w','d','s','a','\b','\b','\n'};
void setup() {    
  Keyboard.begin();
  for(int i=2;i<9;i++)
    pinMode(i,INPUT);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
}
void loop() {
  if(analogRead(A1)>=768)
  {
    Keyboard.write('w');
    while(analogRead(A1)>=768);
  }  
  else if(analogRead(A1)<=256)
  {
    Keyboard.write('s');
    while(analogRead(A1)<=256);    
  }
  if(analogRead(A0)>=768)
  {
    Keyboard.write('d');
    while(analogRead(A0)>=768);
  }  
  else if(analogRead(A0)<=256)
  {
    Keyboard.write('a');
    while(analogRead(A0)<=256);    
  }
  for(int i=2;i<9;i++)
    if(digitalRead(i)==0)
    {
      Keyboard.write(arr[i-2]);
      delay(50);
      while(digitalRead(i)==0)
        Serial.print(i);
      delay(50);
    }
  }
