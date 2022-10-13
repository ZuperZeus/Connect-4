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
#include "StartFrame.h"
#include "SettingsFrame.h"
#include "ExitException.h"
using namespace std;
StartFrame::StartFrame()
{
	xSize=2;
	ySize=2;
	framestring="";
}
Frame * StartFrame::select()
{
	if(sel.first==0&&sel.second==0)
	{
		//ai
		return SettingsFrame::getDefaultBoardFrameAI();
	}
	if(sel.first==1&&sel.second==0)
	{
		//1v1
		return SettingsFrame::getDefaultBoardFrame();
	}
	if(sel.first==0&&sel.second==1)
	{
		//saved
		//SavedFrame *sf=new SavedFrame()
		//return sf;
		return this;
	}
	if(sel.first==1&&sel.second==1)
	{
		//settings
		Frame *sf=new SettingsFrame();
		return sf;
	}
	return this;
}
Frame * StartFrame::esc()
{
	//system("tput cvvis");
	//Frame::delBuffer();
	//exit(0);
	throw ExitException();
	return this;
}
void StartFrame::updateFrame()
{
	string title;
	if(cols>=65)
	{
		title="\n"+
		center("\e[48;5;82;30m                                                                 \e[0m\n",65)+
		center("\e[48;5;46;30m  #     #  #######  #         #####   #######  #     #  #######  \e[0m\n",65)+
		center("\e[48;5;47;30m  #  #  #  #        #        #     #  #     #  ##   ##  #        \e[0m\n",65)+
		center("\e[48;5;48;30m  #  #  #  #        #        #        #     #  # # # #  #        \e[0m\n",65)+
		center("\e[48;5;49;30m  #  #  #  #####    #        #        #     #  #  #  #  #####    \e[0m\n",65)+
		center("\e[48;5;50;30m  #  #  #  #        #        #        #     #  #     #  #        \e[0m\n",65)+
		center("\e[48;5;51;30m  #  #  #  #        #        #     #  #     #  #     #  #        \e[0m\n",65)+
		center("\e[48;5;87;30m   ## ##   #######  #######   #####   #######  #     #  #######  \e[0m\n",65)+
		center("\e[48;5;123;30m                                                                 \e[0m\n",65);
	}
	else if(cols>=44)
	{
		title="\n"+
		center("\e[48;5;46;30m __        __   _                           \e[0m\n",44)+
		center("\e[48;5;47;30m \\ \\      / /__| | ___ ___  _ __ ___   ___  \e[0m\n",44)+
		center("\e[48;5;48;30m  \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\ \e[0m\n",44)+
		center("\e[48;5;49;30m   \\ V  V /  __/ | (_| (_) | | | | | |  __/ \e[0m\n",44)+
		center("\e[48;5;50;30m    \\_/\\_/ \\___|_|\\___\\___/|_| |_| |_|\\___| \e[0m\n",44)+
		center("\e[48;5;51;30m                                            \e[0m\n",44);
	}
	else if(cols>=24)
	{
		title="\n"+
		center("\e[48;5;46;30m \\    /_ | _ _ ._ _  _  \e[0m\n",24)+
		center("\e[48;5;51;30m  \\/\\/(/_|(_(_)| | |(/_ \e[0m\n",24);
	}
	else
	{
		title="\n"+
		center("\e[48;5;46;30m           \e[0m\n",11)+
		center("\e[48;5;48;30m  Welcome  \e[0m\n",11)+
		center("\e[48;5;51;30m           \e[0m\n",11);
	}
	int height=(rows-21)/2;
	int width=(cols*2/3)/2;
	if(height<9) height=9;
	if(width<33) height=33;
	string strarr[4][9]={{

	"           ",
	"   #    ###",
	"  # #    # ",
	" #   #   # ",
	"#     #  # ",
	"#######  # ",
	"#     #  # ",
	"#     # ###",
	"           "},
	{
	"           ",
	"# #     # #",
	"# #     # #",
	"# #     # #",
	"# #     # #",
	"#  #   #  #",
	"#   # #   #",
	"#    #    #",
	"           "},
	{
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
	"           ",
	"     #     ",
	"  # ### #  ",
	"   #   #   ",
	" ##  #  ## ",
	"   #   #   ",
	"  # ### #  ",
	"     #     ",
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
		menu+="\e[101;30m";
		menu+=cen;
		menu+=strarr[0][j];
		menu+=cen;
		menu+="\e[0m";
		if(sel.first==1&&sel.second==0)
			menu+="\e[7;5m";
		menu+="\e[104;30m";
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
		menu+="\e[102;30m";
		menu+=cen;
		menu+=strarr[2][j];
		menu+=cen;
		menu+="\e[0m";
		if(sel.first==1&&sel.second==1)
			menu+="\e[7;5m";
		menu+="\e[103;30m";
		menu+=cen;
		menu+=strarr[3][j];
		menu+=cen;
		menu+="\e[0m\n";
	}
	framestring=title+menu;
}
void StartFrame::printFrame()
{
	updateFrame();
	this->clear();
	cout<<framestring;
}
