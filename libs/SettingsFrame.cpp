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
#include "SettingsFrame.h"
#include "BoardFrame.h"
using namespace std;
/*
 * File Structure:
 * AI difficulty (1-10)
 * player 1 string
 * player 2 string
 * frame string
 * selected frame string
 * winner color string
 */
SettingsFrame::SettingsFrame()
{
	xSize=6;
	ySize=10;
	options.resize(6);
	indexedcolors={"\e[101m","\e[48;5;208m","\e[103m","\e[102m","\e[48;5;49m","\e[106m","\e[104m","\e[105m","\e[48;5;128m","\e[100m"};
	reset="\e[0m";
	framestring="";
	//selY=-1;
	//selX=-1;
	in.open("libs/txt/settings.txt",ios::in);
	for(int i=0;i<6;i++)
		options[i]=(int)in.get()-'0';
	in.close();
}
/*void SettingsFrame::change(int val, int newint)
{
	options[val]=newint;
}*/
void SettingsFrame::save()
{
	//SAVE Current game
}
Frame * SettingsFrame::select()
{
	return this;
}
Frame * SettingsFrame::esc()
{
	//Frame::delBuffer();
	//cout<<"Reached this";
	return this;
}
/*
 * Menu Structure: 
 * SETTINGS
 * choose AI difficulty (x) move with left right arrows
 * choose player 1 color [Red, Orange, Yellow, Green, Aquamarine, Cyan, Blue, Magenta, Purple, Gray]
 * choose player 2 color [Red, Orange, Yellow, Green, Aquamarine, Cyan, Blue, Magenta, Purple, Gray]
 * choose frame color [Red, Orange, Yellow, Green, Aquamarine, Cyan, Blue, Magenta, Purple, Gray]
 * choose selected color [Red, Orange, Yellow, Green, Aquamarine, Cyan, Blue, Magenta, Purple, Gray]
 * choose winner color [Red, Orange, Yellow, Green, Aquamarine, Cyan, Blue, Magenta, Purple, Gray]
 */
