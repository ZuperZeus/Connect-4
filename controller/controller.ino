/*
 *  Connect-4, a terminal GUI with a min-max AI for the classic board game of the same name.
 *  Copyright (C) 2022 ZuperZeus
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

//This is some quick arduino code for a leonardo with a joystick shield
//Basically allows you to use it as the game controller, either with joystick or with buttons

#include "Keyboard.h"
char arr[]={'s','a','w','d','\n','x','\n'};
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
    Keyboard.write('s');
    while(analogRead(A1)>=768);
  }  
  else if(analogRead(A1)<=256)
  {
    Keyboard.write('w');
    while(analogRead(A1)<=256);    
  }
  if(analogRead(A0)>=768)
  {
    Keyboard.write('a');
    while(analogRead(A0)>=768);
  }  
  else if(analogRead(A0)<=256)
  {
    Keyboard.write('d');
    while(analogRead(A0)<=256);    
  }
  for(int i=2;i<9;i++)
    if(digitalRead(i)==0)
    {
      Keyboard.write(arr[i-2]);
      delay(50);
      while(digitalRead(i)==0);
      delay(50);
    }
  }
