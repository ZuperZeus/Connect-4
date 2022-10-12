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

#include <iostream>
#include "Frame.h"
using namespace std;
void Frame::newBuffer()
{
	cout<<"\e[?1049h";
}
void Frame::upperLeft()
{
	cout<<"\e[;H";    
}
void Frame::delBuffer()
{
	cout<<"\e[?1049l";
}
void Frame::clear()
{
	upperLeft();
	cout<<"\e[2J";
}
string Frame::center(string text, int sz)
{    
	string res="";    
	for(int i=0;i<(cols-sz)/2;i++) res+=" ";
	return res+text;    
}
bool Frame::updateSize(int col,int row)
{
	if(row==rows&&col==cols)
		return false;
	cols=col;
	rows=row;
	return true;
}
void Frame::move(int x)
{
	//1=up;2=down;3=left;4=right
	if(sel==make_pair(-1,-1))
		sel=make_pair(0,0);
	else if(x==1)
		if(sel.second==-1)
			sel.second=xSize-1;
		else if(sel.second==0)
			sel.second=xSize-1;
		else
			sel.second-=1;
	else if(x==2)
		if(sel.second==-1)
			sel.second=0;
		else if(sel.second==xSize-1)
			sel.second=0;
		else
			sel.second+=1;
	else if(x==3)
		if(sel.first==-1)
			sel.first=ySize-1;
		else if(sel.first==0)
			sel.first=ySize-1;
		else
			sel.first-=1;
	else if(x==4)
		if(sel.first==-1)
			sel.first=0;
		else if(sel.first==ySize-1)
			sel.first=0;
		else
			sel.first+=1;
}
void Frame::printFrame(int col, int row)
{
	updateSize(col,row);
	printFrame();
}