void SettingsFrame::updateFrame()
{
	string title;
	if(cols>=70)
	{
		title="\n"+
		center("\e[48;5;82;30m                                                                      \e[0m\n",70)+
		center("\e[48;5;46;30m   #####   #######  #######  #######  ###  #     #   #####    #####   \e[0m\n",70)+
		center("\e[48;5;47;30m  #     #  #           #        #      #   ##    #  #     #  #     #  \e[0m\n",70)+
		center("\e[48;5;48;30m  #        #           #        #      #   # #   #  #        #        \e[0m\n",70)+
		center("\e[48;5;49;30m   #####   #####       #        #      #   #  #  #  #  ####   #####   \e[0m\n",70)+
		center("\e[48;5;50;30m        #  #           #        #      #   #   # #  #     #        #  \e[0m\n",70)+
		center("\e[48;5;51;30m  #     #  #           #        #      #   #    ##  #     #  #     #  \e[0m\n",70)+
		center("\e[48;5;87;30m   #####   #######     #        #     ###  #     #   #####    #####   \e[0m\n",70)+
		center("\e[48;5;123;30m                                                                      \e[0m\n",70);

	}
	else if(cols>=40)
	{
		title="\n"+
		center("\e[48;5;46;30m  ____       _   _   _                  \e[0m\n",40)+
		center("\e[48;5;47;30m / ___|  ___| |_| |_(_)_ __   __ _ ___  \e[0m\n",40)+
		center("\e[48;5;48;30m \\___ \\ / _ \\ __| __| | '_ \\ / _` / __| \e[0m\n",40)+
		center("\e[48;5;49;30m  ___) |  __/ |_| |_| | | | | (_| \\__ \\ \e[0m\n",40)+
		center("\e[48;5;50;30m |____/ \\___|\\__|\\__|_|_| |_|\\__, |___/ \e[0m\n",40)+
		center("\e[48;5;51;30m                             |___/      \e[0m\n",40);
	}
	else if(cols>=20)
	{
		title="\n"+
		center("\e[48;5;46;30m __                 \e[0m\n",20)+
		center("\e[48;5;48;30m(_  __|__|_o._  _  _\e[0m\n",20)+
		center("\e[48;5;49;30m__)(/_|_ |_|| |(_|_>\e[0m\n",20)+
		center("\e[48;5;51;30m                _|  \e[0m\n",20);
	}
	else
	{
		title="\n"+
		center("\e[48;5;46;30m            \e[0m\n",12)+
		center("\e[48;5;48;30m  Settings  \e[0m\n",12)+
		center("\e[48;5;51;30m            \e[0m\n",12);
	}
	int height=(rows-21)/6;
	int width=(cols*2/3)/10;
	string ssel="\e[30;5m";
	string nsel="\e[97m";
	string aidiff="AI DIFFICULTY";
	aidiff=center("\e[97m"+aidiff+"\e[0m\n",aidiff.length());
	string aicolors[]={"\e[48;5;51m","\e[48;5;49m","\e[48;5;46m","\e[48;5;154m","\e[48;5;226m","\e[48;5;220m","\e[48;5;214m","\e[48;5;208m","\e[48;5;202m","\e[48;5;196m"};
	for(int i=0;i<height;i++)
	{
		string line="";
		for(int j=0;j<10;j++)
		{
			for(int k=0;k<width;k++)
			{
				line+=aicolors[j];
				if(sel.second==0) line+=ssel;
				else line+=nsel;
				if(sel.second==0&&sel.first==j) line+="▒";
				else if(options[0]==j&&sel.second!=0) line+="▒";
				else line+=" ";
				line+="\e[0m";
			}
		}
		aidiff+=center(line,width*10)+"\n";
	}
	string colormenu="";
	string menutitle[]={"PLAYER ONE'S COLOR","PLAYER TWO'S COLOR","BOARD COLOR","COLUMN SELECTED COLOR","WINNER COLOR"};
	for(int a=1;a<6;a++)
	{
		colormenu+=center("\e[97m"+menutitle[a-1]+"\e[0m\n",menutitle[a-1].length());
		for(int i=0;i<height;i++)
		{
			string line;
			for(int j=0;j<10;j++)
			{
				for(int k=0;k<width;k++)
				{
					line+=indexedcolors[j];
					if(sel.second==a) line+=ssel;
					else line+=nsel;
					if(sel.second==a&&sel.first==j) line+="▒";
					else if(options[a]==j&&sel.second!=a) line+="▒";
					else line+=" ";
					line+="\e[0m";
				}
			}
			colormenu+=center(line,width*10)+"\n";
		}
		colormenu+="\n";
	}
	framestring=title+aidiff+colormenu;
}
void SettingsFrame::printFrame()
{
	updateFrame();
	this->clear();
	cout<<framestring;
}
BoardFrame * SettingsFrame::getDefaultBoardFrame()
{
	vector<string> indexedColors={"\e[101m","\e[48;5;208m","\e[103m","\e[102m","\e[48;5;49m","\e[106m","\e[104m","\e[105m","\e[48;5;128m","\e[100m"};
	vector<int> v;
	v.resize(6);
	ifstream intemp;
	intemp.open("libs/txt/settings.txt",ios::in);
	for(int i=0;i<6;i++)
		v[i]=(int)intemp.get()-'0';
	intemp.close();
	Board b;
	BoardFrame *bf = new BoardFrame(
			indexedColors[v[1]],
			indexedColors[v[2]],
			indexedColors[v[3]],
			indexedColors[v[4]],
			indexedColors[v[5]],
			b, false, 1 );
	return bf;
			
}
BoardFrame * SettingsFrame::getDefaultBoardFrameAI()
{
	vector<string> indexedColors={"\e[101m","\e[48;5;208m","\e[103m","\e[102m","\e[48;5;49m","\e[106m","\e[104m","\e[105m","\e[48;5;128m","\e[100m"};
	vector<int> v;
	v.resize(6);
	ifstream intemp;
	intemp.open("libs/txt/settings.txt",ios::in);
	for(int i=0;i<6;i++)
		v[i]=(int)intemp.get()-'0';
	intemp.close();
	Board b;
	BoardFrame *bf = new BoardFrame(
			indexedColors[v[1]],
			indexedColors[v[2]],
			indexedColors[v[3]],
			indexedColors[v[4]],
			indexedColors[v[5]],
			b, true, 1 );
	return bf;
}
