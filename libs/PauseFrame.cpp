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
#include <vector>
#include <fstream>
#include <stdio.h>
#include "PauseFrame.h"
#include "SettingsFrame.h"
#include "StartFrame.h"
#include "ExitException.h"
using namespace std;
PauseFrame::PauseFrame()
{
	xSize=2;
	ySize=2;
	framestring="";
}
Frame * PauseFrame::select()
{
	if(sel.first==0&&sel.second==0)
	{
		//save
		//SettingsFrame::save();
		//copy temp to curr
		ifstream in;
		ofstream out;
		in.open("libs/txt/temp.txt",ios::binary);
		out.open("libs/txt/curr.txt",ios::binary);
		out<<in.rdbuf();
		in.close();
		out.close();
		sel.first=1;
		sel.second=1;
	}
	if(sel.first==1&&sel.second==0)
	{
		remove("libs/txt/temp.txt");
		//Home
		Frame *stf=new StartFrame();
		return stf;
	}
	if(sel.first==0&&sel.second==1)
	{
		remove("libs/txt/temp.txt");
		//term
		throw ExitException();
		return this;
	}
	if(sel.first==1&&sel.second==1)
	{
		//go back
		return SettingsFrame::getTempBoardFrame();
	}
	return this;
}
Frame * PauseFrame::esc()
{
	sel.first=0;
	sel.second=0;
	return select();
}
void PauseFrame::updateFrame()
{
	string title;
	if(cols>=47)
	{
		title="\n"+
		center("\e[48;5;82;30m                                               \e[0m\n",47)+
		center("\e[48;5;46;30m  ######      #     #     #   #####   #######  \e[0m\n",47)+
		center("\e[48;5;47;30m  #     #    # #    #     #  #     #  #        \e[0m\n",47)+
		center("\e[48;5;48;30m  #     #   #   #   #     #  #        #        \e[0m\n",47)+
		center("\e[48;5;49;30m  ######   #     #  #     #   #####   #####    \e[0m\n",47)+
		center("\e[48;5;50;30m  #        #######  #     #        #  #        \e[0m\n",47)+
		center("\e[48;5;51;30m  #        #     #  #     #  #     #  #        \e[0m\n",47)+
		center("\e[48;5;87;30m  #        #     #   #####    #####   #######  \e[0m\n",47)+
		center("\e[48;5;123;30m                                               \e[0m\n",47);
	}
	else if(cols>=31)
	{
		title="\n"+
		center("\e[48;5;46;30m   ____                        \e[0m\n",31)+
		center("\e[48;5;47;30m  |  _ \\ __ _ _   _ ___  ___   \e[0m\n",31)+
		center("\e[48;5;48;30m  | |_) / _` | | | / __|/ _ \\  \e[0m\n",31)+
		center("\e[48;5;49;30m  |  __/ (_| | |_| \\__ \\  __/  \e[0m\n",31)+
		center("\e[48;5;50;30m  |_|   \\__,_|\\__,_|___/\\___|  \e[0m\n",31)+
		center("\e[48;5;51;30m                               \e[0m\n",31);
	}
	else if(cols>=15)
	{
		title="\n"+
		center("\e[48;5;46;30m  _            \e[0m\n",15)+
		center("\e[48;5;48;30m |_)_.    _ _  \e[0m\n",15)+
		center("\e[48;5;49;30m | (_||_|_>(/_ \e[0m\n",15);
		center("\e[48;5;51;30m               \e[0m\n",15);
	}
	else
	{
		title="\n"+
		center("\e[48;5;46;30m         \e[0m\n",9)+
		center("\e[48;5;48;30m  Pause  \e[0m\n",9)+
		center("\e[48;5;51;30m         \e[0m\n",9);
	}
	int height=(rows-21)/2;
	int width=(cols*2/3)/2;
	if(height<9) height=9;
	if(width<33) height=33;
	string strarr[4][9]={{

	"           ",
	"     #     ",
	"     #     ",
	"  #  #  #  ",
	"   # # #   ",
	"    ###    ",
	"     #     ",
	"  #######  ",
	"           "},
	{
	"     #     ",
	"    # #    ",
	"   #   #   ",
	"  #     #  ",
	" #       # ",
	"##       ##",
	" #  ###  # ",
	" #  # #  # ",
	" #### #### "},
	{
	"           ",
	" #         ",
	"  #        ",
	"   #       ",
	"    #      ",
	"   #       ",
	"  #        ",
	" #         ",
	"   ####### "},
	{
	"           ",
	"###########",
	"# # # # # #",
	"###########",
	"# # # # # #",
	"###########",
	"# # # # # #",
	"###########",
	"           "}};
	string ssel="\e[30;5m";
	string nsel="\e[97m";
	string menu="";
	string cen="";
	for(int i=0;i<(width-11)/2;i++)
		cen+=" ";
	for(int i=0;i<(rows-30)/2;i++)
		menu+="\n";
	for(int j=0;j<9;j++)
	{
		menu+=center("",(width*2));
		if(sel.first==0&&sel.second==0)
			menu+="\e[7;5m";
		menu+="\e[102;30m";
		menu+=cen;
		menu+=strarr[0][j];
		menu+=cen;
		menu+="\e[0m";
		if(sel.first==1&&sel.second==0)
			menu+="\e[7;5m";
		menu+="\e[107;30m";
		menu+=cen;
		menu+=strarr[1][j];
		menu+=cen;
		menu+="\e[0m\n";
	}
	for(int j=0;j<9;j++)
	{
		menu+=center("",(width*2));
		if(sel.first==0&&sel.second==1)
			menu+="\e[7;5m";
		menu+="\e[101;30m";
		menu+=cen;
		menu+=strarr[2][j];
		menu+=cen;
		menu+="\e[0m";
		if(sel.first==1&&sel.second==1)
			menu+="\e[7;5m";
		menu+="\e[104;30m";
		menu+=cen;
		menu+=strarr[3][j];
		menu+=cen;
		menu+="\e[0m\n";
	}
	framestring=title+menu+"\n";
}
void PauseFrame::printFrame()
{
	updateFrame();
	this->clear();
	cout<<framestring;
}
