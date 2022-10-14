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
#include "SavedFrame.h"
#include "SettingsFrame.h"
#include "StartFrame.h"
using namespace std;
SavedFrame::SavedFrame()
{
	xSize=2;
	ySize=8;
	framestring="";
	active.resize(8);
	for(int i=0;i<8;i++)
	{
		in.open("libs/txt/"+to_string(i)+".txt",ios::in);
		active[i]=((int)(in.get()-'0'));
		in.close();
	}
}
Frame * SavedFrame::select()
{
	if(sel.second==1)
	{
		active[sel.first]=0;
		out.open("libs/txt/"+to_string(sel.first)+".txt",ios::trunc);
		out<<'0';
		out.close();
	}
	else if(sel.second==0)
	{
		active[sel.first]=1;
		out.open("libs/txt/"+to_string(sel.first)+".txt",ios::trunc);
		out.close();
		in.open("libs/txt/curr.txt",ios::binary);
		out.open("libs/txt/"+to_string(sel.first)+".txt",ios::binary);
		out<<in.rdbuf();
		in.close();
		out.close();
	}
	return this;
}
Frame * SavedFrame::esc()
{
	Frame *stf=new StartFrame();
	return stf;
}
void SavedFrame::updateFrame()
{
	string title;
	int titleh=0;
	if(cols>=47)
	{
		titleh=9;
		title="\n"+
		center("\e[48;5;82;30m                                               \e[0m\n",47)+
		center("\e[48;5;46;30m   #####      #     #     #  #######  ######   \e[0m\n",47)+
		center("\e[48;5;47;30m  #     #    # #    #     #  #        #     #  \e[0m\n",47)+
		center("\e[48;5;48;30m  #         #   #   #     #  #        #     #  \e[0m\n",47)+
		center("\e[48;5;49;30m   #####   #     #  #     #  #####    #     #  \e[0m\n",47)+
		center("\e[48;5;50;30m        #  #######   #   #   #        #     #  \e[0m\n",47)+
		center("\e[48;5;51;30m  #     #  #     #    # #    #        #     #  \e[0m\n",47)+
		center("\e[48;5;87;30m   #####   #     #     #     #######  ######   \e[0m\n",47)+
		center("\e[48;5;123;30m                                               \e[0m\n",47);
	}
	else if(cols>=33)
	{
		titleh=6;
		title="\n"+
		center("\e[48;5;46;30m   ____                      _   \e[0m\n",33)+
		center("\e[48;5;47;30m  / ___|  __ ___   _____  __| |  \e[0m\n",33)+
		center("\e[48;5;48;30m  \\___ \\ / _` \\ \\ / / _ \\/ _` |  \e[0m\n",33)+
		center("\e[48;5;49;30m   ___) | (_| |\\ V /  __/ (_| |  \e[0m\n",33)+
		center("\e[48;5;50;30m  |____/ \\__,_| \\_/ \\___|\\__,_|  \e[0m\n",33)+
		center("\e[48;5;51;30m                                 \e[0m\n",33);
	}
	else if(cols>=17)
	{
		titleh=4;
		title="\n"+
		center("\e[48;5;46;30m  __             \e[0m\n",17)+
		center("\e[48;5;48;30m (_  _.   _  _|  \e[0m\n",17)+
		center("\e[48;5;49;30m __)(_|\\/(/_(_|  \e[0m\n",17)+
		center("\e[48;5;51;30m                 \e[0m\n",17);
	}
	else
	{
		titleh=3;
		title="\n"+
		center("\e[48;5;46;30m         \e[0m\n",9)+
		center("\e[48;5;48;30m  Saved  \e[0m\n",9)+
		center("\e[48;5;51;30m         \e[0m\n",9);
	}
	int height=(rows-titleh-8)/2;
	int width=(cols*4/5)/8;
	string ssel="\e[30;102;5;4;53m";
	string nsel="\e[97;42m";
	string serr="\e[30;5;9;101m";
	string nerr="\e[48;5;124;97m";
	string menu="";
	string cen="";
	for(int i=0;i<height;i++)
		menu+="\n";
	for(int i=0;i<width/2;i++)
		cen+=" ";
	menu+=center("\e[107;30m Save Current Game \e[0m",19);
	menu+="\n";
	menu+="\n";
	menu+=center("",width*8);
	for(int i=0;i<8;i++)
	{
		if(sel.second==0&&sel.first==i)
			if(active[i]==1)
				menu+=serr;
			else
				menu+=ssel;
		else
			if(active[i]==1)
				menu+=nerr;
			else
				menu+=nsel;
		menu+=cen;
		menu+=to_string(i+1);
		menu+=cen+"\e[0m";
	}
	menu+="\n";
	menu+="\n";
	menu+=center("\e[107;30m Delete Saved Game \e[0m",19);
	menu+="\n";
	menu+="\n";
	menu+=center("",width*8);
	for(int i=0;i<8;i++)
	{
		if(sel.second==1&&sel.first==i)
			if(active[i]==0)
				menu+=serr;
			else
				menu+=ssel;
		else
			if(active[i]==0)
				menu+=nerr;
			else
				menu+=nsel;
		menu+=cen;
		menu+=to_string(i+1);
		menu+=cen+"\e[0m";
	}
	menu+="\n";
	framestring=title+menu+"\n";
}
void SavedFrame::printFrame()
{
	updateFrame();
	this->clear();
	cout<<framestring;
}
